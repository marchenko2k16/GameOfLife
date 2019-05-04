#pragma once

#include "SFML/Graphics.hpp"

class View
{
private:

	static void zoomFunc(float);
	static void shiftFunc(float, float);

public:
	
	static double zoom;
	static double xShift;
	static double yShift;
	static void buttonPressed(sf::Event e);

};

