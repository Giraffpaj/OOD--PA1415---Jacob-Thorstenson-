#include "Object.h"

Object::Object(string textureName, int id, string name)
{	//load Texture
	if (textureName != "noImage" && !this->myTexture.loadFromFile(textureName+".png"))
	{
		EXIT_FAILURE;
	}
	//set sprite
	this->mySprite.setTexture(this->myTexture);

	//set hitbox to same size as sprite
	this->myRectangleShape.setSize(sf::Vector2f(32, 32));
	this->myRectangleShape.setFillColor(sf::Color::Blue);


	//this->mySprite.setTextureRect(sf::IntRect(this->counterWalking * 32, 0, 32, 32));
	this->ID = id;
	this->name = name;
	this->mySprite.setTextureRect(sf::IntRect(32 * 0, 0, 32, 32));
}

bool Object::operator==(const Object & other)
{
	return this->ID == other.ID;
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

void Object::setSpritePosition(int x, int y)
{
	sf::Vector2f pos(x, y);
	this->mySprite.setPosition(pos);
}

void Object::moveRectangleShape(int x, int y)
{
	this->myRectangleShape.move(x, y);
}

void Object::updateSprite(int counterX, int counterY)
{
	this->mySprite.setTextureRect(sf::IntRect(counterX * 32, 32 * counterY, 32, 32));
}

void Object::update()
{
	this->mySprite.setPosition(this->myRectangleShape.getPosition());
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

void Object::draw(sf::RenderWindow &myRenderWindow)
{
	myRenderWindow.draw(this->mySprite);
	//myRenderWindow.draw(this->myRectangleShape);
}