#pragma once

#ifndef SHIP_HPP
#define SHIP_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"

namespace Engine
{
    class App;
    class Ship
    {
    public:
        /* ==========================
        * CONSTRUCTORS
        * ==========================*/
        Ship(App* parent);
        Ship(App* parent, float, float);
        ~Ship();
        /* ==========================
        * PUBLIC FUNCTIONS
        * ==========================*/
        void ChangeShip();
        void MoveUp();
        void RotateLeft(float deltaTime);
        void RotateRight(float deltaTime);
        void Update(float deltaTime);
        void Render();

    private:
        /* ==========================
        * PRIVATE FUNCTIONS
        * ==========================*/
        void ApplyImpulse(Math::Vector2 impulse);
        void ApplyDrag(Math::Vector2 force);
        /* ==========================
        * MEMBERS
        * ==========================*/
        std::vector<Engine::Math::Vector2> m_points;
        Engine::Math::Vector2 m_position;
        Engine::Math::Vector2 m_velocity;
        float m_angle;
        float m_mass;
        float m_rotation;
        float m_currentSpeed;
        App* m_parent;
    };
} // namespace Engine
#endif