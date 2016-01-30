#include "InputHandler.h"

void InputHandler::Initialize()
{
	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
	}
}

void InputHandler::Destroy()
{
	
}

void InputHandler::LateUpdate()
{
	previousCursorPosition = cursorPosition;
}

bool InputHandler::IsKeyDown(unsigned char _key)
{
	return keyStates[_key];
}

vec2 InputHandler::GetCursorPosition()
{
	return cursorPosition;
}

vec2 InputHandler::GetCursorDelta()
{
	return cursorPosition - previousCursorPosition;
}

void InputHandler::OnKeyDown(unsigned char _key)
{
	keyStates[_key] = true;
}

void InputHandler::OnKeyUp(unsigned char _key)
{
	keyStates[_key] = false;
}

void InputHandler::OnMouseMove(int _x, int _y)
{
	previousCursorPosition = cursorPosition;
	cursorPosition = vec2(_x, _y);
	if (previousCursorPosition.x == 0 && previousCursorPosition.y == 0)
	{
		LateUpdate();
	}
}