
#include <iostream>
#include "Ship.hpp"
#include <SDL2/SDL_opengl.h>


    
namespace Engine {

     
                void ship::render() 
                {
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
            
} 