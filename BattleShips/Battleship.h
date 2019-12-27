#pragma once
#ifndef _Battleship_h
#define _Battleship_h

#include <string>
#include "Ship.h"

class Battleship : public Ship
{
public:
	Battleship(int lenght = 4, std::string name = "Battleship");
	Battleship(const Battleship* Bts);
	~Battleship();

private:
};

#endif // !_Battleship_h