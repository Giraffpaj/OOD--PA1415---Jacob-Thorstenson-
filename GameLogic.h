#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "ButtonListener.h"  //kommentera ut denna och allt blir rätt
#include "MovementHandler.h"
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Event.h"
#include "ArrayList.h"
#include "DrawHandler.h"
#include "Library.h"

using namespace std;

class GameLogic
{
private:

	MovementHandler *myMovementHandler;
	string myMainState;
	string mySubState;
	ArrayList<Event>*myEvents;
	DrawHandler*myDrawHandler;
	Library*myLibrary;
	//ItemHandler;
	//MapHandler;
	//ButtonHandler;
	//DrawHandler;
	ButtonListener*myButtonListener;
public:
	GameLogic();
	~GameLogic() { /*Empty for now*/ };
	void addEvent(Event myEvent);
	void tick(sf::RenderWindow &myRenderWindow);
};
#endif // !GAMELOGIC_H
