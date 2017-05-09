#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include <SFML\System.hpp>
#include <ctime>
#include <string>
#include <iostream>
class MapGenerator
{
private:
	int**tempMap;
	int length;
	int height;
	sf::Vector2i start;
	int currentPathLength;
public:
	MapGenerator(int length, int height);
	sf::Vector2i* createPath(int up, int right, int down, int left);
	void createMapDesign(int recursion = 0);
	void draw();
};

#endif //MAPGENERATOR_H