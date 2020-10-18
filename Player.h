#pragma once
#include "Character.h"
#include "InputManager.h"

class Player : public Character
{
public:
	Player(); 
	Player(sf::Vector2f position) { this->position = position; };
	Player(Physics2D physics) { this->physics = physics; };
	Player(sf::Vector2f position, Physics2D physics)
	{
		this->physics = physics;
		this->position = position;
	};
	~Player();
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
	void update(float deltaTime);
private:
	//sf::Sprite sprite;
	sf::CircleShape sprite;

	float speed = 1.0f;

	InputManager input;

	void movePlayer(float deltaTime);
	

};