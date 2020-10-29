#pragma once

#ifndef SHIP_HPP
#define SHIP_HPP

#include "Vector2.hpp"

namespace Engine
{
    class Ship
    {
    public:
        /* ==========================
        * CONSTRUCTORS
        * ==========================*/
        Ship();
        Ship(float, float);
        ~Ship();
        /* ==========================
        * PUBLIC FUNCTIONS
        * ==========================*/
        void Move(float, float);
        void Render();
    private:
        /* ==========================
        * MEMBERS
        * ==========================*/
        Engine::Math::Vector2 m_position;
    };
} // namespace Engine
#endif