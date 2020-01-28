#pragma once
#ifndef _Ship_h
#define _Ship_h

#include <string>
#include <iostream>
#include "Player.h"

class Ship
{
public:
	Ship(Player* owner, int lenght, std::string name);
	Ship(Player *, const Ship& ship);
	~Ship();

	int GetLenght();	//Getters
	int GetX();
	int GetY();
	bool GetPersp();
	std::string GetShipName();
	Player* GetOwner();

	void SetX(int x);	//Setters
	void SetY(int y);
	void SetPersp(bool persp);

	void ShipHit();

protected:
	int lenght, x, y, health;
	std::string name;
	bool persp;
	Player *owner; //p1, p2, bot etc
};

#endif // !_Ship_h
