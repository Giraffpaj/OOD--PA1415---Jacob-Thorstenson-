#include "ButtonListener.h"

Event ButtonListener::checkPressedButtons()
{
	Event myEvent;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myEvent = createEvent("W", "MovementHandler", "moveUp");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myEvent = createEvent("D", "MovementHandler", "moveRight");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myEvent = createEvent("S", "MovementHandler", "moveDown");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myEvent = createEvent("A", "MovementHandler", "moveLeft");
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

Event ButtonListener::createEvent(string button, string handler, string action)
{
	string*myButton = new string(button);
	string*myHandler = new string(handler);
	string*myAction = new string(action);
	Event myEvent(myButton, nullptr, myHandler, myAction);
	return myEvent;
}

ButtonListener::~ButtonListener()
{

}
