#include "Player.h"

Player::Player()
{
	sprite.setFillColor(sf::Color::Red);
	sprite.setRadius(5);
	sprite.setPosition(sf::Vector2f(10, 10));
}

Player::~Player()
{
}
