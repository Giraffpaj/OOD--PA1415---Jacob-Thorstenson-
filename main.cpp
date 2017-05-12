#include <SFML/Graphics.hpp>
#include <ctime>
#include "MapGenerator.h"

int main()
{
	srand(static_cast<unsigned>(time(0)));
	//sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	MapGenerator mG(32,25);
	mG.createMapDesign();


}