#include "Ship.hpp"

#include <gl\GL.h>
#include <iostream>

namespace Engine
{
    inline float wrap(float x, float min, float max)
    {
        if(x < min) return max - (min - x);
        if(x > max) return min + (x - max);
        return x;
    }

    Ship::Ship()
        : m_position(Math::Vector2::Origin)
    {
        std::cout << "Construction of ship\n";
    }

    Ship::Ship(float _x, float _y)
        : m_position(_x, _y)
    {
        std::cout << "Construction of ship\n";
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::Move(float _x, float _y)
    {
        float x = m_position.x + _x;
        float y = m_position.y + _y;

        // TODO: RR: Move this OUT!
        float width = 1136.0f;
        float height = 640.0f;

        float min_width = -width / 2.0f;
        float max_width = width / 2.0f;

        float min_height = -height / 2.0f;
        float max_height = height / 2.0f;

        m_position.x = wrap(x, min_width, max_width);
        m_position.y = wrap(y, min_height, max_height);
    }

     void Ship::Render() 
     {
                        
            glLoadIdentity();

            glTranslatef(m_position.x, m_position.y, 0.0);

                        // ship part #1   
                        glBegin(GL_LINE_LOOP);
                            glVertex2f(20.0, 4.0);
                            glVertex2f(19.0, 2.0);
                            glVertex2f(17.0, 2.0);
                            glVertex2f(16.0, 4.0);		
                        glEnd(); 

                        // ship part #2   
                        glBegin(GL_LINE_LOOP);
                            glVertex2f(-16.0, 4.0);
                            glVertex2f(-17.0, 2.0);
                            glVertex2f(-19.0, 2.0);
                            glVertex2f(-20.0, 4.0);		
                        glEnd(); 

                        // ship part #3
                        glBegin(GL_LINE_LOOP);
                            glVertex2f(4.0, 23.0);
                            glVertex2f(6.0, 17.0);
                            glVertex2f(2.0, 11.0);
                            glVertex2f(-2.0, 11.0);
                            glVertex2f(-5.96, 17.17);
                            glVertex2f(-4.0, 23.0);		
                        glEnd(); 
                        
                        // ship part #4   
                        glBegin(GL_LINE_LOOP);
                            glVertex2f(6.0, 4.0);
                            glVertex2f(-6.0, 4.0);		
                        glEnd(); 

                            // Ship // 
                        glBegin(GL_LINE_LOOP);
                            glVertex2f(-8.0, 19.0);
                            glVertex2f( -8.0, 33.0);
                            glVertex2f( -4.0, 37.0);
                            glVertex2f( -4.0, 23.0);
                            glVertex2f( -3.0, 24.0);
                            glVertex2f(-1.0, 25.0);
                            glVertex2f( 0.0, 25.35);
                            glVertex2f( 1.0, 25.0);
                            glVertex2f( 3.0, 24.0);
                            glVertex2f( 4.0, 23.0);
                            glVertex2f( 4.0, 37.0);
                            glVertex2f( 8.0, 33.0);
                            glVertex2f( 8.0, 19.0);
                            glVertex2f( 13.0, 13.0);
                            glVertex2f( 24.0, 9.0);
                            glVertex2f( 24.0, 4.0);
                            glVertex2f( 6.0, 4.0);
                            glVertex2f( 3.0, -2.0);
                            glVertex2f( 0.0, -3.0);
                            glVertex2f( -3.0, -2.0);
                            glVertex2f( -6.0, 4.0);
                            glVertex2f( -24.0, 4.0);
                            glVertex2f( -24.0, 9.0);
                            glVertex2f( -13.0, 13.0);
                            glVertex2f( -8.0, 19.0);
                        glEnd();

                        
                }
            
} // namespace engine