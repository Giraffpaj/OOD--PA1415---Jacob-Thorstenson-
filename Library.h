#pragma once
#include "Player.h"

class Library
{
private:
	Player*players;
	//int nrOfPlayers;
	//static const int PLAYER_CAP = 4; eller?
public:
	Library();
	~Library();
	Player getPlayer(int id)const;
	std::string find(int id)const;
};