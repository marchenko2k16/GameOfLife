#pragma once

#include "GameUnit.h"

class World
{
private:

	void checkForChanges(unsigned int col, unsigned int row);

public:

	static unsigned int height;
	static unsigned int width;

	GameUnit** worldMap; 

	void checkStates();
	void update();
	
	World(unsigned int row, unsigned int column);
	~World();
};
