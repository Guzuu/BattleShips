#pragma once
#ifndef _Game_h
#define _Game_h

#include "Map.h"
#include "Ship.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Human.h"
#include "Bot.h"

class Game
{
public:
	Game();
	~Game();

	void FastGame();
	void Standard();
	int Arcade();

private:

	bool surrender = false;
};

#endif // !_Game_h
