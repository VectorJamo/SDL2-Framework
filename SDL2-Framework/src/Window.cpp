#include "Window.h"

Window::Window(int width, int height, const char* title)
	:m_Window(nullptr), m_Renderer(nullptr), m_Width(width), m_Height(height), m_Title(title)
{
	m_Window = SDL_CreateWindow(m_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, NULL);
	m_Renderer = SDL_CreateRenderer(m_Window, -1,  NULL);
	// TODO: Check for errors in window or renderer creation
}

Window::~Window()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
}

void Window::Clear(char r, char g, char b, char a)
{
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
	SDL_RenderClear(m_Renderer);
}

void Window::Display()
{
	SDL_RenderPresent(m_Renderer);
}
