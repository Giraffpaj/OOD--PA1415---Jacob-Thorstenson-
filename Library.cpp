#include "Library.h"

Library::Library()
{
	//This is where everything gets created as game is started, before INGAME state.

	//creating a Player
	this->players = new Player(100, 500, "player1", 1, "player1");
}

Library::~Library()
{
	delete this->players;
}

Player Library::getPlayer(int id) const
{//Denna måste fixas ordentligt sen
	int index = 0; 
	if (players[0].getID() == id)
	{
		index = 0;
	}
	return players[0];
	//Denna måste fixas ordentligt sen
}

std::string Library::find(int id) const
{
	string category = "noCategoryFound";
	//funktionen under bör ligga  i en forloop, men nu har vvi bara en spelare så den ligger löst
	if (this->players[0].getID() == id)
	{
		category = "player";
	}
	return category;
}
