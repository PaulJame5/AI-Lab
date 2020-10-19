#pragma once

#include "Character.h"

class Npc : public Character
{

public:
	Npc();
	Npc(sf::Vector2f position) { this->position = position; };
	Npc(Physics2D physics) { this->physics = physics; };
	Npc(sf::Vector2f position, Physics2D physics)
	{
		this->physics = physics;
		this->position = position;
	};
	~Npc();
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
	void update(float deltaTime);
private:
	sf::Sprite sprite;
	sf::Texture texture;

	void initialiseSprite();

	void moveNpc(float deltaTime);
};