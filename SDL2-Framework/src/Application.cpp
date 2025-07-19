#include "Application.h"
#include "states/GameState.h"

#include "audio/SoundManager.h"
#include "utils/AssetLoader.h"

Application::Application(int width, int height, const char* title)
{
	m_Window = new Window(width, height, title);
	m_Running = true;

	if (!UIManager::InitializeUI())
	{
		std::cout << "Failed to initialize UI!" << std::endl;
	}
	if (!SoundManager::InitializeAudio())
	{
		std::cout << "Failed to initialize Audio!" << std::endl;
	}
	AssetLoader::InitializeAssetLoader(m_Window->GetRenderer());

	StateManager::CurrentState = new GameState(m_Window, &m_Running);
	StateManager::CurrentState->Init();
}

Application::~Application()
{
	delete StateManager::CurrentState;
	delete m_Window;
}

void Application::Run()
{
	while (m_Running)
	{
		m_LastTime = SDL_GetTicks();

		m_Window->Clear(0, 0, 0, 255);

		StateManager::CurrentState->Update();
		StateManager::CurrentState->Render();

		m_Window->Display();

		// Frame cap
		unsigned int deltaTime = SDL_GetTicks() - m_LastTime;
		if (deltaTime < (1000 / m_FPS))
		{
			SDL_Delay((1000 / m_FPS) - deltaTime);
		}
	}
}
