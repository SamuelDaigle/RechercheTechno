/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Dependencies/glm/glm.hpp"

using namespace glm;

class InputHandler
{
public:
	void Initialize();
	void Destroy();
	void LateUpdate();
	
	bool IsKeyDown(unsigned char _key);
	vec2 GetCursorPosition();
	vec2 GetCursorDelta();

	void OnKeyDown(unsigned char _key);
	void OnKeyUp(unsigned char _key);

	void OnMouseMove(int _x, int _y);

	bool keyStates[256];

	vec2 previousCursorPosition;
	vec2 cursorPosition;
	vec2 deltaCursor;
};

