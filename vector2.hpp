#pragma once
#include <iostream>

namespace Engine
{
    namespace Math
    {
        struct Vector2
        {
            /* ==========================
            * STATIC
            * ==========================*/
            static Vector2 Origin;

            /* ==========================
            * CONSTRUCTORS
            * ==========================*/
            Vector2();
            Vector2(float, float);
            Vector2(float);

            /* ==========================
            * FUNCTIONS
            * ==========================*/
            float Length() const;
            float SquaredLength() const;
            float Normalize();

            /* ==========================
            * CONSTRUCTORS
            * ==========================*/
            float x;
            float y;
            float length;
        };
    } // namespace Math
} // namespace Engine