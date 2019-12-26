#pragma once
#ifndef _Aircraft_Carrier

#include <string>
#include "Ship.h"

class AircraftCarrier: public Ship
{
public:
	AircraftCarrier(std::string pname, bool persp, );
	~AircraftCarrier();

private:
};

AircraftCarrier::AircraftCarrier()
{

}

AircraftCarrier::~AircraftCarrier()
{
}

#endif // !_Aircraft_Carrier
