#include "AssetLoader.h"
#include <iostream>

SDL_Renderer* AssetLoader::m_Renderer;

void AssetLoader::InitializeAssetLoader(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

SDL_Texture* AssetLoader::LoadTexture(const char* path)
{
    SDL_Surface* surface = IMG_Load(path);
    if (surface == nullptr)
    {
        std::cout << "|Asset Loader Error|: Failed to load texture!" << std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}
