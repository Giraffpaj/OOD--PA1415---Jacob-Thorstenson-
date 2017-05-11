#ifndef OBJECT_H
#define OBJECT_H
#include "GameLogic.h"

class Object
{
private:
	sf::Sprite mySprite;
	sf::Texture myTexture;
	sf::RectangleShape myRectangleShape;
	int ID;
	string name;
public:
	Object(string textureName, int id, string name);
	~Object() {};
	int getID()const;
	string getName()const;
	sf::Sprite getSprite()const;
	void setSprite(sf::Sprite mySprite);
	sf::RectangleShape getRectangleShape()const;
	void setRectangleShape(sf::RectangleShape myRectangleShape);
	void draw(sf::RenderWindow myRenderWindow);
};
#endif // !OBJECT_H

#include "GameLogic.h"
