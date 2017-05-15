#include "MovementHandler.h"

MovementHandler::MovementHandler(Library*myLibrary)
{
	this->myLibrary = myLibrary;
	this->myMoveEvents = new ArrayList<Event>(20);
	this->canMove = true; 

	

}

MovementHandler::~MovementHandler()
{
	delete this->myMoveEvents;
}

void MovementHandler::addEvent(Event*myEvent)
{
	this->myMoveEvents->add(myEvent);
}

void MovementHandler::tick()
{
	int k = 32;
	Event*currentEvent;
	Object*player = this->myLibrary->getObject(1);
	Player*thePlayer = static_cast<Player*>(player);
	sf::Vector2i pos = thePlayer->getMapPos();
	if (thePlayer == nullptr)
	{
		//det funka inte
	}
	for (int a = 0; a < this->myMoveEvents->getSize(); a++)
	{
		currentEvent = this->myMoveEvents->getData(a);
		if (currentEvent->getAction() == "moveUp" && this->playerClock.getElapsedTime().asMilliseconds() > 200)
		{
			if (this->myLibrary->getMapID("design", pos.x, pos.y - 1) != 10)
			{
				thePlayer->updateSpriteSheet(this->counterWalking, 3, 0, -1*k);
				thePlayer->setMapPos(pos.x, pos.y - 1);
				this->playerClock.restart(); 
			
			}
			//Player går Upp
		}
		if (currentEvent->getAction() == "moveRight"&& this->playerClock.getElapsedTime().asMilliseconds() > 200)
		{
			if (this->myLibrary->getMapID("design", pos.x+1, pos.y) != 10)
			{
				thePlayer->updateSpriteSheet(this->counterWalking, 2, 1*k, 0);
				thePlayer->setMapPos(pos.x+1, pos.y);
				this->playerClock.restart();

			}
			//Player går Höger
		}
		if (currentEvent->getAction() == "moveDown"&& this->playerClock.getElapsedTime().asMilliseconds() > 200)
		{
			if (this->myLibrary->getMapID("design", pos.x, pos.y+1) != 10)
			{
				thePlayer->updateSpriteSheet(this->counterWalking, 0, 0, 1*k);
				thePlayer->setMapPos(pos.x, pos.y+1);
				this->playerClock.restart();
			}
			//Player går ner
		}
		if (currentEvent->getAction() == "moveLeft"&& this->playerClock.getElapsedTime().asMilliseconds() > 200)
		{
			if (this->myLibrary->getMapID("design", pos.x-1, pos.y) != 10)
			{
				thePlayer->updateSpriteSheet(this->counterWalking, 1, -1*k, 0);
				thePlayer->setMapPos(pos.x-1, pos.y);
				this->playerClock.restart();
			}
			//Player går vänster
		}
		this->counterWalking++;
		if (this->counterWalking == 2)
		{
			this->counterWalking = 0;
		}
		this->myMoveEvents->remove(currentEvent);
	}
	pos = thePlayer->getMapPos();
	if (this->myLibrary->getMapID("design", pos.x, pos.y) == 2)
	{

	}

}

//void MovementHandler::combat()
//{
//	if (direction == 1 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
//	{
//		this->playerSprite.setTextureRect(sf::IntRect(0, 7 * 32, 32, 32));
//	}
//	if (direction == 2 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
//	{
//		this->playerSprite.setTextureRect(sf::IntRect(0, 4 * 32, 32, 32));
//	}
//	if (direction == 3 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
//	{
//		this->playerSprite.setTextureRect(sf::IntRect(0, 5 * 32, 32, 32));
//	}
//	if (direction == 4 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
//	{
//		this->playerSprite.setTextureRect(sf::IntRect(0, 6 * 32, 32, 32));
//	}
//
//}
