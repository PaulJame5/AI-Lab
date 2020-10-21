#include "KinematicBehaviour.h"
#include <iostream>

sf::Vector2f KinematicBehaviour::wander(float deltaTime) {

	sf::Vector2f circleCenter = velocity;
	circleCenter = normalise(circleCenter);
	circleCenter = circleCenter * (wanderOffset);

	sf::Vector2f displacement(0, -1);
	displacement = displacement * (wanderRadius);
	if (lastDirectionShift + wait > clock.getElapsedTime().asSeconds())
	{
		setWanderAngle(displacement, wanderAngle);
	}




	wanderAngle += randomNumber(-1.0f, 1.0f) * .2;
	sf::Vector2f wanderForce;
	wanderForce = circleCenter + displacement;
	lastDirectionShift = clock.getElapsedTime().asSeconds();
	return wanderForce * maxAcceleration;
}

float KinematicBehaviour::randomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

sf::Vector2f KinematicBehaviour::seek(sf::Vector2f target, sf::Vector2f position, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(target - position) * maxAcceleration;
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 25 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration);


	return velocity;
}
sf::Vector2f KinematicBehaviour::pursue(sf::Vector2f target, sf::Vector2f targetVelocity, sf::Vector2f position, float deltaTime)
{
	// Aim to be slightly in front of direction target is going
	sf::Vector2f desiredVelocity = (normalise((target + targetVelocity) - position)) * maxAcceleration;
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 25 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration);

	return velocity;
}
sf::Vector2f KinematicBehaviour::flee(sf::Vector2f target, sf::Vector2f position, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(position - target) * maxAcceleration;
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 25 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration);

	return velocity;
}


sf::Vector2f KinematicBehaviour::arrival(sf::Vector2f target, sf::Vector2f position, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(target - position) * maxAcceleration;

	float distance = magnitude(desiredVelocity);

	if (distance < 100)
	{
		// Inside the slowing area
		desiredVelocity = normalise(desiredVelocity) * maxAcceleration * (distance / 100);
	}
	else
	{
		desiredVelocity = normalise(desiredVelocity) * maxAcceleration;
	}
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 25 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration);

	return velocity;
}

sf::Vector2f KinematicBehaviour::arrivalSlow(sf::Vector2f target, sf::Vector2f position, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(target - position) * maxAcceleration;

	float distance = magnitude(desiredVelocity);

	if (distance < 100)
	{
		// Inside the slowing area
		desiredVelocity = normalise(desiredVelocity) * maxAcceleration / 10.0f * (distance / 100);
	}
	else
	{
		desiredVelocity = normalise(desiredVelocity) * maxAcceleration / 10.0f;
	}
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 10 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration / 10.0f);

	return velocity;
}


bool KinematicBehaviour::isCollisionDetected(Character &character1, Character &character2, float angle, float collisionDistance)
{
	return false;
}

sf::Vector2f KinematicBehaviour::normalise(sf::Vector2f vector)
{
	return vector / magnitude(vector);
}

sf::Vector2f KinematicBehaviour::truncate(sf::Vector2f vector, float maxForce)
{
	if (magnitude(vector) > maxForce)
	{
		return normalise(vector) * maxForce;
	}
	return vector;
}

float KinematicBehaviour::angleBetween(sf::Vector2f vector1, sf::Vector2f vector2)
{
	return std::acos((dot(normalise(vector1), normalise(vector2)))) * 57.29578f;
}

float KinematicBehaviour::dot(sf::Vector2f lhs, sf::Vector2f rhs)
{
	return (lhs.x * rhs.x + lhs.y * rhs.y);
}

float KinematicBehaviour::magnitude(sf::Vector2f vector)
{
	return (std::sqrtf(vector.x * vector.x + vector.y * vector.y));
}

bool KinematicBehaviour::fieldOfVision(sf::Vector2f facingDirection, sf::Vector2f toOther, float viewAngle)
{
	if (angleBetween(facingDirection, toOther) < viewAngle)
	{
		return true;
	}
	return false;
}

void KinematicBehaviour::setWanderAngle(sf::Vector2f& displacement, float angle)
{
	
		float len  = std::sqrtf((displacement.x * displacement.x) + (displacement.y * displacement.y));
		displacement.x = std::cos(angle) * len;
		displacement.y = std::sin(angle) * len;
	
}
