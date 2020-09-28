#include <string>
#include <iomanip>
#include <iostream>

class Car
{
public:
    /*
     * CONST
     */
    Car(std::string car_make, int max_speed) : m_speed(max_speed),
                                               m_make(car_make)
    {
        // Max speed must be positive, otherwise time defaults to -1
        if (max_speed > 0)
        {
            m_time = 5 + ((1 / (float)max_speed) * 100);
        }
        else
        {
            m_time = -1;
        }
    }

    /*
     * FUNCTIONS
     */
    
    // Returns how fast you can drive a car from 0 to 60
    void drive()
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(2); // Read more about this here: https://en.cppreference.com/w/cpp/io/manip/setprecision
        std::cout << "The car make " << m_make << " goes from 0 to 60 in: " << m_time << " seconds. With a max speed of " << m_speed << "km/h" << std::endl;
    }

private:
    float m_time;
    int m_speed;
    std::string m_make;
};