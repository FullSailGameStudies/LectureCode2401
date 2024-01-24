#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	FlyingCar(float maxAlt, float maxSpeed,
			  int year, std::string make, std::string model) :
		Car(year,make,model),
		maxAltitude_(maxAlt),
		maxAirSpeed_(maxSpeed)
	{

	}
private:
	float maxAltitude_;
	float maxAirSpeed_;
};

