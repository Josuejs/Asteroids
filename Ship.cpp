#include "Ship.hpp"
#include "App.hpp"
#include "vector2.hpp"
#include "Bullet.hpp"
#include "GameObject.hpp"
#include "Asteroid.hpp"

#include <gl\GL.h>
#include <SDL2\SDL.h>

// STL
#include <iostream>
#include <cmath>

namespace Engine
{
    // TODO: RR: Move this to a lib
    const float MAX_VELOCITY = 125.0f;
    const float THRUST = 10.0f;
    const float DRAG_FORCE = 0.999f;
    const float ANGLE_OFFSET = 90.0f;
    const float BULLET_SPEED = 250;
    const float RADIUS = 10.0f;

    Ship::Ship(App *parent)
		: GameObject(1.0f, RADIUS, 0.0f, 250.0f), m_parent(parent) // TODO: RR: Contemplate using a component based design approach
	{
		std::cout << "Construction of ship\n";
		ChangeShip();
	}
   
    Ship::Ship(App *parent, float _x, float _y)
		: GameObject(1.0f, RADIUS, 0.0f, 250.0f), m_parent(parent)
	{
		m_position = Math::Vector2(_x, _y);
		std::cout << "Construction of ship\n";
		ChangeShip();
	}

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::MoveUp()
    {
        ApplyImpulse(Math::Vector2(THRUST), m_angle + ANGLE_OFFSET);
    }

    void Ship::RotateLeft( float deltaTime )
    {        
        m_angle += m_rotation * deltaTime;
    }

    void Ship::RotateRight( float deltaTime )
    {        
        m_angle -= m_rotation * deltaTime;
    }

    void Ship::ApplyDrag(Math::Vector2 force)
    {
        m_velocity.x *= force.x;
        m_velocity.y *= force.y;
    }

    void Ship::Update(float deltaTime)
    {
        // Calculate speed
        float speed = 
            std::fabs(m_velocity.Length());

        // Cap speed
        if(speed > MAX_VELOCITY)
        {
            m_velocity.x = (m_velocity.x / speed) * MAX_VELOCITY;
            m_velocity.y = (m_velocity.y / speed) * MAX_VELOCITY;
        }

        // Set new state
        m_currentSpeed = speed;
        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        // Applies drag
        ApplyDrag(Math::Vector2(DRAG_FORCE));
        GameObject::Update(m_parent, deltaTime);
        
    }

    void Ship::ChangeShip()
    {
        int m_currentShip;
    
        m_currentShip = ++m_currentShip % 2;

		m_points.clear();

       

		switch (m_currentShip)
		{
              
        case 1:

                    // Default Ship //
        m_points.push_back(Math::Vector2(4.0, 23.0));
        m_points.push_back(Math::Vector2(6.0, 17.0));
        m_points.push_back(Math::Vector2(2.0, 11.0));
        m_points.push_back(Math::Vector2(-2.0, 11.0));
        m_points.push_back(Math::Vector2(-5.96, 17.17));
        m_points.push_back(Math::Vector2(-4.0, 23.0));


        // Ship part #2
        m_points.push_back(Math::Vector2(-8.0, 19.0));
        m_points.push_back(Math::Vector2(-8.0, 33.0));
        m_points.push_back(Math::Vector2(-4.0, 37.0));
        m_points.push_back(Math::Vector2(-4.0, 23.0));
        m_points.push_back(Math::Vector2(-3.0, 24.0));
        m_points.push_back(Math::Vector2(-1.0, 25.0));
        m_points.push_back(Math::Vector2(0.0, 25.35));
        m_points.push_back(Math::Vector2(1.0, 25.0));
        m_points.push_back(Math::Vector2(3.0, 24.0));
        m_points.push_back(Math::Vector2(4.0, 23.0));
        m_points.push_back(Math::Vector2(4.0, 37.0));
        m_points.push_back(Math::Vector2(8.0, 33.0));
        m_points.push_back(Math::Vector2(8.0, 19.0));
        m_points.push_back(Math::Vector2(13.0, 13.0));
        m_points.push_back(Math::Vector2(24.0, 9.0));
        m_points.push_back(Math::Vector2(24.0, 4.0));
        m_points.push_back(Math::Vector2(6.0, 4.0));
        m_points.push_back(Math::Vector2(3.0, -2.0));
        m_points.push_back(Math::Vector2(0.0, -3.0));
        m_points.push_back(Math::Vector2(-3.0, -2.0));
        m_points.push_back(Math::Vector2(-6.0, 4.0));
        m_points.push_back(Math::Vector2(-24.0, 4.0));
        m_points.push_back(Math::Vector2(-24.0, 9.0));
        m_points.push_back(Math::Vector2(-13.0, 13.0));
        m_points.push_back(Math::Vector2(-8.0, 19.0));
        break;

        default:  
        
        m_points.push_back(Math::Vector2(0.0f, 20.0f));
		m_points.push_back(Math::Vector2(12.0f, -10.0f));
		m_points.push_back(Math::Vector2(6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-6.0f, -4.0f));
		m_points.push_back(Math::Vector2(-12.0f, -10.0f));
        
        	break;
		}
	} 

    

    void Ship::Respawn()
    {
        glLoadIdentity();
        m_position.x = 0.0f;
        m_position.y = 0.0f;
        m_velocity.x = 0.0f;
        m_velocity.y = 0.0f;
        m_angle = 0.0f;

        glTranslatef(m_position.x, m_position.y, 0.0);

        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
    }

     Bullet* Ship::Shoot()
    {
        float shootingAngle = m_angle + ANGLE_OFFSET;
        float bulletPx = m_points[0].x * cosf(shootingAngle * (Engine::Math::Vector2::PI / 180));
        float bulletPy = m_points[0].y * sinf(shootingAngle * (Engine::Math::Vector2::PI / 180));

        Bullet* bullet = new Bullet(m_parent);        
        bullet->Teleport(m_position.x + bulletPx, m_position.y + bulletPy);
        bullet->ApplyImpulse(Math::Vector2(m_currentSpeed + BULLET_SPEED), shootingAngle);

        return bullet;
    }
                
} // namespace engine