#pragma once

#ifndef APP_HPP
#define APP_HPP

// C++ STL
#include <string>
#include <list>

//
#include "SDLEvent.hpp"
#include "TimeManager.hpp"
#include "Asteroid.hpp"

namespace Engine
{
    class GameObject;
    class Ship;
    class Asteroid;
    class Bullet;
    class App : public SDLEvent
    {
    public:
        /* =============================================================
            * ENUMERATORS
            * ============================================================= */
        struct GameState
        {
            enum State
            {
                UNINITIALIZED = 0,
                INIT_FAILED = 1,
                INIT_SUCCESSFUL = 2,
                RUNNING = 4,
                PAUSED = 8,
                QUIT = 16
            };
        };

        /* =============================================================
            * CONSTRUCTORS/DESTRUCTORS
            * ============================================================= */
        App(const std::string &title, const int width, const int height);
        ~App();

        /* =============================================================
            * PUBLIC FUNCTIONS
            * ============================================================= */
        void Execute();
        bool Init();
        void Update();
        void Render();
        int GetWidth() { return m_width; }
        int GetHeight() { return m_height; }

    private:
        /* =============================================================
            * PRIVATE FUNCTIONS
            * ============================================================= */
        bool SDLInit();
        bool GlewInit();
        void SetupViewPort();
        void CleanupSDL();
        void OnResize(int width, int height) override;
        void OnExit() override;
        void OnKeyDown(SDL_KeyboardEvent keyBoardEvent) override;
        void OnKeyUp(SDL_KeyboardEvent keyBoardEvent) override;
        void UpdateScore(int delta);

        /*=========================================================================
        *           GAME FUNCTIONS  
        * ========================================================================*/

        void CleanGameObjects();
        void CreateBullet();
        void CreateAsteroid(Engine::Asteroid::AsteroidSize::Size size, int amount, float x, float y);
        void CreateDebris(Engine::Asteroid *object);
        void CheckCollision();
        void DestroyGameObject(Engine::GameObject *object);

        /* =============================================================
            * MEMBERS
            * ============================================================= */
        int m_width;
        int m_height;
        int m_nUpdates;
        double m_lastFrameTime;
        std::string m_title;
        SDL_Window *m_mainWindow;
        SDL_GLContext m_context;
        GameState::State m_state;
        Engine::TimeManager *m_timer;
        Engine::Ship *m_ship;
        Engine::Ship *m_current_Ship;
        std::list<Engine::GameObject *> m_objects;
        std::list<Engine::Bullet *> m_bullets;
        std::list<Engine::Asteroid *> m_asteroids;
        int m_score;
    };
} // namespace Engine

#endif /* APP_HPP */

