#ifndef LIBRARY_H
#define LIBRARY_H
#include "Player.h"
#include "Sword.h"
#include "ArrayList.h"
#include "Map.h"

class Library
{
private:
	ArrayList<Object> objects;
	Map*myMap;

public:
	
	Library();
	~Library();
	Object* getObject(int id)const;
	void setLayer(string layer, int**layerData);
	int getMapID(string layer, int x, int y);
	void setMapID(string layer, int x, int y, int ID);
	//std::string find(int id)const;
};
#endif