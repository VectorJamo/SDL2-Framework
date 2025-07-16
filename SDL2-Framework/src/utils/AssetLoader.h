#pragma once
#include <SDL.h>
#include <SDL_image.h>

class AssetLoader
{
private:
	static SDL_Renderer* m_Renderer;

public:

	static void InitializeAssetLoader(SDL_Renderer* renderer);
	static SDL_Texture* LoadTexture(const char* path);
};

