#pragma once

#include "INoise.hpp"
#include "../General.hpp"
#include "../Vector2.hpp"


using namespace cmate::core::mathf;


namespace cmate::core::Noise
{
    class ValueNoise : public cmate::core::Interfaces::INoise
    {
        public:
            ValueNoise(int seed, unsigned int pixel_size, unsigned int noise_size, double log_gen_time = false)
            {
                for (int c = 0; c < pixel_size; c++)
                {
                    for (int p = 0; p < pixel_size; p++)
                    {
                        double noise_x = (c / ((double)pixel_size - 1)) * (double)noise_size;
                        double noise_y = (p / ((double)pixel_size - 1)) * (double)noise_size;

                        Vector2 floored_pos = Vector2(std::floor(noise_x), std::floor(noise_y));

                        Vector2 fract_coords = Vector2(fract(noise_x), fract(noise_y));

                        Vector2 interpolated_vector = Vector2(SmoothStep(0, 1, fract_coords.x), SmoothStep(0, 1, fract_coords.y));

                        double a = hash(floored_pos, seed);
                        double b = hash(floored_pos + V2_RIGHT, seed);
                        double c_ = hash(floored_pos + V2_UP, seed);
                        double d = hash(floored_pos + V2_ONE, seed);

                        double value = std::lerp(std::lerp(a, b, interpolated_vector.x), std::lerp(c_, d, interpolated_vector.x), interpolated_vector.y);

                        this->value_map.push_back(value);       
                    }
                }
                width = pixel_size;
                height = pixel_size;

                if (log_gen_time)
                {
                    LOG("Generation of Value Noise Completed", LFlags::INFO);
                }
            }

            Image GetImage() override
            {
                return Image::ValueMapToImage(value_map, width);
            }
    };
}