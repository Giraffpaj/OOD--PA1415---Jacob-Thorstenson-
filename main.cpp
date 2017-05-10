#include <SFML/Graphics.hpp>
#include <ctime>
#include "MapGenerator.h"
#include "GameLogic.h"

int main()
{
	GameLogic myGameLogic;
	//data skapats
	srand(static_cast<unsigned>(time(0)));
	//sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	
	//looop
	
	
	
	
	myGameLogic->tick();
	
	MapGenerator mG(32,25);
	mG.createMapDesign();
	mG.draw();
	
	//slut ppå loop
}
