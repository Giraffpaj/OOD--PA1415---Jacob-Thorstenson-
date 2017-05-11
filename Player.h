#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"

class Player : public Object
{
	private:
		int health;
		int damage;
		int movement;
		int mapXPos;
		int mapYPos;
		int playerID;
		//Backpack myBackpack;
	public:
		Player(string textureName, int id, string name, int mapXPos, int mapYPos, int playerID);
		~Player();
		void setPosition(int playerPosX, int playerPos);
		void die();
		int getHealth()const;
		int getXPos()const;
		int getYPos()const;
		

};
#endif //PLAYER_H