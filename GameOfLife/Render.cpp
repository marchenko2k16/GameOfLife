#include "Render.h"
#include "Engine.h"


void Render::render(GameUnit** world)
{
	for (auto i = 0; i < World::height; ++i)
	{
		for (auto j = 0; j < World::width; ++j)
		{
			Engine::gameWindow->draw(world[i][j].shape);
		}
	}
}
