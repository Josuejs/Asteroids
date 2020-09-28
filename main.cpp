#include <iostream>
#include "car.hpp"
#include "rectangle.hpp"

int main(int argc, char ** argv)
{    
    /*
        char 8 bits (1 byte)
        short 
        int 32 bits (4 bytes)
        float
        long
        long long
        bool
        void

        |-------------------------------|
        | (type) (name) = (val) [addr]  |
        | int x = 4; (32 bits)          |
        | int y = 1;                    |        
        |-------------------------------|
    */

    int x, y;
    x = 10;
    y = 20;
    
    std::cout << "An int variable takes " << sizeof(x) << " bytes of memory" << std::endl;
    std::cout << "Rectangle area = " << x * y << std::endl;

    // Object: Instance of a class
    // rect is an instance of Rectangle
    Rectangle rect(x, y);
    Rectangle rect1(200, 100);
    Rectangle rect2(200, 100);
    Rectangle rect3(70, 1);

    // dot operator to access public members from our Rectangle class
    std::cout << "Rectangle area = " << rect.area() << std::endl;
    std::cout << "Rectangle area = " << rect1.area() << std::endl;
    std::cout << "Rectangle area = " << rect2.area() << std::endl;
    std::cout << "Rectangle area = " << rect3.area() << std::endl;

    std::cout << "A Rectangle variable takes " << sizeof(rect) << " bytes of memory" << std::endl;

    // Client code that uses the Car class
    // Object: Instance of a class
    // bmw is an instance of Car
    Car bmw("BMW", 180);
    Car honda("Honda", 220);
    Car renault("Renault", 175);
    Car toyota("Toyota", 0);

    bmw.drive();
    honda.drive();
    renault.drive();
    toyota.drive();

    return 0;
}