#pragma once
#include "StateManager.h"
#include "src/entities/Player.h"

class GameState : public StateManager
{
private:
	Player* m_Player;
	
public:
	GameState(Window* window, bool* isAppRunning);
	~GameState();

	void Init() override;
	void Update() override;
	void Render() override;
};

