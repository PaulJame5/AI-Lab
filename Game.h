#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Npc.h"
class Game
{
public:
	Game();
	~Game();
	void run();
	void render();
	void update(float deltaTime);


private:

	Player player;
	Npc npc;
	sf::RenderWindow window;
	bool exitGame = false;
	float deltaTime = 0;

};