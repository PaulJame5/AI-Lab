#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Constants.h"
#include <cmath>
#include "Character.h"


class KinematicBehaviour
{
public:
	KinematicBehaviour(sf::Vector2f& velocity) : velocity(velocity) { };
	~KinematicBehaviour() {};

	sf::Vector2f wander(float deltaTime);
	float randomNumber(float Min, float Max);
	sf::Vector2f seek(sf::Vector2f target, sf::Vector2f position, float deltaTime);
	sf::Vector2f pursue(sf::Vector2f target, sf::Vector2f targetVelocity, sf::Vector2f position, float deltaTime);
	sf::Vector2f flee(sf::Vector2f target, sf::Vector2f position, float deltaTime);
	sf::Vector2f arrival(sf::Vector2f target, sf::Vector2f position, float deltaTime);
	sf::Vector2f arrivalSlow(sf::Vector2f target, sf::Vector2f position, float deltaTime);
	void arrive();

	// Need to be sent to a vector class
	bool isCollisionDetected(Character& character1, Character& character2, float angle, float collisionDistance);
	sf::Vector2f normalise(sf::Vector2f vector);
	sf::Vector2f truncate(sf::Vector2f vector, float maxForce);
	float angleBetween(sf::Vector2f vector1, sf::Vector2f vector2);
	float dot(sf::Vector2f lhs, sf::Vector2f rhs);
	float magnitude(sf::Vector2f vector);

	bool fieldOfVision(sf::Vector2f facingDirection, sf::Vector2f toOther, float viewAngle);
	bool fieldOfVision(sf::Vector2f facingDirection, sf::Vector2f toOther, float viewAngle, float maxDistance);
private:
	void setWanderAngle(sf::Vector2f& displacement, float angle);
	float wanderOffset = 10;
	float wanderRadius = 10;
	float wanderRate = 10;
	float wanderOrientation = 0;
	float wanderAngle = 0;
	float maxAcceleration = 90.6f;

	sf::Vector2f& velocity;

	float wait = 1.5f;
	float lastDirectionShift = 0;
	sf::Clock clock;
};