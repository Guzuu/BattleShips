#include "Map.h"
#include <iostream>

Map::Map(int size)
{
	this->size = size;
	map = new Sector * [size];
	for (int x = 0; x < size; x++) map[x] = new Sector[size];
}

Map::~Map()
{
}

void Map::AddShip(Ship *s, bool persp, int x, int y)
{

	if (persp) { //adding ship Horizontaly
		for (int i = x; i < x + s->GetLenght(); i++) {
			map[i][y].occup = true;
			map[i][y].symbol = 'S';
		}
	}
	else { //adding ship Verticaly
		for (int i = y; i < y + s->GetLenght(); i++) {
			map[x][i].occup = true;
			map[x][i].symbol = 'S';
		}
	}
}

void Map::Hit(int x, int y)
{
	if (map[x][y].occup) { //mark ship as hit
		map[x][y].symbol = 'X';
	}
	else {
		map[x][y].hit = true; //mark sector as checked
		map[x][y].symbol = 'O';
	}
}

void Map::DrawMap()
{
	std::cout << " ";
	for (int x = 0; x < size; x++) {  //Numbers first row
		if (x > 9) {
			std::cout << " " << x + 1 << " ";
		}
		else std::cout << "  " << x + 1 << " ";
	}
	std::cout << " " << std::endl << " ";

	for (int y = 0; y < size; y++) { 
		for (int x = 0; x < size; x++) { //separating row
			std::cout << "+---";
		}
		std::cout << "+" << std::endl << char(y+65); //letters
		for (int x = 0; x < size; x++) {
			std::cout << "| " << map[x][y].symbol << " "; //Rows of map
		}
		std::cout << "|" << std::endl <<" ";
	}

	for (int x = 0; x < size; x++) { //last separating row
		std::cout << "+---";
	}
	std::cout << "+" << std::endl;
}
