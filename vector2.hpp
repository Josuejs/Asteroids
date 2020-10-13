#include <iostream>

class Vector2
{
    public:
        Vector2(float _x, float _y) :
            x(_x),
            y(_y)
        {}

        void print()
        {
            std::cout << "(x, y) => " << x << ", " << y << std::endl;
        }

    private:
        float x;
        float y;
};