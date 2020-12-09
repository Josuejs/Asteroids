#pragma once

#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

// Asteroids
#include "Vector2.hpp"
#include <vector>

namespace Engine
{
    class App;
    class GameObject
    {
    public:
        /* ==========================
            * ENUMERATIONS
            * ==========================*/
        struct GameObjectState
        {
            enum State
            {
                NORMAL = 0,
                COLLIDED = 1,
                DELETED = 2
            };
        };
        /* ==========================
            * PUBLIC FUNCTIONS
            * ==========================*/
        GameObject(float mass, float radius, float angle, float rotation);
        void Update(App *world, float deltaTime);
        void Render();
        void ApplyImpulse(Engine::Math::Vector2 impulse, float angle);
        void Teleport(float _x, float _y);
        bool DetectCollision(GameObject *object);
        inline Engine::Math::Vector2 GetPosition() { return m_position; }
        inline bool CouldCollide() { return m_state == GameObjectState::NORMAL; }
        inline bool IsDisappearing() { return m_state == GameObjectState::DELETED; }
        inline bool IsColliding() { return m_state == GameObjectState::COLLIDED; }
        inline float GetX			( ) { return m_position.x; }
		inline float GetY			( ) { return m_position.y; }
    protected:
        /* ==========================
            * PROTECTED FUNCTIONS
            * ==========================*/
        void DrawCircle(float, float, float, int);
        /* ==========================
            * MEMBERS
            * ==========================*/
        std::vector<Engine::Math::Vector2> m_points;
        Engine::Math::Vector2 m_position;
        Engine::Math::Vector2 m_velocity;
        float m_angle;
        float m_mass;
        float m_rotation;
        float m_radius;
        GameObjectState::State m_state;
    };
} // namespace Engine

#endif