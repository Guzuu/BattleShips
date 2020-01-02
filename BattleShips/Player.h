#pragma once
#ifndef _Player_h
#define _Player_h

#include <string>
#include <iostream>

class Player
{
public:
	Player(std::string name);
	~Player();

	void IncShips();
	void DecShips();

	int GetShipsCount();
	std::string GetName();

protected:
	std::string name;
	int id, ships=0;

};
#endif // !_Player_h

