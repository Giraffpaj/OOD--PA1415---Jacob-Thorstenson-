#ifndef SWORD_H
#define SWORD_H
#include"Item.h"

class Sword : public Item
{
private:
	int damagePoints;
public:
	Sword(int damagePoints=10);
};





#endif