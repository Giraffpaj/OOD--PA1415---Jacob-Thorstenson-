#include "ButtonListener.h"

Event* ButtonListener::checkPressedButtons()
{
	Event*myEvent = nullptr;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myEvent =  new Event("W", -1, "MovementHandler", "moveUp");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myEvent = new Event("D", -1, "MovementHandler", "moveRight");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myEvent = new Event("S", -1, "MovementHandler", "moveDown");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myEvent = new Event("A", -1, "MovementHandler", "moveLeft");
	}
	if (myEvent == nullptr)
	{
		myEvent = new Event();
	}
	return myEvent;
}

void ButtonListener::clearAll()
{

}

void ButtonListener::deepCopy(const ButtonListener & other)
{

}

ButtonListener::ButtonListener()
{
}

ButtonListener::ButtonListener(const ButtonListener & other)
{
	this->deepCopy(other);
}

ButtonListener & ButtonListener::operator=(const ButtonListener & other)
{
	if (this != &other)
	{
		this->clearAll();
		this->deepCopy(other);
	}
	return *this;
}

void ButtonListener::tick()
{
	this->checkPressedButtons();
}

ButtonListener::~ButtonListener()
{
	delete this->checkPressedButtons(); 
}
