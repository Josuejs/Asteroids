#include "App.hpp"
#include <algorithm>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

//
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"

namespace Engine
{	
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;	

	App::App(const std::string& title, const int width, const int height)
		: m_title(title)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new TimeManager)
		, m_mainWindow(nullptr)
	{
		m_state = GameState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();

		m_ship = new Engine::Ship(this);
		m_asteroid = new Engine::Asteroid(this);
		
	}

	App::~App()
	{
		CleanupSDL();

        // Removes timer allocation
        delete m_timer;

		// Removes ship allocation
		delete m_ship;

		// Remove Asteroids
		delete m_asteroid;

	}

	void App::Execute()
	{
		if (m_state != GameState::INIT_SUCCESSFUL)
		{
			SDL_Log("Game INIT was not successful.");
			return;
		}

		m_state = GameState::RUNNING;

		SDL_Event event;
		while (m_state == GameState::RUNNING)
		{
			// Input polling
			//
			while (SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}

			//
			Update();
			Render();
		}
	}

	bool App::Init()
	{
		// Init the external dependencies
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = GameState::INIT_FAILED;
			SDL_Log("Game INIT failed.");
			return false;
		}

		// Setup the viewport
		SetupViewPort();

		// Change game state
		m_state = GameState::INIT_SUCCESSFUL;

		return true;
	}

	void App::CreateBullet()
	{
		Engine::Bullet* pBullet = m_ship->Shoot();		
		m_objects.push_back(pBullet);
		m_bullets.push_back(pBullet);
	}

	void App::CleanGameObjects()
	{
		auto iter = std::find_if(m_objects.begin(), m_objects.end(),
			[&](Engine::GameObject* entity) { return entity->IsDisappearing(); });
		
		if(iter != m_objects.end())
		{
			// Destroy it!
			SDL_Log("Bullet should be deleted!");
			DestroyGameObject(*iter);
		}
	}	

	void App::DestroyGameObject(Engine::GameObject* object)
	{
		if(!object) return;

		// Search for game object in our collections
		auto gameObjectResult = std::find(m_objects.begin(), m_objects.end(), object);
		auto bulletResult = std::find(m_bullets.begin(), m_bullets.end(), object);

		// Remove allocation from memory
		delete object;

		// Remove element from game objects list
		if(m_objects.size() > 0 && gameObjectResult != m_objects.end())
		{
			m_objects.erase(gameObjectResult);
		}

		// Remove element from bullets list
		if(m_bullets.size() > 0 && bulletResult != m_bullets.end())
		{
			m_bullets.erase(bulletResult);
		}
	}


	void App::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
    {
        const float MOVE_UNIT = 15.f;
        switch (keyBoardEvent.keysym.scancode)
        {
        case SDL_SCANCODE_W:
            SDL_Log("Going up");    
            m_ship->MoveUp();    
            break;
        case SDL_SCANCODE_A:
            SDL_Log("Going left");
            m_ship->RotateLeft(DESIRED_FRAME_TIME);
            break;
        case SDL_SCANCODE_S:            
            break;
        case SDL_SCANCODE_D:
            SDL_Log("Going right");
            m_ship->RotateRight(DESIRED_FRAME_TIME);
            break;
        case SDL_SCANCODE_M:
            m_ship->ChangeShip();
            break;
        case SDL_SCANCODE_P:
            m_ship->Respawn();
            break;
		case SDL_SCANCODE_SPACE:
			SDL_Log("Shooting!");
			CreateBullet();
			break;
        default:
            SDL_Log("%S was pressed.", keyBoardEvent.keysym.scancode);
            break;
        }
    }

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		default:
			//DO NOTHING
			break;
		}
	}

	void App::Update()
	{
		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		m_ship->Update(DESIRED_FRAME_TIME);
		m_asteroid->Update(DESIRED_FRAME_TIME);

		std::list< Engine::Bullet* >::iterator ait = m_bullets.begin();
		while(ait != m_bullets.end())
		{
			(*ait)->Update(DESIRED_FRAME_TIME);
			++ait;
		}

		CleanGameObjects();

		double endTime = m_timer->GetElapsedTimeInSeconds();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		while (endTime < nextTimeFrame)
		{
			// Spin lock
			endTime = m_timer->GetElapsedTimeInSeconds();
		}

		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();

		m_nUpdates++;
	}

	void App::Render()
	{
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Render code goes here
		m_ship->Render();
		m_asteroid->Render();

		std::list< Engine::Bullet* >::iterator bull = m_bullets.begin();
		while(bull != m_bullets.end())
		{
			(*bull)->Render();
			++bull;
		}	
		
		SDL_GL_SwapWindow(m_mainWindow);
	}

	bool App::SDLInit()
	{
		// Initialize SDL's Video subsystem
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			SDL_Log("Failed to init SDL");
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags =  SDL_WINDOW_OPENGL     | 
						SDL_WINDOW_SHOWN      | 
						SDL_WINDOW_RESIZABLE;

		m_mainWindow = SDL_CreateWindow(
			m_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			flags
		);

		if (!m_mainWindow)
		{
			SDL_Log("Failed to create window!");
			SDL_Quit();
			return false;
		}

		m_context = SDL_GL_CreateContext(m_mainWindow);
		SDL_GL_MakeCurrent(m_mainWindow, m_context);

		// Make double buffer interval synced with vertical scanline refresh
		SDL_GL_SetSwapInterval(0);

		return true;
	}

	
	void App::SetupViewPort()
	{
		// Defining ortho values
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;

		// Set viewport to match window
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

		// Setting Mode to GL_MODELVIEW
		glMatrixMode(GL_MODELVIEW);
	}

	bool App::GlewInit()
	{
	 	return true;
	}

	void App::CleanupSDL()
	{
		// Cleanup
		//
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void App::OnResize(int width, int height)
	{
		// TODO: Add resize functionality
		//
		m_width = width;
		m_height = height;

		SetupViewPort();
	}

	void App::OnExit()
	{
		// Exit main for loop
		//
		m_state = GameState::QUIT;

		// Cleanup SDL pointers
		//
		CleanupSDL();
	}
}