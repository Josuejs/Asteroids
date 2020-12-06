#pragma once

#ifndef SHIP_HPP
#define SHIP_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"
#include "GameObject.hpp"

namespace Engine
{
    class Bullet;
    class App;
    class Ship : public GameObject
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
        void Respawn();
        Bullet* Shoot();

    private:
        /* ==========================
        * PRIVATE FUNCTIONS
        * ==========================*/
        void ApplyDrag(Math::Vector2 force);
        /* ==========================
        * MEMBERS
        * ==========================*/
        float m_currentSpeed;
        App* m_parent;
    };
} // namespace Engine
#endif