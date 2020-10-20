#include "Npc.h"

Npc::Npc()
{
	initialiseSprite();
	position = sf::Vector2f(100, 100);
	sprite.setPosition(position);
	kin.setPosition(&position);
}

Npc::~Npc()
{
}

void Npc::update(float deltaTime)
{
	moveNpc(deltaTime);
	setSpriteAngle();

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

void Npc::setSpriteAngle()
{
	sprite.setRotation((std::atan2(physics.velocity.y, physics.velocity.x) * 180 / PI));
}

void Npc::moveNpc(float deltaTime)
{

	//physics.setVelocity(kin.wander(deltaTime));
	//physics.setVelocity(kin.seek(player->getPosition(), deltaTime));
	//physics.setVelocity(kin.flee(player->getPosition(), deltaTime));
	physics.setVelocity(kin.arrival(player->getPosition(), deltaTime));
	position.x += physics.velocity.x * deltaTime;
	position.y += physics.velocity.y * deltaTime;

	wrapAroundWorld();
}
