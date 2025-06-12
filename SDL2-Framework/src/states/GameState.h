#pragma once
#include "StateManager.h"
#include "src/input/KeyManager.h"
#include "src/audio/SoundEffect.h"
#include "src/audio/Music.h"

class GameState : public StateManager
{
private:
	SoundEffect* m_PickupSound, *m_LaserSound;
	Music* m_BackgroundMusic;
	
public:
	GameState(Window* window, bool* isAppRunning);
	~GameState();

	void Init() override;
	void Update() override;
	void Render() override;
};

