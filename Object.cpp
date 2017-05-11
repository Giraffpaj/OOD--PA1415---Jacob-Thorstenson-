#include "Object.h"

Object::Object(string textureName, int id, string name)
{	//load Texture
	if (!this->myTexture.loadFromFile(textureName+".png"))
	{
		EXIT_FAILURE;
	}
	//set sprite
	this->mySprite.setTexture(this->myTexture);

	//set hitbox to same size as sprite
	this->myRectangleShape.setSize(sf::Vector2f(32, 32));


	//this->mySprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 0, 32, 32));
	this->ID = id;
	this->name = name;
}

int Object::getID() const
{
	return this->ID;
}

string Object::getName() const
{
	return string();
}

sf::Sprite Object::getSprite()const
{
	return this->mySprite;
}

void Object::setSprite(sf::Sprite mySprite)
{
	this->mySprite = mySprite;
}

sf::RectangleShape Object::getRectangleShape() const
{
	return this->myRectangleShape;
}

void Object::setRectangleShape(sf::RectangleShape myRectangleShape)
{
	this->myRectangleShape = myRectangleShape;
}

void Object::draw(sf::RenderWindow myRenderWindow)
{
	myRenderWindow.draw(this->mySprite);
}