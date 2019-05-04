#include "View.h"

double View::zoom = 1;
double View::xShift;
double View::yShift;

void View::zoomFunc(float _zoom)
{
	zoom += _zoom;
}

void View::shiftFunc(float shiftX, float shiftY)
{
	View::xShift += shiftX;
	View::yShift += shiftY;
}

void View::buttonPressed(sf::Event e)
{
	if (e.type == e.KeyPressed)
	{
		switch (e.key.code)
		{
		case (sf::Keyboard::Left):
			shiftFunc(20, 0);
			break;
		case (sf::Keyboard::Right):
			shiftFunc(-20, 0);
			break;
		case (sf::Keyboard::Up):
			shiftFunc(0, 20);
			break;
		case (sf::Keyboard::Down):
			shiftFunc(0, -20);
			break;
		case (sf::Keyboard::W):
			zoomFunc(0.1);
			break;
		case (sf::Keyboard::S):
			zoomFunc(-0.1);	
			break;

		default:
			break;
		}

	}
}
