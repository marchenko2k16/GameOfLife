#pragma once

#include "SFML/Graphics.hpp"
#include "World.h"
#include "Render.h"

class Engine
{
public:

	World* world;
	static sf::RenderWindow* gameWindow;
	void initWorld(World* wrld);
	void start();

	Engine(sf::RenderWindow& wnd);

};

