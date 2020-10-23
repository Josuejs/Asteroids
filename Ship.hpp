#include <iostream>
#pragma once

#ifndef SHIP_HPP
#define SHIP_HPP

namespace Engine
{
    class ship
    {
    public:
        void render();

    protected:
        int m_ship;
    };
} 

#endif