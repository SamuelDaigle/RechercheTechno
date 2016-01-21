#pragma once
class Window
{
public:
	Window();
	~Window();

	void Update();
	void Display();
	void Reshape();

private:
	void manageInput();
};

