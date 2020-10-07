#include "Game.h"
#include <iostream>



Game::Game() : window { sf::VideoMode(1920, 1080, 32), "AI Labs", sf::Style::Fullscreen}
{
	
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeAtEndOfPreviousFrame = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds((1.f / 60.0f));

	while (window.isOpen() && !exitGame)
	{
		deltaTime = clock.getElapsedTime().asMilliseconds() - timeAtEndOfPreviousFrame.asMilliseconds();

		if (clock.getElapsedTime() < timeAtEndOfPreviousFrame + timePerFrame)
		{
			render();
			std::cout << "too soon to update" << std::endl;
			continue;
		}
			update(deltaTime);
			timeAtEndOfPreviousFrame = clock.getElapsedTime();
			render();

			std::cout << "updated complete" << std::endl;
		
	}
}

void Game::render()
{
	window.clear();

	player.draw(window);
	npc.draw(window);

	window.display();
}

void Game::update(float deltaTime)
{
	std::cout << "updating..." << std::endl;
}

