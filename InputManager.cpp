#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::pressedUp()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		upPressedLastFrame = false;
		return false;
	}
	if (upPressedLastFrame)
	{
		return false;
	}
	return true;
}

bool InputManager::pressedDown()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		downPressedLastFrame = false;
		return false;
	}
	if (downPressedLastFrame)
	{
		return false;
	}
	return true;
}

bool InputManager::pressedLeft()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		leftPressedLastFrame = false;
		return false;
	}
	if (leftPressedLastFrame)
	{
		return false;
	}
	return true;
}

bool InputManager::pressedRight()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightPressedLastFrame = false;
		return false;
	}
	if (rightPressedLastFrame)
	{
		return false;
	}
	return true;
}

bool InputManager::heldUp()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		upPressedLastFrame = false;
		return false;
	}
	return true;
}

bool InputManager::heldDown()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		downPressedLastFrame = false;
		return false;
	}
	return true;
}

bool InputManager::heldLeft()
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		leftPressedLastFrame = false;
		return false;
	}
	return true;
}

bool InputManager::heldRight()
{
	
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightPressedLastFrame = false;
		return false;
	}
	return true;
}
