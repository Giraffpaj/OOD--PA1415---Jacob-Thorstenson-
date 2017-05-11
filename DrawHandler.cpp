#include "DrawHandler.h"

DrawHandler::DrawHandler()
{
	
}

DrawHandler::~DrawHandler()
{

}

void DrawHandler::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < this->objectList.getSize(); i++)
	{
		this->objectList.getData(i).draw(window);
	}
}

bool DrawHandler::addObject(Object object)
{
	int size = this->objectList.getSize();
	bool added = false;
	this->objectList.add(object);
	if(this->objectList.getSize() > size)
	{
		added = true;
	}
	return added;
}

bool DrawHandler::removeObject(Object object)
{
	int size = this->objectList.getSize();
	bool removed = false;
	this->objectList.remove(object);
	if (this->objectList.getSize() < size)
	{
		removed = true;
	}
	return removed;
}

void DrawHandler::updateSprite(Object object)
{
	for (int i = 0; i < this->objectList.getSize; i++)
	{
		this->objectList.getData(i).? // ej klar; kanske sköts i movementHandler ist.
	}
}
