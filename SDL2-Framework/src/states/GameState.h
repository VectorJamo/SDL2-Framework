#pragma once
#include "StateManager.h"

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

