#include "Tilemap.h"
#include <iostream>
#include <fstream>
#include <string>

Tilemap::Tilemap(const char* filePath)
{
	m_Map = new char* [MapConstants::NumRows];
	for (int i = 0; i < MapConstants::NumRows; i++)
		m_Map[i] = new char[MapConstants::NumCols];

	LoadTilemap(filePath);
}

Tilemap::~Tilemap()
{
	for (int i = 0; i < MapConstants::NumRows; i++)
		delete[] m_Map[i];
}

void Tilemap::Render()
{
}

void Tilemap::LoadTilemap(const char* path)
{
	std::ifstream stream(path);

	std::string line;
	int row = 0, col = 0;
	while (std::getline(stream, line))
	{
		for (char& c : line)
		{
			if (c != ' ')
			{
				m_Map[row][col] = c;
				col++;
			}
		}
		row++;
		col = 0;
	}

	stream.close();
}
