#pragma once
#ifndef _Map_h
#define _Map_h

#include <string>
#include "Sector.h"
#include "Ship.h"

class Map
{
public:
	Map(int size);
	~Map();

	void AddShip(Ship *s, bool persp, int x, int y);
	void Hit(int x, int y);
	void DrawMap();

private:
	struct Sector {
		bool hit = false; //sector hit
		bool occup = false; //ship occupying sector
		char symbol = ' ';
	};
	int size; //square map size
	Sector **map;
};

#endif // !_Map_h
