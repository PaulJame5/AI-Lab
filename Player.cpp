#include "Player.h"

Player::Player()
{
	sprite.setFillColor(sf::Color::Red);
	sprite.setRadius(5);
	position = sf::Vector2f{ 0,0 };
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	movePlayer(deltaTime);

	sprite.setPosition(position);
}

void Player::movePlayer(float deltaTime)
{
	if (input.heldDown())
	{
		position.y += speed * deltaTime;
	}
	else if (input.heldUp())
	{
		position.y -= speed * deltaTime;
	}
	if (input.heldLeft())
	{
		position.x -= speed * deltaTime;
	}
	else if (input.heldRight())
	{
		position.x += speed * deltaTime;
	}

	wrapAroundWorld();

}
