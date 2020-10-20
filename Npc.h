#pragma once

#include "Character.h"
#include "KinematicBehaviour.h"
#include "Player.h"
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

	void setPlayer(Player* player) { this->player = player; }
private:
	Player* player;
	sf::Sprite sprite;
	sf::Texture texture;
	KinematicBehaviour kin = KinematicBehaviour(physics.velocity);

	void initialiseSprite();
	void setSpriteAngle();

	void moveNpc(float deltaTime);

};