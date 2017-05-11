#include "Player.h"

Player::Player(string textureName, int id, string name, int mapXPos, int mapYPos, int playerID)
	:Object(textureName, id, name)
{
	this->mapXPos = mapXPos;
	this->mapYPos = mapYPos;
	this->playerID = playerID;
}

Player::~Player()
{

}

void Player::setPosition(int posX, int posY)
{

}

void Player::die()
{
	//Implement die
}

int Player::getHealth() const
{
	return this->health;
}

int Player::getXPos() const
{
	return this->mapXPos;
}

int Player::getYPos() const
{
	return this->mapYPos;
}