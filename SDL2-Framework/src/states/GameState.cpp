#include "GameState.h"

#include <cmath>
#include <cstdlib>
#include <vector>

GameState::GameState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
	m_InputBox = new InputBox(vec2(50.0f, 50.0f), vec2(100.0f, 40.0f), m_Window->GetRenderer());
	UIManager::AddInputBox(m_InputBox);
}

GameState::~GameState()
{
}

void GameState::Init()
{

}

void GameState::Update()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
		{
			*m_IsAppRunning = false;
		}
		
		KeyManager::UpdateKeyState(&ev);
		UIManager::UpdateUI(&ev);
		MouseManager::UpdateMouseState(&ev);
	}
}

void GameState::Render()
{
	m_InputBox->Render(m_Window->GetRenderer());
}
