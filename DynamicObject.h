#pragma once
#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "Object.h"
using namespace std;
class DynamicObject : public Object
{
private:
	int myUpdateSpriteCounter;
	float myFrameCounter;
	float mySwitchFrame;
	float myFrameSpeed;
public:
	DynamicObject();
	DynamicObject(float switchFrame, float frameSpeed, std::string textureName, int id, string name);
	bool operator==(const DynamicObject & other);
	virtual void update();
	void updateSpriteSheet(int counterX, int counterY, int dirX, int dirY);
	float getFrameCounter() const; 
	float getFrameSpeed() const; 
	float getSwitchFrame() const; 
	void setFrameCounter(float frameCounter); 

};

#endif //DYAMICOBJECT_H