#ifndef ITEM_H
#define ITEM_H
#include "Object.h"

class Item : public Object
{
	private:
		string itemType;
		string description;

	public:
		Item(int itemID, string name, string itemType, string description, string myTexture);
		~Item() {};
		string getType() const;
		string getDescription() const;
};
#endif //ITEM_H