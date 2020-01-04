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
	int move;

	bool EoSOM = false;
	bool _2Hits = false;
	Coords Moves[7];
	Coords LastHit;
};

#endif // !_Bot_h
