#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();
	void* draw(sf::RenderWindow& window) { window.draw(sprite); return 0; }
private:
	//sf::Sprite sprite;
	sf::CircleShape sprite;

};