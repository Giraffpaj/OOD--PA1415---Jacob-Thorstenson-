#include "Map.h"

Map::Map()
{
	this->designLayer = nullptr;
	this->charLayer = new int*[28];
	for (int a = 0; a < 28; a++)
	{
		this->charLayer[a] = new int[50];
		for (int b = 0; b < 50; b++)
		{
			this->charLayer[a][b] = 0;
		}
	}
	this->itemLayer = nullptr;
}

Map::~Map()
{
	for (int a = 0; a < 28; a++)
	{
		delete[] this->designLayer[a];
	}
}

void Map::setLayer(std::string layer, int ** layerData)
{
	if (layer == "design")
	{
		this->designLayer = layerData;
	}
}

int Map::getLayerID(std::string layer, int x, int y)
{
	int ID;
	if (layer == "design")
	{
		ID = this->designLayer[y][x];
	}
	return ID;
}

void Map::setMapID(std::string layer, int x, int y, int ID)
{
	if (layer == "design")
	{
		this->designLayer[y][x] = ID;
	}
}

void Map::clearMap()
{
	
}
