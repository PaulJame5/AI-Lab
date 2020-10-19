#pragma once

#include <SFML/Graphics.hpp>


class Physics2D
{

private:
	sf::Vector2f velocity = sf::Vector2f(0,0);
	float gravityScale = 1;

public:
	// Constructors + Overloads
	Physics2D() {};
	Physics2D(float gravityScale) { this->gravityScale = gravityScale; }
	Physics2D(sf::Vector2f velocity) { this->velocity = velocity; }
	Physics2D(float gravityScale, sf::Vector2f velocity) 
	{ 
		this->velocity = velocity; 
		this->gravityScale = gravityScale;
	}
	~Physics2D() {};

	sf::Vector2f getVelocity() { return velocity; }
	void setVelocity(sf::Vector2f velocity) { this->velocity = velocity; }
	void setXVelocity(float x) { this->velocity.x = x; }
	void setYVelocity(float y) { this->velocity.y = y; }
};