#pragma once
#include "StateManager.h"
#include "input/KeyManager.h"
#include "audio/SoundEffect.h"
#include "audio/Music.h"

#include "ui/UIManager.h"
#include "ui/InputBox.h"
#include "input/MouseManager.h"

class GameState : public StateManager
{
private:
	InputBox* m_InputBox;

public:
	GameState(Window* window, bool* isAppRunning);
	~GameState();

	void Init() override;
	void Update() override;
	void Render() override;
};

