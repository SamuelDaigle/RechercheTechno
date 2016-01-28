#include "InputHandler.h"
#include <windows.h>

void InputHandler::Initialize()
{
}

void InputHandler::Destroy()
{
	
}

bool InputHandler::IsKeyDown(unsigned char _key)
{
	return ::GetAsyncKeyState(_key);
}

void InputHandler::OnKeyDown(unsigned char _key)
{

}

void InputHandler::OnKeyUp(unsigned char _key)
{

}