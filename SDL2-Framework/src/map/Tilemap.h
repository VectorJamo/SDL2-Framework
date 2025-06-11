#pragma once
#include "MapConstants.h"
class Tilemap
{
private:
	char** m_Map;

public:
	Tilemap(const char* filePath);
	~Tilemap();

	void Render();

	inline char** GetMap() { return m_Map; }

private:
	void LoadTilemap(const char* path);
};

