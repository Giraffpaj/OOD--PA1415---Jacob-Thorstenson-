#pragma once
#include "DynamicObject.h"

class Player : public DynamicObject
{
private:
	//inget m�ste f�r MVP
	//hp
	//equipment
	//stats
	//class
	//och dylikt
public:
	Player(float switchFrame, float frameSpeed, std::string textureName, int id, string name);
	~Player();
};