#include "DrawHandler.h"

DrawHandler::DrawHandler(Library*myLibrary)
{
	this->myLibrary = myLibrary; //denna pekar nu på samma Library som 
	//skapas i GameLogic! Skall absolut inte allokeras i nytt minne, för vi vill bara ha ett library
	this->myObjects = new ArrayList<Object>(20);
	this->myDrawEvents = new ArrayList<Event>(20);
}

DrawHandler::~DrawHandler()
{
	delete this->myObjects;
	delete this->myDrawEvents; 
}

void DrawHandler::tick()
{
	Event*currentEvent;
	for (int a = 0; a < this->myDrawEvents->getSize(); a++)
	{
		currentEvent = this->myDrawEvents->getData(a);
		if (currentEvent->getAction() == "addObjectByID")
		{

			Object*addObject = this->myLibrary->getObject(currentEvent->getDataNum());
			this->addObject(addObject);
			//kommentera ut det under
			//string category = this->myLibrary->find(currentEvent->getDataNum());
			//if (category == "player")
			//{
			//	DynamicObject*theObject = this->myLibrary->getPlayer(currentEvent->getDataNum());
			//	this->addDynamicObject(theObject);
			//}
				
			//this->addEvent(Library.getobject(event.getDataNum()))  event contains the ID in dataNum
		}
		this->myDrawEvents->remove(currentEvent);
		//currentEvent.clearAll();
	}
	currentEvent = nullptr;
}

void DrawHandler::addEvent(Event*myEvent)
{
	this->myDrawEvents->add(myEvent);
}

void DrawHandler::draw(sf::RenderWindow & window)
{
	Object*theObject;
	DynamicObject*theDynamicObject;
	for (int i = 0; i < this->myObjects->getSize(); i++)
	{
		theObject = this->myObjects->getData(i);
		theObject->update();
		theObject->draw(window);
	}
	//for (int i = 0; i < this->myDynamicObjects->getSize(); i++)
	//{
	//	theDynamicObject = this->myDynamicObjects->getData(i);
	//	theDynamicObject->update();
	//	theDynamicObject->draw(window);
	//}
}

bool DrawHandler::addObject(Object *object)
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

bool DrawHandler::removeObject(Object *object)
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

bool DrawHandler::addDynamicObject(DynamicObject *object)
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

bool DrawHandler::removeDynamicObject(DynamicObject *object)
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