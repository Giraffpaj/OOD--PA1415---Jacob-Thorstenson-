#include "ButtonListener.h"

void ButtonListener::checkPressedButtons()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Event myEvent = createEvent("W", "MovementHandler", "moveUp");
		this->myGameLogic->addEvent(myEvent);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Event myEvent = createEvent("D", "MovementHandler", "moveRight");
		this->myGameLogic->addEvent(myEvent);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Event myEvent = createEvent("S", "MovementHandler", "moveDown");
		this->myGameLogic->addEvent(myEvent);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Event myEvent = createEvent("A", "MovementHandler", "moveLeft");
		this->myGameLogic->addEvent(myEvent);
	}
}

void ButtonListener::clearAll()
{
	if (this->myGameLogic != nullptr)
	{
		delete this->myGameLogic;
	}
}

void ButtonListener::deepCopy(const ButtonListener & other)
{
	if (other.myGameLogic != nullptr)
	{
		this->myGameLogic = new GameLogic(other.myGameLogic);
	}
}

ButtonListener::ButtonListener(GameLogic*myGameLogic)
{
	this->myGameLogic = myGameLogic;
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
	string*button = new string(button);
	string*handler = new string(handler);
	string*action = new string(action);

	
}

ButtonListener::~ButtonListener()
{
	if (this->myGameLogic != nullptr)
	{
		delete this->myGameLogic;
	}
}
