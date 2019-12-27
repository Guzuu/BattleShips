#include "Map.h"

Map::Map(int size)
{
	this->size = size;
	map = new Sector * [size];
	for (int x = 0; x < size; x++) map[x] = new Sector[size];
}

Map::~Map()
{
}

int Map::AddShip(Ship *s, bool persp, int x, int y)
{

	if (persp) { //adding ship Horizontaly
		if (size > y) {
			for (int i = x; i < x + s->GetLenght(); i++) {
				if (size <= i || map[i][y].occup) {
					std::cout << "Cannot place ship at " << i << char(y + 65) << "\n Make different placement." << std::endl;
					
					AddShipRand(s);
					return 0;
				}
			}
			for (int i = x; i < x + s->GetLenght(); i++) {
				map[i][y].occup = true;
				map[i][y].symbol = 'S';
			}
		}
	}
	else { //adding ship Verticaly
		if (size > x) {
			for (int i = y; i < y + s->GetLenght(); i++) {
				if (size <= i || map[x][i].occup) {
					std::cout << "Cannot Place Ship at " << x << char(i + 65) << "\n Make different placement." << std::endl;
					
					AddShipRand(s);
					return 0;
				}
			}
			for (int i = y; i < y + s->GetLenght(); i++) {
				map[x][i].occup = true;
				map[x][i].symbol = 'S';
			}
		}
	}
	return 0;
}

void Map::Hit(int x, int y)
{
	if (map[x][y].occup) { //mark ship as hit
		map[x][y].symbol = 'X';
	}
	else {
		map[x][y].chk = true; //mark sector as checked
		map[x][y].symbol = 'O';
	}
}

void Map::DrawMap()
{
	std::cout << " ";
	for (int x = 0; x < size; x++) {  //Numbers first row
		if (x > 9) {
			std::cout << " " << x << " ";
		}
		else std::cout << "  " << x << " ";
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
