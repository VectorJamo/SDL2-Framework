#include "Application.h"

#include <SDL.h>

int main(int argc, char** argv)
{
	Application app(800, 600, "SDL2 Framework");
	app.Run();

	return 0;
}