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
/*
	Coords PrevMove;
	Coords NextMoves[5];*/
};

#endif // !_Bot_h
