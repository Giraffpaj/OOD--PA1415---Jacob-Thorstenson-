#include "MapGenerator.h"

MapGenerator::MapGenerator(int length, int height)
{
	this->length = length;
	this->height = height;
	this->tempMap = new int*[length];
	for (int a = 0; a < this->length; a++)
	{
		this->tempMap[a] = new int[this->height];
	}
	this->start.x = this->length / 2;
	this->start.y = this->height / 2;
}

sf::Vector2i* MapGenerator::createPath(int up, int right, int down, int left)
{
	int nrOfTiles = 0;
	int value = 0;
	int cap = rand() % 3 + 5;
	this->currentPathLength = cap;
	sf::Vector2i*path = new sf::Vector2i[cap];
	path[0] = this->start;
	int move = 0;
	int direction = 0;
	while (nrOfTiles <= cap)
	{
		move = rand() % 10 + 1;
		if (direction == 0 && up >= move)
		{//makeMove
			value = -1;
			if (this->height > path[nrOfTiles].y + value && path[nrOfTiles].y+value > 0)
			{
				path[nrOfTiles + 1] = sf::Vector2i(path[nrOfTiles].x, path[nrOfTiles].y + value);
				nrOfTiles++;
			}
		}
		else if (direction == 1 && right >= move)
		{//makeMove
			value = 1;
			if (this->length > path[nrOfTiles].x + value && path[nrOfTiles].x+value > 0)
			{
				path[nrOfTiles + 1] = sf::Vector2i(path[nrOfTiles].x+value, path[nrOfTiles].y);
				nrOfTiles++;
			}
		}
		else if (direction == 2 && down >= move)
		{//makeMove
			value = 1;
			if (this->height > path[nrOfTiles].y + value && path[nrOfTiles].y + value > 0)
			{
				path[nrOfTiles + 1] = sf::Vector2i(path[nrOfTiles].x, path[nrOfTiles].y + value);
				nrOfTiles++;
			}
		}
		else if (direction == 3 && left >= move)
		{//makeMove
			value = -1;
			if (this->length > path[nrOfTiles].x + value && path[nrOfTiles].x + value > 0)
			{
				path[nrOfTiles + 1] = sf::Vector2i(path[nrOfTiles].x + value, path[nrOfTiles].y);
				nrOfTiles++;
			}
		}
		direction++;
		if (direction > 3)
		{
			direction = 0;
		}
	}
	return path;
}

void MapGenerator::createMapDesign(int recursion)
{
	for (int b = 0; b < 10; b++)
	{
		int up = rand() % 10;
		int right = rand() % 10;
		int down = rand() % 10;
		int left = rand() % 10;
		sf::Vector2i*path = this->createPath(up, right, down, left);
		for (int a = 0; a < this->currentPathLength; a++)
		{
			this->tempMap[path[a].x][path[a].y] = 1;
		}
		int randNr = rand()%this->currentPathLength;
		start = path[randNr];
		//delete[] path;
	}
	if (recursion != 5)
	{
		this->start.x = this->length / 2;
		this->start.y = this->height / 2;
		this->createMapDesign(recursion + 1);
	}

}

void MapGenerator::draw()
{
	for (int a = 0; a < this->height; a++)
	{
		for (int b = 0; b < this->length; b++)
		{
			if (this->tempMap[b][a] == 1)
			{
				std::cout << "X";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
