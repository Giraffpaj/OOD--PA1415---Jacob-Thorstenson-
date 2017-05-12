#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace std;

class Object
{
private:
	sf::Sprite mySprite;
	sf::Texture myTexture;
	sf::RectangleShape myRectangleShape;
	int ID;
	string name;
public:
	Object(string textureName = "noImage", int id = -1, string name = "noName");
	~Object() {};
	bool operator==(const Object&other);
	int getID()const;
	string getName()const;
	sf::Sprite getSprite()const;
	void setSprite(sf::Sprite mySprite);
	sf::RectangleShape getRectangleShape()const;
	void setRectangleShape(sf::RectangleShape myRectangleShape);
	void draw(sf::RenderWindow &myRenderWindow);
};
#endif // !OBJECT_H
