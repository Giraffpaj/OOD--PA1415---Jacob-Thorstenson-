#pragma once
#ifndef MOVEMENTHANDLER_H
#define MOVEMENTHANDLER_H
#include "DynamicObject.h"
#include "Event.h"
#include "ArrayList.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Library.h"


class MovementHandler 
{

private:
	Library*myLibrary;
	ArrayList<Event>*myMoveEvents;

	//Skall flyttas till Objekt
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	sf::RectangleShape playerRect;
	int counterWalking = 0; //<--- Dynamic Objekt, till objekt
	//int direction = 0; //1 - up, 2 - down, 3 - left, 4 right   ----||----
	//float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	//inte helt hundra på vart klockan bör vara
	sf::Clock clock;
	//sf::Event event;

	int counterPlayer; 
	sf::Clock playerClock; 
	bool canMove; 
	

	int movementLength = 0;


public:
	//float switchFrame, float frameSpeed, std::string textureName, int id, string name
	MovementHandler(Library*myLibrary);
	void addEvent(Event*myEvent);
	void tick();
	//void update();
	//void updateMovement();
	//void updateMovement2();
	//void combat();
	//sf::Sprite getPlayerSprite() const;

};



#endif // !MOVEMENTHANDLER_H

