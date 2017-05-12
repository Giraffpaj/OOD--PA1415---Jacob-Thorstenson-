#include "Player.h"

Player::Player(float switchFrame, float frameSpeed, std::string textureName, int id, string name)
	: DynamicObject(switchFrame, frameSpeed, textureName, id, name)
{
}

Player::~Player()
{
}
