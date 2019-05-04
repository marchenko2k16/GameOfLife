#pragma once

#include "Randomizer.h"

#include "SFML/Graphics.hpp"

enum class State {DEAD, ALIVE, DEFAULT_NEXT};

class GameUnit
{
private:

	State currentState;
	State nextState;
	sf::Vector2f position;
	sf::Vector2f size;
	void updateState();
	void updateColor();

	void setRectangleView();
public:

	sf::RectangleShape shape;

	void update();

	void setNext(bool flag);
	void setPosition(sf::Vector2f _position);
	
	void setSize(sf::Vector2f _size);

	State getState() const;
	//sf::Vector2f getPosition() const;

	GameUnit();
	GameUnit(bool flag);

};

