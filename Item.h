#ifndef ITEM_H
#define ITEM_H
#include "Object.h"

class Item : public Object
{
	private:
		string itemType;
		string description;

	public:
		Item(string itemType, string description, string myTexture, int itemID, string name);
		~Item() {};
		string getType() const;
		string getDescription() const;
};
#endif //ITEM_H