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
	Map(Player* player, int size);
	~Map();

	template <class T>
	void RandPlacement(T* ship);
	template <class T>
	void UserPlacement(T* ship);

	int AddShip(Ship* ship);
	void Shoot(int x, int y);
	static void DrawMap(Map *m1, Map *m2, int size);

	Player* GetPlayer(); //Getters
	int GetSize(); //returns size of the map
	bool GetSectorCheck(int x, int y); //returns check status of the sector
	bool WasShipHit(int x, int y); 

private:
	struct Sector {
		bool chk = false; //sector checked
		bool occup = false; //ship occupying sector
		char allysymbol = ' ';
		char enemysymbol = ' ';
		Ship* ship;
	};
	int size; //square map size
	Sector **map;
	Player* player;
};

#endif // !_Map_h

template<class T>	//Makes Random Position variables
inline void Map::RandPlacement(T* ship)
{
	ship->SetPersp(rand() % 2); //Picks perspective

	if (ship->GetPersp()) {
		ship->SetX(rand() % (size - ship->GetLenght() + 1)); //Calculates possible horizontal positions with given ship lenght 
		ship->SetY(rand() % size);
	}
	else {
		ship->SetX(rand() % size);
		ship->SetY(rand() % (size - ship->GetLenght() + 1)); //Calculates possible vertical positions with given ship lenght
	}

	if (!AddShip(ship)) {
		RandPlacement(ship);
	}
}

template<class T>
inline void Map::UserPlacement(T* ship)
{
	int coordX;	//using for boolean perspective alignment also 
	char coordY;

	std::cout << "Pick alignment\n1 - Horizontal(__)\n0 - Vertical(|)\n";
	std::cin >> coordX;
	while (coordX != 0 && coordX != 1) {
		std::cout << "Couldnt determine alignment from " << coordX << ". Please try again\n";
		std::cin >> coordX;
	}
	ship->SetPersp(coordX);

	std::cout << "\n Pick coords X and Y\n";
	std::cin >> coordX >> coordY;
	ship->SetX(coordX);
	ship->SetY(coordY-65);
	
	if (!AddShip(ship)) {
		std::cout << "Couldnt Place ship at " << ship->GetX() << char(ship->GetY() + 65) << ". Please input valid coordinates\n";
		UserPlacement(ship);
	}
}

