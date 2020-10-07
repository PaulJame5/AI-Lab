#pragma once
#include <SFML/Graphics.hpp>

class Character
{
public:
	Character();
	virtual ~Character();
	virtual void* draw(sf::RenderWindow& window) = 0;
};