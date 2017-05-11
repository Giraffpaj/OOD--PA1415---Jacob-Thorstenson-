#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "GameLogic.h"
#include "Object.h"
class DynamicObject : Object
{
private:
	int myUpdateSpriteCounter,
		myDirection;
	float myFrameCounter,
		mySwitchFrame,
		myFrameSpeed;
public:
	DynamicObject(float switchFrame, float frameSpeed, std::string textureName, int id, string name);
	void update();
};

#endif //DYAMICOBJECT_H