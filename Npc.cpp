#include "Npc.h"

Npc::Npc()
{
	initialiseSprite();
	position = sf::Vector2f(100, 100);
	sprite.setPosition(position);
}

Npc::~Npc()
{
}

void Npc::update(float deltaTime)
{
	moveNpc(deltaTime);

	sprite.setPosition(position);
}

void Npc::initialiseSprite()
{
	if (!texture.loadFromFile(TEXTURES_ALIEN_SHIP))
	{
		std::cout << "Alien Sprite not found!" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(127, 127);
}

void Npc::moveNpc(float deltaTime)
{
	position.x += physics.getVelocity().x * deltaTime;
	position.y += physics.getVelocity().y * deltaTime;

	wrapAroundWorld();
}
