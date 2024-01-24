#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //FULLY OVERRIDE: means you do NOT call the base version
    //EXTEND: means you call the base version
    std::string info = Car::vehicleInformation() +  "\nMax Altitude: " + std::to_string(maxAltitude_) +
        "\tMax Airspeed: " + std::to_string(maxAirSpeed_);
    return info;
}
