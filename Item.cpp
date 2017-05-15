#include "Item.h"

Item::Item(string itemType, string description, string myTexture, int itemID, string name)
	: Object(myTexture,itemID, name)
{
	this->itemType = itemType;
	this->description = description;
}

string Item::getType() const
{
	return this->itemType;
}

string Item::getDescription() const
{
	return this->description;
}
