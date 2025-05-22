#pragma once

// Map constants
// TODO: Change as you need
namespace MapConstants {
	inline constexpr int TileWidth = 32;
	inline constexpr int TileHeight = 32;
	inline constexpr int NumRows = 22;
	inline constexpr int NumCols = 15;
}

namespace WindowConstants {
	inline constexpr int ViewportWidth = MapConstants::NumCols * MapConstants::TileWidth;
	inline constexpr int ViewportHeight = MapConstants::NumRows * MapConstants::TileHeight;
}