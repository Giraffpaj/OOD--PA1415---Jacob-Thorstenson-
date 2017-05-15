#include "MapGenerator.h"

void MapGenerator::expand()
{
	this->cap += this->increment;
	sf::Vector2i*temp = new sf::Vector2i[this->cap];
	for (int a = 0; a < this->nrOfPoints; a++)
	{
		temp[a] = this->crossPoints[a];
	}
	delete[]this->crossPoints;
	this->crossPoints = temp;
}

void MapGenerator::deepCopy(const MapGenerator & other)
{
	this->cap = other.cap;
	this->increment = other.increment;
	this->nrOfPoints = other.nrOfPoints;
	this->xSize = other.xSize;
	this->ySize = other.ySize;
	this->crossPoints = new sf::Vector2i[this->cap];
	this->map = new int*[this->ySize];
	for (int a = 0; a < this->ySize; a++)
	{
		this->map[a] = new int[this->xSize];
		for (int b = 0; b < this->xSize; b++)
		{
			this->map[a][b] = other.map[a][b];
		}
	}
	for (int a = 0; a < this->nrOfPoints; a++)
	{
		this->crossPoints[a] = other.crossPoints[a];
	}
}

void MapGenerator::clearAll()
{
	for (int a = 0; a < this->ySize; a++)
	{
		delete[] this->map[a];
	}
	delete[]this->map;
	delete[]this->crossPoints;
}

MapGenerator::MapGenerator(int xSize, int ySize, DrawHandler*myDrawHandler, Library*myLibrary)
{
	this->myDrawHandler = myDrawHandler;
	this->myLibrary = myLibrary;
	this->nrOfMapTiles = 0;
	this->corridorSize = 0;
	this->currentCrosspoint = 0;
	this->cap = this->increment = 20;
	this->nrOfPoints = 0;
	this->xSize = xSize;
	this->ySize = ySize;
	this->map = new int*[this->ySize];
	for (int a = 0; a < this->ySize; a++)
	{
		this->map[a] = new int[this->xSize];
	}
	this->crossPoints = new sf::Vector2i[this->cap];

}

MapGenerator::~MapGenerator()
{
	this->clearAll();
}

MapGenerator::MapGenerator(const MapGenerator & other)
{
	this->deepCopy(other);
}

MapGenerator & MapGenerator::operator=(const MapGenerator & other)
{
	if (this != &other)
	{
		this->clearAll();
		this->deepCopy(other);
	}
	return *this;
}

void MapGenerator::createMapDesign()
{
	this->nrOfMapTiles = 0;
	sf::Vector2i*corridor;
	bool successfulApply = true;
	int x = 25;
	int y = 14;
	this->crossPoints[0] = sf::Vector2i(x, y);
	int dirPriority[4] = { 0,1,2,3 };
	while (this->nrOfMapTiles < 300)
	{
		int randIndex = rand() % 4;
		dirPriority[0] = dirPriority[randIndex];
		dirPriority[3] = this->getTail(dirPriority[0]);
		randIndex = rand() % 2;
		if (dirPriority[0] == 0 || dirPriority[0] == 2)
		{
			if (randIndex == 0) {
				dirPriority[1] = 1;
				dirPriority[2] = 3;
			}
			else {
				dirPriority[1] = 3;
				dirPriority[2] = 1;
			}
		}
		else
		{
			if (randIndex == 0) {
				dirPriority[1] = 0;
				dirPriority[2] = 2;
			}
			else {
				dirPriority[1] = 2;
				dirPriority[2] = 0;
			}
		}
		successfulApply = true;
		std::cout << this->nrOfMapTiles << std::endl;
		int middle = rand() % 5;
		if (middle == 1)
		{
			corridor = this->createCorridor(dirPriority, crossPoints[0]);
		}
		else
		{
			corridor = this->createCorridor(dirPriority, crossPoints[rand() % (this->nrOfPoints + 1)]);
		}
		
		for (int a = 0; a < this->corridorSize; a++)
		{
			if (corridor[a].y > 0 && corridor[a].y < this->ySize - 1 && corridor[a].x > 0 && corridor[a].x < this->xSize - 1)
			{
				this->nrOfMapTiles++;
				this->map[corridor[a].y][corridor[a].x] = 1;
			}
			else
			{
				successfulApply = false;
				a = this->corridorSize;
			}
		}
		if (successfulApply)
		{
			this->crossPoints[this->nrOfPoints++] = corridor[this->corridorSize-1];
		}
		if (corridor != nullptr)
		{
			delete[]corridor;
		}
	}
}

sf::Vector2i * MapGenerator::createCorridor(int dirPriority[], sf::Vector2i start)
{
	int randCap = rand() % 4 + 10;
	sf::Vector2i*corridor = new sf::Vector2i[randCap*3];
	corridor[0] = start;
	int nrOfSteps = 1;
	for(int a = 0; a < randCap; a++)
	{
		int randNum = rand() % 170;
		if (randNum > 90)
		{
			start = makeStep(dirPriority[0], start);
			corridor[nrOfSteps++] = start;
			//expand possibility
			randNum = rand() % 170;
			if (randNum > 150)
			{
				randNum = rand() % 2;
				if (randNum == 1)
				{
					start = makeStep(this->getLeft(dirPriority[0]), start);
					corridor[nrOfSteps++] = start;
				}
				else
				{
					start = makeStep(this->getLeft(dirPriority[0]), start);
					corridor[nrOfSteps++] = start;
				}
				
			}
		}
		else if (randNum > 30)
		{
			start = makeStep(dirPriority[1], start);
			corridor[nrOfSteps++] = start;
			//expand possibility
			randNum = rand() % 170;
			if (randNum > 150)
			{

				start = makeStep(this->getRight(dirPriority[1]), start);
				corridor[nrOfSteps++] = start;
			}
			if (randNum > 110)
			{
				randNum = rand() % 2;
				if (randNum == 1)
				{
					start = makeStep(this->getLeft(dirPriority[1]), start);
					corridor[nrOfSteps++] = start;
				}
				else
				{
					start = makeStep(this->getLeft(dirPriority[1]), start);
					corridor[nrOfSteps++] = start;
				}

			}
		}
		else if (randNum > 10)
		{
			start = makeStep(dirPriority[2], start);
			corridor[nrOfSteps++] = start;
			//expand possibility
			randNum = rand() % 170;
			if (randNum > 150)
			{

				start = makeStep(this->getRight(dirPriority[2]), start);
				corridor[nrOfSteps++] = start;
			}
			if (randNum > 110)
			{
				randNum = rand() % 2;
				if (randNum == 1)
				{
					start = makeStep(this->getLeft(dirPriority[2]), start);
					corridor[nrOfSteps++] = start;
				}
				else
				{
					start = makeStep(this->getLeft(dirPriority[2]), start);
					corridor[nrOfSteps++] = start;
				}

			}
		}
		else
		{
			start = makeStep(dirPriority[3], start);
			corridor[nrOfSteps++] = start;
			//expand possibility
			randNum = rand() % 170;
			if (randNum > 150)
			{

				start = makeStep(this->getRight(dirPriority[3]), start);
				corridor[nrOfSteps++] = start;
			}
			if (randNum > 110)
			{
				randNum = rand() % 2;
				if (randNum == 1)
				{
					start = makeStep(this->getLeft(dirPriority[3]), start);
					corridor[nrOfSteps++] = start;
				}
				else
				{
					start = makeStep(this->getLeft(dirPriority[3]), start);
					corridor[nrOfSteps++] = start;
				}

			}
		}
	}
	this->corridorSize = nrOfSteps;
	return corridor;
}

sf::Vector2i MapGenerator::makeStep(int dir, sf::Vector2i lastStart)
{

	if (dir == 0)
	{
		lastStart.y--;
	}
	else if (dir == 1)
	{
		lastStart.x++;
	}
	else if (dir == 2)
	{
		lastStart.y++;
	}
	else
	{
		lastStart.x--;
	}

	return lastStart;
}

int MapGenerator::getLeft(int dir)
{
	int left;
	if (dir == 0)
		left = 3;
	else if (dir == 1)
		left = 0;
	else if (dir == 2)
		left = 1;
	else
		left = 2;
	return left;
}

int MapGenerator::getRight(int dir)
{
	int right;
	if (dir == 0)
		right = 1;
	else if (dir == 1)
		right = 2;
	else if (dir == 2)
		right = 3;
	else
		right = 0;
	return right;
}

int MapGenerator::getTail(int dir)
{
	int tail;
	if (dir == 0)
		tail = 2;
	else if (dir == 1)
		tail = 3;
	else if (dir == 2)
		tail = 0;
	else
		tail = 1;
	return tail;
}



void MapGenerator::drawMap()
{
	Object*tile;
	for (int a = 0; a < this->ySize; a++)
	{
		for (int b = 0; b < this->xSize; b++)
		{
			if (map[a][b] == 1)
			{
				map[a][b] = 20;
				tile = new Object(*this->myLibrary->getObject(20));
				tile->moveRectangleShape(b * 32, a * 32);
				this->myDrawHandler->addObject(tile);
			}
			else if(map[a][b] == 2)
			{
				tile = new Object(*this->myLibrary->getObject(30)); 
				tile->moveRectangleShape(b * 32, a * 32); 
				this->myDrawHandler->addObject(tile); 
			}

			else
			{
				map[a][b] = 10;
				tile = new Object(*this->myLibrary->getObject(10));
				tile->moveRectangleShape(b * 32, a * 32);
				this->myDrawHandler->addObject(tile);
			}
		}
	}
		int randPlayerPos = rand() % this->nrOfPoints;
		Player*thePlayer = static_cast<Player*>(this->myLibrary->getObject(1));
		thePlayer->setMapPos(this->crossPoints[randPlayerPos].x, this->crossPoints[randPlayerPos].y);
		thePlayer->moveRectangleShape(this->crossPoints[randPlayerPos].x*32, this->crossPoints[randPlayerPos].y*32);
		this->myLibrary->setLayer("design", this->map);
}

void MapGenerator::createExitTile()
{
	int randNr = rand() % this->nrOfPoints;
	sf::Vector2i exitPoint = this->crossPoints[randNr];
	this->map[exitPoint.y][exitPoint.x] = 2;
}
