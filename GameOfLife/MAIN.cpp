#include "SFML/Graphics.hpp"
#include <iostream>
#include "Randomizer.h"
#include "World.h"
#include "Engine.h"



int windowWidth = 1000;
int windowHeight = 1000;
int rows = 100;
int columns = 100;



int main()
{

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "GAME OF LIFE");

	World* wrld = new World(rows, columns);
	Engine engine(window);
	engine.initWorld(wrld);
	engine.start();

}
