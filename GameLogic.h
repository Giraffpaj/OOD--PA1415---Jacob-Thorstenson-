#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include<string>
using namespace std;

class GameLogic
{
private:
	string myMainState;
	string mySubState;
	//Events
	//movementHandler;
	//ItemHandler;
	//MapHandler;
	//ButtonHandler;
	//DrawHandler;
	//ButtonListener;
public:
	GameLogic();
	~GameLogic() { /*Empty for now*/ };
	addEvent(/*event*/);
	void tick();

};
#endif // !GAMELOGIC_H
