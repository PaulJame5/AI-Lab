#pragma once

#include "Character.h"

class Npc : public Character
{

public:
	Npc();
	~Npc();
	void* draw(sf::RenderWindow& window) { window.draw(sprite); return 0; }
private:
	//sf::Sprite sprite;
	sf::CircleShape sprite;
};