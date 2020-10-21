#pragma once

#include "Character.h"
#include "KinematicBehaviour.h"
#include "Player.h"
#include "Enums.h"

class Npc : public Character
{

public:
	Npc();
	Npc(sf::Vector2f position) { this->position = position; };
	Npc(Physics2D physics) { this->physics = physics; };
	Npc(sf::Vector2f position, Physics2D physics)
	{
		this->physics = physics;
		this->position = position;
	};
	~Npc();
	void draw(sf::RenderWindow& window) { window.draw(sprite); window.draw(behaviourNameText);  }
	void update(float deltaTime);

	void setPlayer(Player* player) { this->player = player; }

	void setBehaviourType(KinematicBehaviours myBehaviour);
	void setupTextMessage();
private:
	Player* player;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Font pixelFont;
	sf::Text behaviourNameText;

	KinematicBehaviours myBehaviourType;
	KinematicBehaviour kin = KinematicBehaviour(physics.velocity);

	void initialiseSprite();
	void setSpriteAngle();

	void moveNpc(float deltaTime);
	void setConeOfVisionPosition();

	// cone of vision
	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray triangle{ sf::Triangles,3 };


};