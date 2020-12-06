#define VERSION

#include "App.hpp"

// C++ STL
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <SDL2\SDL.h>

const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char ** argv)
{

	// Game Version
	const std::string version("v0.4.0");
	const char* data = version.data();
	std::cout << "Game Version: " << version.data() << std::endl;

	// Create Game Object
	Engine::App* app = new Engine::App("Asteroids", WIDTH, HEIGHT);	

	// Initialize game
	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}	

	// Execute game
	app->Execute();

	// Delete game object
	delete app;

	return 0;
}