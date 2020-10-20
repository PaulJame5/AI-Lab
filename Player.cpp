#include "Player.h"

Player::Player()
{
	initialiseSprite();
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

void Player::updateVelocity(float deltaTime)
{
	if (input.heldDown())
	{
		if (physics.velocity.y < MAX_DIRECTIONAL_VELOCITY)
		{
			physics.setYVelocity(physics.velocity.y + acceleration * deltaTime);
		}
		else
		{
			physics.setYVelocity(MAX_DIRECTIONAL_VELOCITY);
		}
	}
	else if (input.heldUp())
	{
		if (physics.velocity.y > -MAX_DIRECTIONAL_VELOCITY)
		{
			physics.setYVelocity(physics.velocity.y - acceleration * deltaTime);
		}
		else
		{
			physics.setYVelocity(-MAX_DIRECTIONAL_VELOCITY);
		}
	}
	if (input.heldLeft())
	{
		if (physics.velocity.x > -MAX_DIRECTIONAL_VELOCITY)
		{
			physics.setXVelocity(physics.velocity.x - acceleration * deltaTime);
		}
		else
		{
			physics.setXVelocity(-MAX_DIRECTIONAL_VELOCITY);
		}
	}
	else if (input.heldRight())
	{
		if (physics.velocity.x < MAX_DIRECTIONAL_VELOCITY)
		{
			physics.setXVelocity(physics.velocity.x + acceleration * deltaTime);
		}
		else
		{
			physics.setXVelocity(MAX_DIRECTIONAL_VELOCITY);
		}
	}
}

void Player::movePlayer(float deltaTime)
{

	updateVelocity(deltaTime);
	setSpriteAngle();

	position += physics.velocity;

	wrapAroundWorld();

}

void Player::initialiseSprite()
{
	if (!texture.loadFromFile(TEXTURES_PLAYER_SHIP))
	{
		std::cout << "Player Sprite not found!" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(127, 127);
}

void Player::setSpriteAngle()
{
	sprite.setRotation((std::atan2(physics.velocity.y, physics.velocity.x)*180/PI));
}
