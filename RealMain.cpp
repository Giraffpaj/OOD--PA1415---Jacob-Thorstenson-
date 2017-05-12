#include "SFML/Graphics.hpp"
#include "MovementHandler.h"
#include "GameLogic.h"
int main()
{
	GameLogic g1;
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORKS!");
	window.setFramerateLimit(30); 

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
}