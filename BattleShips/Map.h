#pragma once
#ifndef _Map_h
#define _Map_h

#include <string>
#include <iostream>
#include <time.h>

#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"


class Map
{
public:
	Map(int size);
	~Map();

	template <class T>
	void AddShipRand(T* ship);

	int AddShip(Ship* s, bool persp, int x, int y);
	void Hit(int x, int y);
	void DrawMap();

private:
	struct Sector {
		bool chk = false; //sector checked
		bool occup = false; //ship occupying sector
		char symbol = ' ';
	};
	int size; //square map size
	Sector **map;
};

#endif // !_Map_h

template<class T>	//Makes Random Position variables
inline void Map::AddShipRand(T* ship)
{
	bool persp;
	int x, y;
	persp = rand() % 2;

	if (persp) {
		x = rand() % (size - ship->GetLenght() +1);
		y = rand() % size;
	}
	else {
		x = rand() % size;
		y = rand() % (size - ship->GetLenght() +1);
	}

	std::cout << persp << x << y<<std::endl;

	AddShip(ship, persp, x, y);
}

