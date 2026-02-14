#pragma once

#include <cmath>
#include <algorithm>
#include "Vector2.hpp"

#include "../../CMate-Core/Include/CMate-Core.h"

namespace cmate::core::mathf
{
    class Vector2; // Forward Decleration = Compiler knows Vector2 exists, not what it contains

    Vector2 lerp(Vector2 from, Vector2 to, double t);

    //Define Inline Vector based functions 
    Vector2 sin(Vector2 input);
    Vector2 fract(Vector2 input);
}