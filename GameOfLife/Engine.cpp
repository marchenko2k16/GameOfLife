#include "Engine.h"
#include "View.h"

sf::RenderWindow* Engine::gameWindow;

void Engine::initWorld(World* wrld)
{
	world = wrld;
}

Engine::Engine(sf::RenderWindow& wnd)
{
	gameWindow = &wnd;
}


#include <thread>
void Engine::start()
{
	sf::Event event;

	while (gameWindow->isOpen())
	{
		while (gameWindow->pollEvent(event))
		{
			View::buttonPressed(event);
		}

		gameWindow->clear();
		Render::render(world->worldMap);
		gameWindow->display();

	//	std::this_thread::sleep_for(std::chrono::seconds(10));

		world->checkStates();
		world->update();
	}
}
