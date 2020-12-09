#include "Bullet.hpp"
#include <gl\GL.h>

#include <iostream>

#include "App.hpp"

#include <iostream>

namespace Engine
{
    Bullet::Bullet(App *parent)
        : GameObject(1.0f, 1.0f, 0.0f, 0.0f), m_parent(parent), m_lifeSpan(120.0f), m_currentLifeSpan(0.0f)
    {
    }

    void Bullet::Update(float deltaTime)
    {
        if(m_currentLifeSpan < m_lifeSpan)
        {
            m_currentLifeSpan++;
        }
        else
        {
            m_state = GameObjectState::State::DELETED;
        }
        
        GameObject::Update(m_parent, deltaTime);
    }

    void Bullet::Render()
    {
        glLoadIdentity();
        glPointSize(2.0f);
        glEnable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);
            glVertex2f(m_position.x, m_position.y);
        glEnd();
    }
}