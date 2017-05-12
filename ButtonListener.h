#ifndef BUTTONLISTENER_H
#define BUTTONLISTENER_H
using namespace std;
#include "Event.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class ButtonListener
{
private:
	
	void clearAll();
	void deepCopy(const ButtonListener & other);
public:
	ButtonListener();
	Event checkPressedButtons();
	ButtonListener(const ButtonListener & other);
	ButtonListener& operator=(const ButtonListener & other);
	~ButtonListener();
	void tick();
	Event createEvent(string button, string handler, string action);
};
#endif // !BUTTONLISTENER_H
