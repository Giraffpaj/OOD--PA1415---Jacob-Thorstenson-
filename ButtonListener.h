#ifndef BUTTONLISTENER_H
#define BUTTONLISTENER_H
#include "GameLogic.h"



class ButtonListener
{
private:
	GameLogic*myGameLogic;
	void checkPressedButtons();
	void clearAll();
	void deepCopy(const ButtonListener & other);
public:
	ButtonListener(GameLogic*myGameLogic);
	ButtonListener(const ButtonListener & other);
	ButtonListener& operator=(const ButtonListener & other);
	~ButtonListener();
	void tick();
	Event createEvent(string button, string handler, string action);
};
#endif // !BUTTONLISTENER_H
