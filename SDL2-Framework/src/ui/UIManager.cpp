#include "UIManager.h"

#include <iostream>

bool UIManager::InitializeUI()
{
    if (TTF_Init() != 0)
    {
        std::cout << "Failed to initialize SDL_ttf!" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}
