#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include <iostream>
#include <SFML\System.hpp>
#include <ctime>
#include "DrawHandler.h"
#include "Library.h"

class MapGenerator
{
private:
	DrawHandler*myDrawHandler;
	Library*myLibrary;
	int xSize;
	int ySize;
	int**map;
	int nrOfMapTiles;
	sf::Vector2i*crossPoints;
	int cap;
	int increment;
	int nrOfPoints;
	int currentCrosspoint;
	int corridorSize;
	void expand();
	void deepCopy(const MapGenerator & other);
	void clearAll();
public:
	MapGenerator(int xSize, int ySize, DrawHandler*myDrawHandler, Library*myLibrary);
	~MapGenerator();
	MapGenerator(const MapGenerator & other);
	MapGenerator& operator=(const MapGenerator & other);
	void createMapDesign();
	sf::Vector2i* createCorridor(int dirPriority[], sf::Vector2i start);
	sf::Vector2i makeStep(int dir, sf::Vector2i lastStart);
	int getLeft(int dir);
	int getRight(int dir);
	int getTail(int dir);
	void drawMap();
	void createExitTile(); 
};

#endif //MAPGENERATOR_H