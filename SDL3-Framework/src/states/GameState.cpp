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
	m_Player->AddComponent<Velocity>({0.1f, 0.1f});

	std::cout << m_Player->GetComponent<Transform>()->x << std::endl;
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
