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

sf::Vector2f KinematicBehaviour::seek(sf::Vector2f target, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(target - *position) * maxAcceleration;
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 25 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration);

	return velocity;
}
sf::Vector2f KinematicBehaviour::flee(sf::Vector2f target, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(*position - target) * maxAcceleration;
	sf::Vector2f steering = desiredVelocity - velocity;

	steering = truncate(steering, 25 * deltaTime);
	velocity = truncate(velocity + steering, maxAcceleration);

	return velocity;
}


sf::Vector2f KinematicBehaviour::arrival(sf::Vector2f target, float deltaTime)
{

	sf::Vector2f desiredVelocity = normalise(target - *position) * maxAcceleration;

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

float KinematicBehaviour::magnitude(sf::Vector2f vector)
{
	return (std::sqrtf(vector.x * vector.x + vector.y * vector.y));
}

void KinematicBehaviour::setWanderAngle(sf::Vector2f& displacement, float angle)
{
	
		float len  = std::sqrtf((displacement.x * displacement.x) + (displacement.y * displacement.y));
		displacement.x = std::cos(angle) * len;
		displacement.y = std::sin(angle) * len;
	
}
