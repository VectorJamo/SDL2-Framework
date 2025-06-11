#include "UIManager.h"

#include <iostream>

bool UIManager::InitializeUI()
{
    if (!TTF_Init())
    {
        std::cout << "Failed to initialize SDL_ttf!" << std::endl;
        return false;
    }
    return true;
}
