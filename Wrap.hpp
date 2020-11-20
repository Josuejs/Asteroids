#pragma once

#ifndef _Wrapp_HPP
#define _Wrapp_HPP

namespace Engine
{
     float wrap(float x, float min, float max)
    {
        if (x < min)
            return max - (min - x);
        if (x > max)
            return min + (x - max);
        return x;
    }
}
#endif