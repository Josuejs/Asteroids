#pragma once

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

// STL
#include <vector>

#include "Vector2.hpp"

namespace Engine
{
    class Asteroid
    {
        public:
            Asteroid();
            void Render();
        private:
            std::vector<Engine::Math::Vector2> m_points;
    };
} // namespace Engine
#endif