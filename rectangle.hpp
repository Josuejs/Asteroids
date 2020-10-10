#include <iostream>

// Class: blueprint for creating objects.
// A class defines a rule of state management and behavior of an object.
class Rectangle
{
public:
    // Rectangle constructor and member initialization
    // Read more about it here: https://en.cppreference.com/w/cpp/language/constructor

    /*
     * CONST
     */
    Rectangle(int width, int height) : m_width(width),  // Initialize member m_width
                                       m_height(height) // Initialize member m_height
    {
        std::cout << "Constructor is being executed. Params: " << m_width << " and " << m_height << std::endl;
    }

    /*
     * Functions
     */

    // Calculates the rectangle area
    int area()
    {
        return m_width * m_height;
    }

private:
    int m_width, m_height;
};