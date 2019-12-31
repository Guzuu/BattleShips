#pragma once
#ifndef _Human_h
#define _Human_h

#include "Player.h"
#include <string>

class Human : public Player
{
public:
	Human(std::string name);
	Human(const Human& Hum);
	~Human();
	
private:

};

#endif // !_Human_h
