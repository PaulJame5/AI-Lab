#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::wrapAroundWorld()
{
	if (position.x < 0.0f)
	{
		position.x = SCREEN_WIDTH - 1.0f;
	}

	if (position.x > SCREEN_WIDTH)
	{
		position.x = 1.0f;
	}

	if (position.y < 0.0f)
	{
		position.y = SCREEN_HEIGHT - 1.0f;
	}

	if (position.y > SCREEN_HEIGHT)
	{
		position.y = 1.0f;
	}
}
