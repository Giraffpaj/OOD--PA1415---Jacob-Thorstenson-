#ifndef MOVEMENTHANDLER_H
#define MOVEMENTHANDLER_H
#include "GameLogic.h"


class MovementHandler 
{

private:
	GameLogic*myGameLogic;
	ArrayList<Event>*myMoveEvents;

	//Skall flyttas till Objekt
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	sf::RectangleShape playerRect;
	int counterWalking = 0; //<--- Dynamic Objekt, till objekt
	int direction = 0; //1 - up, 2 - down, 3 - left, 4 right   ----||----
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	//inte helt hundra p� vart klockan b�r vara
	sf::Clock clock;
	//sf::Event event;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;
	

	int movementLength = 0;


public:

	MovementHandler(int _startingPositionX, int _startingPositionY);
	MovementHandler(GameLogic*myGameLogic);
	void addEvent(Event myEvent);
	void tick();
	void update();
	void updateMovement();
	void updateMovement2();
	void combat();
	sf::Sprite getPlayerSprite() const;

};



#endif // !MOVEMENTHANDLER_H

