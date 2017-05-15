#include "DynamicObject.h"

DynamicObject::DynamicObject()
{
}

DynamicObject::DynamicObject(float switchFrame, float frameSpeed, std::string textureName, int id, string name)
	: Object(textureName, id, name)
{
	this->mySwitchFrame = switchFrame;
	this->myFrameSpeed = frameSpeed;
	//this->myDirection = 0;
	this->myFrameCounter = 0;
	this->myUpdateSpriteCounter = 0;
}

bool DynamicObject::operator==(const DynamicObject & other)
{
	return this->getID() == other.getID();
}

void DynamicObject::updateSpriteSheet(int counterX, int counterY, int dirX, int dirY)
{
	//rektangeln flyttas och spriten följer automatiskt med rektangeln
	this->moveRectangleShape(dirX, dirY);
	
	//kontrollerar ifall det är okej att byta bild i spritesheet
	this->myFrameCounter= this->myFrameCounter += this->myFrameSpeed* this->myClock.restart().asSeconds();
	if (this->myFrameCounter >= this->mySwitchFrame)
	{
		this->myFrameCounter = 0; 
		this->updateSprite(counterX, counterY);
	}
}

float DynamicObject::getFrameCounter() const
{
	return this->myFrameCounter;
}

float DynamicObject::getFrameSpeed() const
{
	return this->myFrameSpeed;
}

float DynamicObject::getSwitchFrame() const
{
	return this->mySwitchFrame;
}

void DynamicObject::setFrameCounter(float frameCounter)
{
	this->myFrameCounter = frameCounter; 
}

