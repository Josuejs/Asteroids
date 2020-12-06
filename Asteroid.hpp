#pragma once

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

// Asteroids
#include "Vector2.hpp"
#include "GameObject.hpp"

namespace Engine
{    
    class App;
    class Asteroid : public GameObject
    {                
        public:  
            /* ==========================
            * PUBLIC FUNCTIONS
            * ==========================*/
            Asteroid(App* parent);
            void Update(float deltaTime);
        private:
            /* ==========================
            * MEMBERS
            * ==========================*/            
            App* m_parent;
    };
}

#endif