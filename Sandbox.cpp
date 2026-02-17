#include "Include/CMate-GameExtended.h"

#include <thread>

using namespace cmate::core;
using namespace cmate::core::mathf;


int main(void)
{
    SDManager* sd_manager = &SDManager::Instance();

    SET_LOGS_FOLDER("/home/mate/Projects/CMate-Expanded/logs"); // KEEP AT THE TOP, some internal logs may break

    //Initiating savefile
    sd_manager->SetSaveFile("/home/mate/Projects/CMate-Expanded/Save_File.odt");
    sd_manager->ClearSaveFile();


    Noise::WhiteNoise myWhiteNoise(500, 100, true); // Also computed on the CPU but much less work
    Noise::ValueNoise myValueNoise(500, 512, 40, true); // Use carefully, computed on the CPU!!
    Noise::PerlinNoise myPerlinNoise(500, 512, 10, true);
    Noise::VoronoiNoise myVoronoiNoise(500, 512, 20, true);

    LOG("-------------Initialized CMate-GameExpanded-------------", cmate::core::LFlags::INFO);


    Image white_noise = myWhiteNoise.GetImage();
    Image value_noise = myValueNoise.GetImage();
    Image perlin_noise = myPerlinNoise.GetImage();
    Image voronoi_noise = myVoronoiNoise.GetImage();

    Imager::SaveImage(white_noise, "/home/mate/Projects/CMate-Expanded/white_noise.bmp"); // Must be a .bmp file
    Imager::SaveImage(value_noise, "/home/mate/Projects/CMate-Expanded/value_noise.bmp"); // Must be a .bmp file
    Imager::SaveImage(perlin_noise, "/home/mate/Projects/CMate-Expanded/perlin_noise.bmp"); // Must be a .bmp file
    Imager::SaveImage(voronoi_noise, "/home/mate/Projects/CMate-Expanded/voronoi_noise.bmp"); // Must be a .bmp file

    int rand_int = Random::iRange(1, 100);
    int rand_int_seed = Random::iRangeS(1, 100, 412);

    double rand_double = Random::dRange(1, 100);
    double rand_double_seed = Random::dRangeS(1, 100, 412);

    std::string message = std::format("My random int is: {}, with seed {}.", rand_int, rand_int_seed);
    LOG(message, LFlags::INFO);

    message = std::format("My random double is: {}, with seed {}.", rand_double, rand_double_seed);
    LOG(message, LFlags::INFO);
}