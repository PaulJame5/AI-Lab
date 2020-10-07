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
