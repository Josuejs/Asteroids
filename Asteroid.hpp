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
            * ENUMERATIONS
            * ==========================*/
           struct AsteroidSize
           {
               enum Size
               {
                   BIG = 0,
                   MEDIUM = 1,
                   SMALL = 2
               };
           };
            /* ==========================
            * PUBLIC FUNCTIONS
            * ==========================*/
            Asteroid(AsteroidSize::Size size, App* parent);
            void Update(float deltaTime);
            inline AsteroidSize::Size GetSize() { return m_size; }
        private:
            /* ==========================
            * MEMBERS
            * ==========================*/            
            App*                m_parent;
            AsteroidSize::Size  m_size; 
    };
}

#endif
