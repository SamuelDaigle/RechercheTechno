#include "InputHandler.h"

void InputHandler::Initialize()
{
}

void InputHandler::Destroy()
{
	
}

bool InputHandler::IsKeyDown(unsigned char _key)
{
	return keyStates[_key];
}

void InputHandler::OnKeyDown(unsigned char _key)
{
	keyStates[_key] = true;
}

void InputHandler::OnKeyUp(unsigned char _key)
{
	keyStates[_key] = false;
}