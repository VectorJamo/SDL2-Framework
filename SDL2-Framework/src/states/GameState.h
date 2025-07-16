#pragma once
#include "StateManager.h"
#include "input/KeyManager.h"
#include "audio/SoundEffect.h"
#include "audio/Music.h"

class GameState : public StateManager
{
private:
	
public:
	GameState(Window* window, bool* isAppRunning);
	~GameState();

	void Init() override;
	void Update() override;
	void Render() override;
};

