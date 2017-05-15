#include "Library.h"

Library::Library()
{
	//This is where everything gets created as game is started, before INGAME state.

	Player*player1 = new Player(100, 500, "player1", 1, "player1");
	this->objects.add(player1);

	Object * lavaTile= new Object("wallTile", 10, "wallTile");
	this->objects.add(lavaTile);

	Object * pathTile = new Object("pathTile", 20, "pathTile");
	this->objects.add(pathTile);

	Object * stairs = new Object("stairs", 30, "stairs"); 
	this->objects.add(stairs); 

	this->myMap = new Map();

	Sword *sword=new Sword;
	this->objects.add(sword);


}

Library::~Library()
{
	delete this->myMap;
}

Object* Library::getObject(int id) const
{
	return this->objects.getByID(id);
}

void Library::setLayer(std::string layer, int ** layerData)
{
	this->myMap->setLayer(layer,layerData);
}

int Library::getMapID(string layer, int x, int y)
{
	return this->myMap->getLayerID(layer,x,y);
}

void Library::setMapID(string layer, int x, int y, int ID)
{
	this->myMap->setMapID(layer, x, y, ID);
}

//std::string Library::find(int id) const
//{
//	string category = "noCategoryFound";
//	//funktionen under bör ligga  i en forloop, men nu har vvi bara en spelare så den ligger löst
//	this->objects.find(Object.id)
//	if (this->players[0]->getID() == id)
//	{
//		category = "player";
//	}
//	return category;
//}
