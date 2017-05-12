#include "MovementHandler.h"

MovementHandler::MovementHandler(Library*myLibrary)
{
	this->myLibrary = myLibrary;
	this->myMoveEvents = new ArrayList<Event>(20);
	//load Texture
	//if (!this->playerTexture.loadFromFile("spritesheet.png"))
	//{
	//	EXIT_FAILURE; 
	//}
	////set sprite
	//this->playerSprite.setTexture(this->playerTexture); 
	//
	////set hitbox to same size as sprite
	//this->playerRect.setSize(sf::Vector2f(32, 32)); 


	//this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 0, 32, 32));

	

}

void MovementHandler::addEvent(Event myEvent)
{
	this->myMoveEvents->add(myEvent);
}

void MovementHandler::tick()
{
	Event currentEvent;
	for (int a = 0; a < this->myMoveEvents->getSize(); a++)
	{
		//kan ha problemet att thePlayer Raderar alla pekar värden i sig
		Player thePlayer = this->myLibrary->getPlayer(0);
		currentEvent = this->myMoveEvents->getData(a);
		if (currentEvent.getAction() == "moveUp")
		{
			thePlayer.updateSpriteSheet(this->counterWalking, 3, 0, -1);
		}
		if (currentEvent.getAction() == "moveRight")
		{
			//Player går Höger
			thePlayer.updateSpriteSheet(this->counterWalking, 2, 1, 0);
		}
		if (currentEvent.getAction() == "moveDown")
		{
			//Player går ner
			thePlayer.updateSpriteSheet(this->counterWalking,0, 0, 1);
		}
		if (currentEvent.getAction() == "moveLeft")
		{
			//Player går vänster
			thePlayer.updateSpriteSheet(this->counterWalking,1, -1, 0);
		}
		int theFrameCounter = thePlayer.getFrameCounter(); 
		thePlayer.setFrameCounter(theFrameCounter += thePlayer.getFrameSpeed() * this->clock.restart().asSeconds());
		if (thePlayer.getFrameCounter() >= thePlayer.getSwitchFrame())
		{
			thePlayer.setFrameCounter(0); 
			this->counterWalking++; 
			if (this->counterWalking == 2)
			{
				this->counterWalking = 0; 
			}
			if (this->movementLength == 32)
			{
				this->movementLength = 0; 
			}
		}
		this->myMoveEvents->remove(currentEvent);
		currentEvent.clearAll();
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
