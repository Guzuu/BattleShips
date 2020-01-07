#pragma once
#ifndef _Bot_h
#define _Bot_h

#include "Player.h"
#include "Map.h"
#include <string>

class Bot : public Player
{
public:
	Bot();
	Bot(std::string name);
	~Bot();

	void MakeMove(Map* m);

private:
	struct Coords {
		int x;
		int y;
	};
	int move=0;
	int hits=0;
	int shots = 0;

	bool EoSoM = false; //end of ship or map

	Coords Moves[7];
	Coords FirstHit;
	Coords SecondHit;
	Coords LastHit[2];
};

#endif // !_Bot_h
