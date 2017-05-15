#pragma once
#ifndef MAP_H
#define MAP_H
#include <string>
class Map
{
private:
	int**designLayer;
	int**itemLayer;
	int**charLayer;
public:
	Map();
	~Map();
	void setLayer(std::string layer, int**layerData);
	int getLayerID(std::string layer, int x, int y);
	void setMapID(std::string layer, int x, int y, int ID);
	void clearMap(); 


};
#endif //MAP_H