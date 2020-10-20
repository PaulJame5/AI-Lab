#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Physics2D.h"
#include "Constants.h"

class Character
{
public:
	Character();
	virtual ~Character();

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(float deltaTime) = 0;

	Physics2D physics;
	sf::Vector2f getPosition() { return position; }
protected:
	void wrapAroundWorld();
	sf::Vector2f position = sf::Vector2f{ 0, 0 };

private:
};