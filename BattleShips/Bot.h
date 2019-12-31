#pragma once
#ifndef _Bot_h
#define _Bot_h

#include "Player.h"
#include <string>

class Bot : public Player
{
public:
	Bot(std::string name);
	Bot(const Bot& Bot);
	~Bot();


private:

};

#endif // !_Bot_h
