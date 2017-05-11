#include "DynamicObject.h"

DynamicObject::DynamicObject(float switchFrame, float frameSpeed, std::string textureName, int id, string name)
	: Object(textureName, id, name)
{
	this->mySwitchFrame = switchFrame;
	this->myFrameSpeed = frameSpeed;
	this->myDirection = 0;
	this->myFrameCounter = 0;
	this->myUpdateSpriteCounter = 0;
}

void DynamicObject::update()
{
	sf::Sprite theSprite = this->getSprite();
	theSprite.setPosition(this->getRectangleShape().getPosition());
	this->setSprite(theSprite);
}
