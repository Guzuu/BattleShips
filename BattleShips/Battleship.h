#pragma once
#ifndef _Battleship_h
#define _Battleship_h

#include <string>
#include "Ship.h"

class Battleship : public Ship
{
public:
	Battleship(Player* owner, int lenght = 4, std::string name = "Battleship");
	Battleship(Player* owner, const Battleship& Bts);
	~Battleship();

private:
};

#endif // !_Battleship_h