#pragma once
#ifndef _Submarine_h
#define _Submarine_h

#include <string>
#include "Ship.h"

class Submarine :public Ship
{
public:
	Submarine(Player* owner, int lenght = 3, std::string name = "Submarine");
	Submarine(Player* owner, const Submarine& Sub);
	~Submarine();

private:

};

#endif // !_Submarine_h
