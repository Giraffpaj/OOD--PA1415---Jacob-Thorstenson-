#include "Player.h"

Player::Player(float switchFrame, float frameSpeed, std::string textureName, int id, string name)
	: DynamicObject(switchFrame, frameSpeed, textureName, id, name)
{
}

Player::~Player()
{
}

void Player::setMapPos(int x, int y)
{
	this->mapPos.x = x;
	this->mapPos.y = y;
}

sf::Vector2i Player::getMapPos() const
{
	return this->mapPos;
}
