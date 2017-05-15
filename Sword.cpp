#include"Sword.h"

Sword::Sword(int damagePoints)
:Item("Weapon", "This sword has no epic history at all. It's rusty, ugly and completely worthless when it comes to a sword fight."
	, "sword", 1, "Rusty Sword")
{
	this->setRectangleShape(sf::RectangleShape(sf::Vector2f(32, 32)));
}