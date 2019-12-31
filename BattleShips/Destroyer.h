#pragma once
#ifndef _Destroyer_h
#define _Destroyer_h

#include <string>
#include "Ship.h"

class Destroyer :public Ship
{
public:
	Destroyer(Player* owner, int lenght = 2, std::string name = "Destroyer");
	Destroyer(Player* owner, const Destroyer& Dst);
	~Destroyer();

private:

};

#endif // !_Destroyer_h
