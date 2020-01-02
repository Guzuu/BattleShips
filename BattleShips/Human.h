#pragma once
#ifndef _Human_h
#define _Human_h

#include "Player.h"
#include "Map.h"
#include <string>
#include <iostream>

class Human : public Player
{
public:
	Human();
	Human(std::string name);
	~Human();

	void MakeMove(Map *m);
	
private:
};

#endif // !_Human_h
