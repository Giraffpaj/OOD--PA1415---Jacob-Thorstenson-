#include "DrawHandler.h"

DrawHandler::DrawHandler(Library*myLibrary)
{
	this->myLibrary = myLibrary; //denna pekar nu på samma Library som 
	//skapas i GameLogic! Skall absolut inte allokeras i nytt minne, för vi vill bara ha ett library
	this->myObjects = new ArrayList<Object>(20);
	this->myDynamicObjects = new ArrayList<DynamicObject>(20);
	this->myDrawEvents = new ArrayList<Event>(20);
}

DrawHandler::~DrawHandler()
{
	delete this->myObjects;
}

void DrawHandler::tick()
{
	Event currentEvent;
	for (int a = 0; a < this->myDrawEvents->getSize(); a++)
	{
		currentEvent = this->myDrawEvents->getData(a);
		if (currentEvent.getAction() == "addObjectByID")
		{
			string category = this->myLibrary->find(currentEvent.getDataNum());
			if (category == "player")
			{
				this->addDynamicObject(this->myLibrary->getPlayer(currentEvent.getDataNum()));
			}
				
			//this->addEvent(Library.getobject(event.getDataNum()))  event contains the ID in dataNum
		}
		this->myDrawEvents->remove(currentEvent);
		//currentEvent.clearAll();
	}
	currentEvent = nullptr;
}

void DrawHandler::addEvent(Event myEvent)
{
	this->myDrawEvents->add(myEvent);
}

void DrawHandler::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < this->myObjects->getSize(); i++)
	{
		this->myObjects->getData(i).draw(window);
	}
	for (int i = 0; i < this->myDynamicObjects->getSize(); i++)
	{
		this->myDynamicObjects->getData(i).draw(window);
	}
}

bool DrawHandler::addObject(Object object)
{
	int size = this->myObjects->getSize();
	bool added = false;
	this->myObjects->add(object);
	if (this->myObjects->getSize() > size)
	{
		added = true;
	}
	return added;
}

bool DrawHandler::removeObject(Object object)
{
	int size = this->myObjects->getSize();
	bool removed = false;
	this->myObjects->remove(object);
	if (this->myObjects->getSize() < size)
	{
		removed = true;
	}
	return removed;
}

bool DrawHandler::addDynamicObject(DynamicObject object)
{
	int size = this->myObjects->getSize();
	bool added = false;
	this->myDynamicObjects->add(object);
	if (this->myDynamicObjects->getSize() > size)
	{
		added = true;
	}
	return added;
}

bool DrawHandler::removeDynamicObject(DynamicObject object)
{
	int size = this->myDynamicObjects->getSize();
	bool removed = false;
	this->myDynamicObjects->remove(object);
	if (this->myDynamicObjects->getSize() < size)
	{
		removed = true;
	}
	return removed;
}

//void DrawHandler::updateSprite(Object object)
//{
//	for (int i = 0; i < this->objectList->getSize; i++)
//	{
//		this->objectList.getData(i). ? // ej klar; kanske sköts i movementHandler ist.
//	}
//}