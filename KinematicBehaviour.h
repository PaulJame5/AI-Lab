#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Constants.h"
#include <cmath>


class KinematicBehaviour
{
public:
	KinematicBehaviour(sf::Vector2f& velocity) : velocity(velocity) { };
	~KinematicBehaviour() {};

	sf::Vector2f wander(float deltaTime);
	float randomNumber(float Min, float Max);
	sf::Vector2f seek(sf::Vector2f target, float deltaTime);
	sf::Vector2f flee(sf::Vector2f target, float deltaTime);
	sf::Vector2f arrival(sf::Vector2f target, float deltaTime);
	void arrive();
	void setPosition(sf::Vector2f* position) { this->position = position; }
private:
	sf::Vector2f normalise(sf::Vector2f vector);
	sf::Vector2f truncate(sf::Vector2f vector, float maxForce);
	float angleBetween(sf::Vector2f vector1, sf::Vector2f vector2);
	float magnitude(sf::Vector2f vector);
	void setWanderAngle(sf::Vector2f& displacement, float angle);
	float wanderOffset = 10;
	float wanderRadius = 10;
	float wanderRate = 10;
	float wanderOrientation = 0;
	float wanderAngle = 0;
	float maxAcceleration = 90.6f;

	sf::Vector2f& velocity;
	sf::Vector2f* position;

	float wait = 1.5f;
	float lastDirectionShift = 0;
	sf::Clock clock;
};