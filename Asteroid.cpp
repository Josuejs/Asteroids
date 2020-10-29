#include "Asteroid.hpp"


#include <SDL2/SDL_opengl.h>
#include <gl\GL.h>
#include <cmath>
#include <cstdlib>

namespace Engine
{
    const size_t NUM_POINTS = 16;
    const float MIN_SIZE = 25.0f;
    const float MAX_SIZE = 45.0f;

    // Move this out to a Math 
    const float PI = 3.141592653;

    Asteroid::Asteroid()
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
    }

    void Asteroid::Render()
    {
        glLoadIdentity();

        glTranslatef(0.f, 0.f, 0.f);

        glBegin(GL_LINE_LOOP);
        std::vector<Engine::Math::Vector2>::iterator it = m_points.begin();
        for(; it != m_points.end(); ++it)
        {
            glVertex2f((*it).x, (*it).y);
        }
        glEnd();
    }
}