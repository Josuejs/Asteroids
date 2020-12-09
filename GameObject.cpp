#include "GameObject.hpp"
#include "App.hpp"
#include <gl\GL.h>

#include <cstdlib>
#include <cmath>

namespace Engine
{

    inline float wrap(float x, float min, float max)
    {
        if (x < min)
            return max - (min - x);
        if (x > max)
            return min + (x - max);
        return x;
    }

    GameObject::GameObject(float mass, float radius, float angle, float rotation)
        : m_mass(mass), m_radius(radius), m_angle(angle), m_rotation(rotation), m_position(Engine::Math::Vector2::Origin), m_velocity(Engine::Math::Vector2::Origin), m_state(Engine::GameObject::GameObjectState::NORMAL)
    {
    }

    void GameObject::ApplyImpulse(Engine::Math::Vector2 impulse, float angle)
    {
        if (m_mass > 0)
        {
            m_velocity.x += (impulse.x / m_mass) * cosf((angle) * (Engine::Math::Vector2::PI / 180));
            m_velocity.y += (impulse.y / m_mass) * sinf((angle) * (Engine::Math::Vector2::PI / 180));
        }
    }

    void GameObject::Teleport(float _x, float _y)
    {
        m_position.x = _x;
        m_position.y = _y;
    }

    void GameObject::Update(App *world, float deltaTime)
    {
        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        // Calculations for wrap around
        float halfWidth = world->GetWidth() / 2.0f;
        float halfHeight = world->GetHeight() / 2.0f;

        float worldMinX = -halfWidth;
        float worldMaxX = halfWidth;

        float worldMinY = -halfHeight;
        float worldMaxY = halfHeight;

        m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
        m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
    }

    void GameObject::Render()
    {
        //
        DrawCircle(m_position.x, m_position.y, m_radius, 64);

        glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.f);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        std::vector<Engine::Math::Vector2>::iterator it = m_points.begin();
        for (; it != m_points.end(); ++it)
        {
            glVertex2f((*it).x, (*it).y);
        }
        glEnd();
    }

    void GameObject::DrawCircle(float cx, float cy, float r, int num_segments)
    {
        glLoadIdentity();
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int ii = 0; ii < num_segments; ii++)
        {
            float theta = 2.0f * Engine::Math::Vector2::PI * float(ii) / float(num_segments);
            float x = r * cosf(theta);
            float y = r * sinf(theta);
            glVertex2f(x + cx, y + cy);
        }
        glEnd();
    }

    bool GameObject::DetectCollision(GameObject *object)
    {
        float radii = m_radius + object->m_radius;
        //radii ^ 2 >= (x0 - x1) ^ 2 + (y0 - y1) ^ 2)

        float xdiff = m_position.x - object->m_position.x;
        float ydiff = m_position.y - object->m_position.y;

        float squaredDistance = (xdiff * xdiff) + (ydiff * ydiff);

        bool collision = (radii * radii) >= squaredDistance;

        if (collision)
        {
            m_state = GameObject::GameObjectState::COLLIDED;
            object->m_state = GameObject::GameObjectState::COLLIDED;
        }

        return collision;
    }
} // namespace Engine