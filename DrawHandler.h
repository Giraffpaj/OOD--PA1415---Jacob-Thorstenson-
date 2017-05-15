#pragma once
#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H
#include "ArrayList.h"
#include "Object.h"
#include "Event.h"
#include "Library.h"

class DrawHandler
{
private:
	Library*myLibrary;
	ArrayList<Object>*myObjects;
	ArrayList<DynamicObject>*myDynamicObjects;
	ArrayList<Event>*myDrawEvents;
public:
	DrawHandler(Library*myLibrary);
	~DrawHandler();
	void tick();
	void addEvent(Event*myEvent);
	void draw(sf::RenderWindow & window);
	bool addObject(Object *object);
	bool removeObject(Object *object);
	bool addDynamicObject(DynamicObject *object);
	bool removeDynamicObject(DynamicObject *object);
	//void updateSprite(Object object);
};



#endif //DRAWHANDLER_H