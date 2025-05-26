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
	m_Player = new Player();
	m_Player->AddComponent<Transform>({10, 10, 50, 50});

	if (m_Player->HasComponent<Transform>())
	{
		std::cout << "Yes." << std::endl;
	}
}

void GameState::Update()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_EVENT_QUIT)
		{
			*m_IsAppRunning = false;
		}
	}

}

void GameState::Render()
{
}
