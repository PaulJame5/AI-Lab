#include "Npc.h"

Npc::Npc()
{
	initialiseSprite();
	position = sf::Vector2f(100, 100);
	sprite.setPosition(position);

	pixelFont.loadFromFile(FONTS_PIXEL);
	behaviourNameText.setFont(pixelFont);
	behaviourNameText.setFillColor(sf::Color::Red);
	behaviourNameText.setCharacterSize(30);
	setupTextMessage();

	myBehaviourType = WANDER;
}

Npc::~Npc()
{
}

void Npc::update(float deltaTime)
{
	moveNpc(deltaTime);
	setSpriteAngle();

	sprite.setPosition(position);
	behaviourNameText.setPosition(position);
}

void Npc::setBehaviourType(KinematicBehaviours myBehaviour)
{
	myBehaviourType = myBehaviour;
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

void Npc::setupTextMessage()
{
	switch (myBehaviourType)
	{
	case WANDER:
		behaviourNameText.setString("Wander");
		break;
	case SEEK:
		behaviourNameText.setString("Seek");
		break;
	case FLEE:
		behaviourNameText.setString("Flee");
		break;
	case ARRIVAL:
		behaviourNameText.setString("Arrival");
		break;
	case ARRIVAL_SLOW:
		behaviourNameText.setString("Arrival_Slow");
		break;
	case PERSUE:
		behaviourNameText.setString("Persue");
		break;
	default:
		break;
	}
}

void Npc::setSpriteAngle()
{
	sprite.setRotation((std::atan2(physics.velocity.y, physics.velocity.x) * 180 / PI));
}

void Npc::moveNpc(float deltaTime)
{
	switch (myBehaviourType)
	{
	case WANDER:
		physics.setVelocity(kin.wander(deltaTime));
		break;
	case SEEK:
		physics.setVelocity(kin.seek(player->getPosition(), position, deltaTime));
		break;
	case FLEE:
		physics.setVelocity(kin.flee(player->getPosition(), position, deltaTime));
		break;
	case ARRIVAL:
		physics.setVelocity(kin.arrival(player->getPosition(), position, deltaTime));
		break;
	case ARRIVAL_SLOW:
		physics.setVelocity(kin.arrivalSlow(player->getPosition(), position, deltaTime));
		break;
	case PERSUE:
		physics.setVelocity(kin.pursue(player->getPosition(),player->physics.velocity, position, deltaTime));
		break;
	default:
		break;
	}

	if (kin.fieldOfVision(kin.normalise(physics.velocity), player->getPosition() - position, 22))
	{
		std::cout << "In my sights" << std::endl;
		behaviourNameText.setFillColor(sf::Color::Red);
	}
	else
	{

		behaviourNameText.setFillColor(sf::Color::Blue);
		std::cout << "searching" << std::endl;
	}

	setConeOfVisionPosition();
	position.x += physics.velocity.x * deltaTime;
	position.y += physics.velocity.y * deltaTime;

	wrapAroundWorld();
}

void Npc::setConeOfVisionPosition()
{
	// define the position of the triangle's points
	triangle[0].position = position;
	triangle[1].position = sf::Vector2f(position.x + 100.f, position.y + 100.f);
	triangle[2].position = sf::Vector2f(position.x - 100.f, position.y + 100.f);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;
}
