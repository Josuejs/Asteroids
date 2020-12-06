// Local Libraries
#include "Asteroid.hpp"
#include "App.hpp"
#include "GameObject.hpp"

#include <SDL2/SDL_opengl.h>
#include <gl\GL.h>
#include <cmath>
#include <cstdlib>

namespace Engine
{
    inline float randInRange(float min, float max)
    {
        return min + (max - min) * (rand() / static_cast<float>(RAND_MAX));
    }
        
    const size_t NUM_POINTS = 16;
    const float MIN_SIZE = 25.0f;
    const float MAX_SIZE = 45.0f;
    // Move this out to a Math 
    const float PI = 3.141592653;

    Asteroid::Asteroid(App* parent)
        : GameObject(1.0f, 0.0f, 120.0f)
        , m_parent(parent)
    {
        float sizeFactor = 1;
        float min = MIN_SIZE / sizeFactor;
        float max = MAX_SIZE / sizeFactor;

        for(size_t idx = 0; idx < NUM_POINTS; ++idx)
        {
            const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * PI;
            const float randDist = min + (max - min) * (rand() / static_cast<float>(RAND_MAX));
              m_points.push_back(Engine::Math::Vector2(sinf(radians) * randDist,
                                                       cosf(radians) * randDist));
        }
       
        float x = randInRange(-150.0f, 150.0f);
        float y = randInRange(-150.0f, 150.0f);
        ApplyImpulse(Engine::Math::Vector2(x, y), m_rotation);
    }

    void Asteroid::Update(float deltaTime)
    {
        m_angle += m_rotation * deltaTime;
        GameObject::Update(m_parent, deltaTime);
    }
}