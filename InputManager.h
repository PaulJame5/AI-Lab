#pragma once
#include <SFML/Graphics.hpp>


class InputManager
{
public:
	InputManager();
	~InputManager();

	bool pressedUp();
	bool pressedDown();
	bool pressedLeft();
	bool pressedRight();

	bool heldUp();
	bool heldDown();
	bool heldLeft();
	bool heldRight();

private:

	bool upPressedLastFrame = false;
	bool downPressedLastFrame = false;
	bool leftPressedLastFrame = false;
	bool rightPressedLastFrame = false;

};