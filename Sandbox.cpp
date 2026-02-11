#include "Include/CMate-GameExtended.h"
#include "CMate-Core/Include/CMate-Core.h"


#include <thread>

using namespace cmate::core;
using namespace cmate::core::mathf;


int main(void)
{
    Noise::WhiteNoise myWhiteNoise(500, 100, true); // Also computed on the CPU but much less work
    Noise::ValueNoise myValueNoise(500, 512, 40, true); // Use carefully, computed on the CPU!!
    Noise::PerlinNoise myPerlinNoise(500, 512, 50, true);
    Noise::VoronoiNoise myVoronoiNoise(500, 512, 20, true);

    LOG("-------------Initialized CMate-GameExpanded-------------", cmate::core::LFlags::INFO);

    myWhiteNoise.SaveAsImage("/home/mate/Projects/Mate-Utils/white_noise.bmp"); // Must be a .bmp file
    myValueNoise.SaveAsImage("/home/mate/Projects/Mate-Utils/value_noise.bmp"); // Must be a .bmp file
    myPerlinNoise.SaveAsImage("/home/mate/Projects/Mate-Utils/perlin_noise.bmp"); // Must be a .bmp file
    myVoronoiNoise.SaveAsImage("/home/mate/Projects/Mate-Utils/voronoi_noise.bmp"); // Must be a .bmp file

    int rand_int = Random::iRange(1, 100);
    int rand_int_seed = Random::iRangeS(1, 100, 412);

    double rand_double = Random::dRange(1, 100);
    double rand_double_seed = Random::dRangeS(1, 100, 412);

    std::string message = std::format("My random int is: {}, with seed {}.", rand_int, rand_int_seed);
    LOG(message, LFlags::INFO);

    message = std::format("My random double is: {}, with seed {}.", rand_double, rand_double_seed);
    LOG(message, LFlags::INFO);
}