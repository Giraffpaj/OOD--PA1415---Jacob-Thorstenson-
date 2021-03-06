#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->myEvents = new ArrayList<Event>(20);
	this->myButtonListener = new ButtonListener(this);
	this->myMovementHandler = new MovementHandler(this);
}

void GameLogic::addEvent(Event myEvent)
{
	this->myEvents->add(myEvent);
}

void GameLogic::tick()
{
	Event currentEvent;
	for(int a = 0;a<this->myEvents->getSize();a++)
	{
		currentEvent = this->myEvents->getData(a);

		if (this->myMainState == "INGAME")
		{
			if (currentEvent.getHandler == "CombatHandler")
			{
				//skicka event till CombatHandler
			}
			if (currentEvent.getHandler == "ItemHandler")
			{
				//skicka event tillItemHandler
			}
		}
		if (currentEvent.getHandler == "MovementHandler")
		{
			this->myMovementHandler->addEvent(currentEvent);
		}
		if (currentEvent.getHandler == "MapHandler")
		{
			//skicka event till MapHandler
		}
		this->myEvents->remove(currentEvent);  //Tar bort event fr�n listan
	}
}
