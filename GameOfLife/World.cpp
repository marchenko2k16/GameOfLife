#include "World.h"

unsigned int World::height;
unsigned int World::width;

extern int windowHeight;
extern int windowWidth;

void World::checkForChanges(unsigned int row, unsigned int col)
{
	bool flag = false;
	int count = 0;


	int i;
	if (row == 0)
	{
		i = 0;
	}
	else
	{
		i = row - 1;
	}

	int _j;
	if (col == 0)
	{
		_j = 0;
	}
	else
	{
		_j = col - 1;
	}

	for (; i <= (row + 1) && i < World::height; ++i)
	{
		for (auto j = _j; j <= (col + 1) && j < World::width; ++j)
		{
			if (!(i == row && j == col) && worldMap[i][j].getState() == State::ALIVE)
			{
				count++;
			}
		}
	}

	if (worldMap[row][col].getState() == State::DEAD && count == 3)
	{
		flag = true;
	}
	else if (worldMap[row][col].getState() == State::ALIVE && (count == 2 || count == 3))
	{
		flag = true;
	}
	else if (worldMap[row][col].getState() == State::ALIVE && (count < 2 || count > 3))
	{
		flag = false;
	}

	worldMap[row][col].setNext(flag);
	
}

void World::checkStates()
{
	for (auto i = 0; i < height; ++i)
	{
		for (auto j = 0; j < width; ++j)
		{
			checkForChanges(i, j);
		}
	}
}

void World::update()
{

	for (auto i = 0; i < height; ++i)
	{
		for (auto j = 0; j < width; ++j)
		{
			worldMap[i][j].update();
		}
	}
	
}

World::World(unsigned int row, unsigned int column)
{
	World::width = row;	
	World::height = column;

	worldMap = new GameUnit*[height];
	for (auto i = 0; i < height; ++i)
	{
		worldMap[i] = new GameUnit[width];
	}

	for (auto i = 0; i < height; ++i)
	{
		for (auto j = 0; j < width; ++j)
		{
			worldMap[i][j] = GameUnit();
		}
	}

	for (auto i = 0; i < height; ++i)
	{
		for (auto j = 0; j < width; ++j)
		{
			worldMap[i][j].setPosition(sf::Vector2f((windowWidth / World::width) * j, (windowHeight / World::height) * i));
			worldMap[i][j].setSize(sf::Vector2f(windowWidth / World::width, windowHeight / World::height));
		}
	}

}

World::~World()
{
	for (int i = 0; i < height; ++i)
	{
		delete[] worldMap[i];
	}
	delete[] worldMap;
	worldMap = 0;
}
