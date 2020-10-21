#include "Game.h"
#include <iostream>



Game::Game() : window { sf::VideoMode(1920, 1080, 32), "AI Labs", sf::Style::Fullscreen}
{
	KinematicBehaviours behaviourTypes = FLEE;

	flee.physics.setVelocity(sf::Vector2f{ 1, 1 });
	flee.setPlayer(&player);
	flee.setBehaviourType(behaviourTypes);
	flee.setupTextMessage();
	npcs.push_back(flee); 
	

	behaviourTypes = WANDER;
	wander.physics.setVelocity(sf::Vector2f{ 1, 1 });
	wander.setPlayer(&player);
	wander.setBehaviourType(behaviourTypes);
	wander.setupTextMessage();
	npcs.push_back(wander);


	behaviourTypes = SEEK;
	seek.physics.setVelocity(sf::Vector2f{ 1, 1 });
	seek.setPlayer(&player);
	seek.setBehaviourType(behaviourTypes);
	seek.setupTextMessage();
	npcs.push_back(seek);



	behaviourTypes = ARRIVAL;
	arrival.physics.setVelocity(sf::Vector2f{ 1, 1 });
	arrival.setPosition(sf::Vector2f(500, 500));
	arrival.setPlayer(&player);
	arrival.setBehaviourType(behaviourTypes);
	arrival.setupTextMessage();
	npcs.push_back(arrival);

	behaviourTypes = ARRIVAL_SLOW;
	arrivalSlow.physics.setVelocity(sf::Vector2f{ 1, 1 });
	arrivalSlow.setPosition(sf::Vector2f(500, 500));
	arrivalSlow.setPlayer(&player);
	arrivalSlow.setBehaviourType(behaviourTypes);
	arrivalSlow.setupTextMessage();
	npcs.push_back(arrivalSlow);

	behaviourTypes = PERSUE;
	pursue.physics.setVelocity(sf::Vector2f{ 1, 1 });
	pursue.setPosition(sf::Vector2f(300, 500));
	pursue.setPlayer(&player);
	pursue.setBehaviourType(behaviourTypes);
	pursue.setupTextMessage();
	npcs.push_back(pursue);

	//Npc two;
	//behaviourTypes = SEEK;
	//two.physics.setVelocity(sf::Vector2f{ 1, 1 });
	//two.setPlayer(&player);
	//two.setBehaviourType(behaviourTypes);
	//npcs.push_back(two);

	//behaviourTypes = ARRIVAL;
	//npc.setBehaviourType(behaviourTypes);
	//npcs.push_back(npc);

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
		deltaTime = clock.getElapsedTime().asSeconds() - timeAtEndOfPreviousFrame.asSeconds();

		if (clock.getElapsedTime() < timeAtEndOfPreviousFrame + timePerFrame)
		{
			render();
			continue;
		}

		update(deltaTime);
		timeAtEndOfPreviousFrame = clock.getElapsedTime();
		render();
	}
}

void Game::render()
{
	window.clear();

	player.draw(window);
	for (int i = 0; i < npcs.size(); i++)
	{
		npcs[i].draw(window);
	}

	window.display();
}

void Game::update(float deltaTime)
{
	player.update(deltaTime);

	for (int i = 0; i < npcs.size(); i++)
	{
		npcs[i].update(deltaTime);
	}
}

