#pragma once
#ifndef _Cruiser_h
#define _Cruiser_h

#include <string>
#include "Ship.h"

class Cruiser : public Ship
{
public:
	Cruiser(int lenght = 3, std::string name = "Cruiser");
	Cruiser(const Cruiser* Cru);
	~Cruiser();

private:
};

#endif // !_Cruiser_h