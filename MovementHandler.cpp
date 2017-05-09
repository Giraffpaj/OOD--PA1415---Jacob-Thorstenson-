#include "MovementHandler.h"

MovementHandler::MovementHandler(int _startingPositionX, int _startingPositionY)
{
}

MovementHandler::MovementHandler(GameLogic*myGameLogic)
{
	this->myMoveEvents = new ArrayList<Event>(20);
	this->myGameLogic = myGameLogic;
	//load Texture
	if (!this->playerTexture.loadFromFile("spritesheet.png"))
	{
		EXIT_FAILURE; 
	}
	//set sprite
	this->playerSprite.setTexture(this->playerTexture); 
	
	//set hitbox to same size as sprite
	this->playerRect.setSize(sf::Vector2f(32, 32)); 


	this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 0, 32, 32));

	

}

void MovementHandler::addEvent(Event myEvent)
{
	this->myMoveEvents->add(myEvent);
}

void MovementHandler::tick()
{
	Event currentEvent;
	for (int a = 0; a < this->myMoveEvents->getSize; a++)
	{
		currentEvent = this->myMoveEvents->getData(a);
		if (currentEvent.getAction == "moveUp")
		{
			//Player går uppåt
		}
		if (currentEvent.getAction == "moveRight")
		{
			//Player går Höger
		}
		if (currentEvent.getAction == "moveDown")
		{
			//Player går ner
		}
		if (currentEvent.getAction == "moveLeft")
		{
			//Player går vänster
		}
		this->myMoveEvents->remove(currentEvent);
		currentEvent.clearAll();
	}
}

void MovementHandler::update()
{
	//sprite follows hitbox
	playerSprite.setPosition(this->playerRect.getPosition()); 
}

void MovementHandler::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (this->canMoveUp == true)
		{
			this->playerRect.move(0, -1); 
			this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 32* 3, 32, 32)); 
			this->direction = 1; 

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (this->canMoveDown == true)
		{
			this->playerRect.move(0, 1);
			this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 0, 32, 32));
			this->direction = 2;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (this->canMoveLeft == true)
		{
			this->playerRect.move(-1, 0);
			this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 32 * 1, 32, 32));
			this->direction = 3;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (this->canMoveRight == true)
		{
			this->playerRect.move(1,0);
			this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 32 * 2, 32, 32));
			this->direction = 4;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	
	this->frameCounter += this->frameSpeed* this->clock.restart().asSeconds(); 
	if (this->frameCounter >= this->switchFrame)
	{
		this->frameCounter = 0; 
		//updates sprite sheet
		this->counterWalking++;
		//resets sprite sheet
		if (this->counterWalking == 2)
		{
			this->counterWalking = 0;
		}
	}
	


	
}

void MovementHandler::updateMovement2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->movementLength == 0)
	{
		if (this->canMoveUp == true)
		{
			while (this->movementLength != 32)
			{
				this->playerRect.move(0, -1);
				this->movementLength++;
				this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 32 * 3, 32, 32));
			}
			this->direction = 1;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->movementLength == 0)
	{
		if (this->canMoveDown == true)
		{
			while (this->movementLength != 32)
			{
				this->playerRect.move(0, 1);
				this->movementLength++;
				this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 0, 32, 32));
			}
			this->direction = 2;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->movementLength == 0)
	{
		if (this->canMoveLeft == true)
		{
			while (this->movementLength != 32)
			{
				this->playerRect.move(-1, 0);
				this->movementLength++;
				this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 32 * 1, 32, 32));
			}
			this->direction = 3;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->movementLength == 0)
	{
		if (this->canMoveRight == true)
		{
			while (this->movementLength != 32)
			{
				this->playerRect.move(1, 0);
				this->movementLength++;
				this->playerSprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 32 * 2, 32, 32));
			}
			this->direction = 4;

			this->canMoveUp = true;
			this->canMoveDown = true;
			this->canMoveLeft = true;
			this->canMoveRight = true;
		}
	}

	this->frameCounter += this->frameSpeed* this->clock.restart().asSeconds();
	if (this->frameCounter >= this->switchFrame)
	{
		this->frameCounter = 0;
		//updates sprite sheet
		this->counterWalking++;
		//resets sprite sheet
		if (this->counterWalking == 2)
		{
			this->counterWalking = 0;
		}
		//reset movementLength
		if (this->movementLength == 32)
		{
			this->movementLength = 0; 
		}
	}
}

void MovementHandler::combat()
{
	if (direction == 1 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
	{
		this->playerSprite.setTextureRect(sf::IntRect(0, 7 * 32, 32, 32));
	}
	if (direction == 2 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
	{
		this->playerSprite.setTextureRect(sf::IntRect(0, 4 * 32, 32, 32));
	}
	if (direction == 3 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
	{
		this->playerSprite.setTextureRect(sf::IntRect(0, 5 * 32, 32, 32));
	}
	if (direction == 4 && sf::Keyboard().isKeyPressed(sf::Keyboard::Space))
	{
		this->playerSprite.setTextureRect(sf::IntRect(0, 6 * 32, 32, 32));
	}

}




sf::Sprite MovementHandler::getPlayerSprite() const
{
	return this->playerSprite;
}
