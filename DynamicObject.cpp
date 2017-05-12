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

void DynamicObject::update()
{
	sf::Sprite theSprite = this->getSprite();
	theSprite.setPosition(this->getRectangleShape().getPosition());
	this->setSprite(theSprite);
}

void DynamicObject::updateSpriteSheet(int counterX, int counterY, int dirX, int dirY)
{
	sf::RectangleShape theRectangleShape = this->getRectangleShape();
	theRectangleShape.move(dirX, dirY);
	this->setRectangleShape(theRectangleShape);
	sf::Sprite theSprite = this->getSprite();
	theSprite.setTextureRect(sf::IntRect(counterX * 32, 32 * counterY, 32, 32));
	this->setSprite(theSprite);
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

