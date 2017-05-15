#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->myLibrary = new Library();  //Denna m�ste skapas f�rst f�r den skall skickas till de flesta handlers!
	this->myEvents = new ArrayList<Event>(20);
	this->myButtonListener = new ButtonListener();
	this->myMovementHandler = new MovementHandler(this->myLibrary);
	this->myDrawHandler = new DrawHandler(this->myLibrary);
	this->myMapGenerator = new MapGenerator(50, 28, this->myDrawHandler, this->myLibrary);
	this->myMapGenerator->createMapDesign();
	this->myMapGenerator->createExitTile();
	this->myMapGenerator->drawMap();
	
	//Ful-l�sning
	string*dataTxt = nullptr;
	int id = 1;
	string handler = "DrawHandler";
	string action = "addObjectByID";
	Event*addPlayer = new Event("?", id, handler, action);
	this->myEvents->add(addPlayer);
	//slut p� Ful-l�sning
}

void GameLogic::addEvent(Event*myEvent)
{
	this->myEvents->add(myEvent);
}

void GameLogic::tick(sf::RenderWindow &myRenderWindow)
{
	Event*currentEvent;
	this->addEvent(this->myButtonListener->checkPressedButtons());
	for(int a = 0;a<this->myEvents->getSize()+1;a++) //l�gger till +1 f�r att det finns ett extra event som ligger �ver fr�n initierings process
	{
		currentEvent = this->myEvents->getData(a);

		if (this->myMainState == "INGAME")
		{
			if (currentEvent->getHandler() == "CombatHandler")
			{
				//skicka event till CombatHandler
			}
			if (currentEvent->getHandler() == "ItemHandler")
			{
				//skicka event tillItemHandler
			}
		}
		if (currentEvent->getHandler() == "MovementHandler")
		{
			this->myMovementHandler->addEvent(currentEvent);
		}
		if (currentEvent->getHandler() == "MapHandler")
		{
			//skicka event till MapHandler
		}
		if (currentEvent->getHandler() == "DrawHandler")
		{
			this->myDrawHandler->addEvent(currentEvent);
			//skicka event till MapHandler
		}
		this->myEvents->remove(currentEvent);  //Tar bort event fr�n listan
	}
	this->myMovementHandler->tick();
	this->myDrawHandler->tick();
	this->myDrawHandler->draw(myRenderWindow); //kan �ven l�ggas in i slutet p� tick i DrawHandler
}
