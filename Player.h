#pragma once
#include "Character.h"
#include "InputManager.h"

class Player : public Character
{
public:
	Player(); 
	Player(sf::Vector2f position) { this->position = position; initialiseSprite(); };
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

	sf::Sprite sprite;
	sf::Texture texture;

	float acceleration = 0.01f;

	InputManager input;

	void updateVelocity(float deltaTime);
	void movePlayer(float deltaTime);
	void initialiseSprite();

	void setSpriteAngle();
	
	const float MAX_DIRECTIONAL_VELOCITY = 3.0f;

};