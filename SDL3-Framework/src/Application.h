#pragma once
#include "Window.h"

class Application
{
private:
	Window* m_Window;
	bool m_Running;

	unsigned int m_LastTime;

	static constexpr unsigned int m_FPS = 60;

public:
	Application(int width, int height, const char* title);
	~Application();

	void Run();
};
