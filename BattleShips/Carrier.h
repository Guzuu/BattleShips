#pragma once
#ifndef _Carrier_h
#define _Carrier_h

#include <string>
#include "Ship.h"

class Carrier: public Ship
{
public:
	Carrier(int lenght = 5, std::string name = "Carrier");
	Carrier(const Carrier* Carr);
	~Carrier();

private:
};

#endif // !_Carrier_h
