#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Npc.h"
#include "Enums.h"

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
	std::vector<Npc> npcs = std::vector<Npc>();
	Npc flee, wander, seek, arrival,arrivalSlow, pursue;
	sf::RenderWindow window;
	bool exitGame = false;
	float deltaTime = 0;

};