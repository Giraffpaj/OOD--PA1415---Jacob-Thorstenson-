#include "SFML/Graphics.hpp"
#include "MovementHandler.h"
#include "GameLogic.h"
int main()
{
	srand(static_cast<unsigned>(time(0)));
	GameLogic g1;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML WORKS!");
	window.setFramerateLimit(15); 

	//MovementHandler MH; 
	while (window.isOpen())
	{
		sf::Event event; //Skapar ett event

		while (window.pollEvent(event)) //skapar ett event som gör att man kan kryssa ner fönstret
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}

		}
		//MH.update(); 
		//MH.updateMovement();
		//MH.updateMovement2(); 
		//MH.combat(); 
		window.clear();
		g1.tick(window);
		//window.draw(MH.getPlayerSprite()); 
		window.display();
	}
	
	delete g1;
	return 0;
}
