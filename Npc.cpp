#include "Npc.h"

Npc::Npc()
{
	sprite.setFillColor(sf::Color::Red);
	sprite.setRadius(5);
	sprite.setPosition(sf::Vector2f(100, 100));
}

Npc::~Npc()
{
}

void Npc::update(float deltaTime)
{
	moveNpc(deltaTime);

	sprite.setPosition(position);
	std::cout << "Pos X: " << position.x << std::endl;
	std::cout << "Pos Y: " << position.y << std::endl;
}

void Npc::moveNpc(float deltaTime)
{
	position.x += physics.getVelocity().x * deltaTime;
	position.y += physics.getVelocity().y * deltaTime;

	wrapAroundWorld();
}
