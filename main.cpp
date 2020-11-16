// C++ STL
#include <iostream>

// 
#include "App.hpp"

const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char ** argv)
{
	// Create Game Object
	//
	Engine::App* app = new Engine::App("Asteroids", WIDTH, HEIGHT);	

	// Initialize game
	//
	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}	

	// Execute game
	//
	app->Execute();

	// Delete game object
	//
	delete app;

	return 0;
}