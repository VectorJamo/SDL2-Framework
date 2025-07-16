#include <SDL.h>
#include "GameConstants.h"
#include "Application.h"

int main(int argc, char** argv)
{
	Application app(WindowDimensions::Width, WindowDimensions::Height, "Space Shooter");
	app.Run();

	return 0;
}