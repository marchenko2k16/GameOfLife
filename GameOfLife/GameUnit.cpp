#include "GameUnit.h"
#include "View.h"

void GameUnit::update()
{
	updateState();
	updateColor();
	setRectangleView();
}

void GameUnit::updateState()
{
	currentState = nextState;
}

void GameUnit::updateColor()
{
	currentState == State::ALIVE ? shape.setFillColor(sf::Color::Yellow) : shape.setFillColor(sf::Color::Black);
}

void GameUnit::setRectangleView()
{
	double posX = position.x - (position.x - position.x * View::zoom) + View::xShift;
	double posY = position.y - (position.y - position.y * View::zoom) + View::yShift;
	shape.setPosition(posX, posY);
	shape.setSize(sf::Vector2f(size.x * View::zoom, size.y * View::zoom));
	
}

void GameUnit::setNext(bool flag)
{
	flag ? nextState = State::ALIVE : nextState = State::DEAD;
}

void GameUnit::setPosition(sf::Vector2f _position)
{
	position = _position;
	shape.setPosition(position);
}

void GameUnit::setSize(sf::Vector2f _size)
{
	size = _size;
	shape.setSize(size);
}

State GameUnit::getState() const
{
	return currentState;
}

//sf::Vector2f GameUnit::getPosition() const
//{
//	return position;
//}

GameUnit::GameUnit()
{
	Randomizer<double>::randomize(0, 10) > 5 ? currentState = State::ALIVE : currentState = State::DEAD;
	nextState = State::DEFAULT_NEXT;
	currentState == State::ALIVE ? shape.setFillColor(sf::Color::Yellow) : shape.setFillColor(sf::Color::Black);
}

GameUnit::GameUnit(bool flag)
{
	flag ? currentState = State::ALIVE : currentState = State::DEAD;
	nextState = State::DEFAULT_NEXT;
	updateColor();
}

