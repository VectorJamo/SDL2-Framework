#include "GameState.h"

#include <cmath>
#include <cstdlib>
#include <vector>

GameState::GameState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
	m_PickupSound = new SoundEffect("res/audio/pickupCoin.wav");
	m_LaserSound = new SoundEffect("res/audio/laserShoot.wav");
	m_BackgroundMusic = new Music("res/audio/BossMain.wav");

	
}

GameState::~GameState()
{
	delete m_PickupSound;
	delete m_LaserSound;
	delete m_BackgroundMusic;
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

		if (ev.type == SDL_KEYDOWN)
		{
			if (ev.key.keysym.sym == SDLK_0)
			{

			}
			if (ev.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				m_PickupSound->Play();
			}
			if (ev.key.keysym.scancode == SDL_SCANCODE_G)
			{
				m_LaserSound->PlayLooped(2);
			}
			if (ev.key.keysym.scancode == SDL_SCANCODE_1)
			{
				m_BackgroundMusic->Play(-1);
			}
			if (ev.key.keysym.scancode == SDL_SCANCODE_2)
			{
				m_BackgroundMusic->Pause();
			}
			if (ev.key.keysym.scancode == SDL_SCANCODE_3)
			{
				m_BackgroundMusic->Resume();
			}
			if (ev.key.keysym.scancode == SDL_SCANCODE_4)
			{
				m_BackgroundMusic->Stop();
			}
		}
	}

	if (KeyManager::IsKeyPressed('.'))
	{
		std::cout << "." << std::endl;
	}
}

void GameState::Render()
{
}
