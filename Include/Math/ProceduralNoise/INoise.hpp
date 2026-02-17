#pragma once

#include "../../../CMate-Core/Include/CMate-Core.h"
#include "../Vector2.hpp"

#include <vector>
#include <cmath>

namespace cmate::core
{
    class Imager; //Forward decleration of Imager
    class Image; // Forward decleration of Image

    namespace Interfaces {
        class INoise
        {
            public:

                int GetSeed() const
                {
                    return seed;
                }

                virtual Image GetImage() = 0;

            protected:
                int seed;
                unsigned int width;
                unsigned int height;

                std::vector<double> value_map;
        };
    }  

    namespace mathf {

        // Hashing function for White-Value Noise (Slow and CPU Unfriendly)
        inline double hash(Vector2 inputVec, int seed)
        {
           return fract(
                    std::sin(
                        Vector2::dot(inputVec, 
                            Vector2(Random::dRangeS(0, 1000000, seed + inputVec.x * 35281 + inputVec.y * 97246), 
                                    Random::dRangeS(0, 1000000, seed + inputVec.x * 28754 + inputVec.y * 21634)
                                ))* seed));
        }

        // Hashing function for Perlin Noise (No idea whats going on)
        inline Vector2 hash2D(Vector2 inputVec, int seed)
        {
            int x = int(inputVec.x);
            int y = int(inputVec.y);
        
            uint32_t h = seed;

            // Gives huge variation between each coordinate 
            h ^= x * 374761393u; // Bitwise XOR Operation same as h = h ^ x * ..
            h ^= y * 668265263u;

            h = (h ^ (h >> 13)) * 1274126177u;
            double angle = (h & 0xFFFF) / double(0xFFFF) * 2.0 * M_PI; // 0xFFFF = 00000000 00000000 11111111 11111111, so & keeps only 16 bits
            return Vector2(std::cos(angle), std::sin(angle));
        }
    }
}