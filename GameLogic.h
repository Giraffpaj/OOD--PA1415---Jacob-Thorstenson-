#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Event.h"
#include "ArrayList.h"
#include "ButtonListener.h"  //kommentera ut denna och allt blir r�tt
#include "MovementHandler.h"

using namespace std;

class GameLogic
{
private:
	string myMainState;
	string mySubState;
	ArrayList<Event>*myEvents;
	MovementHandler*myMovementHandler;
	//ItemHandler;
	//MapHandler;
	//ButtonHandler;
	//DrawHandler;
	ButtonListener*myButtonListener;
public:
	GameLogic();
	~GameLogic() { /*Empty for now*/ };
	void addEvent(Event myEvent);
	void tick();
};
#endif // !GAMELOGIC_H
