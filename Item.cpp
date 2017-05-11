#include "Item.h"

Item::Item(int itemID, string name, string itemType, string description, string myTexture)
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
