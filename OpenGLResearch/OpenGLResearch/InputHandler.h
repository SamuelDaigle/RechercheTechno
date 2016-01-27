#pragma once
class InputHandler
{
public:
	void Initialize();
	void Destroy();
	
	bool IsKeyDown(unsigned char _key);

private:
	void OnKeyDown(unsigned char _key);
	void OnKeyUp(unsigned char _key);

	bool keyStates[256];
};

