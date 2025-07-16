#include "GameState.h"

#include <cmath>
#include <cstdlib>
#include <vector>

GameState::GameState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
	
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
	}

}

void GameState::Render()
{
}
