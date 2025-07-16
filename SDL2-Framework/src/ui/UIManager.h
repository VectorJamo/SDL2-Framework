#pragma once

#include <SDL_ttf.h>
#include <vector>
#include <iostream>

class Button;

class UIManager
{
private:
	static std::vector<Button*> m_TrackedButtons;

public:
	static bool InitializeUI();
	static void UpdateUI();

	static void AddButton(Button* button);
	static void ClearButtons();
};

