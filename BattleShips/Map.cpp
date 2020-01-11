#include "Map.h"

Map::Map(Player* player, int size)
{
	this->player = player;
	this->size = size;
	map = new Sector * [size];
	for (int x = 0; x < size; x++) map[x] = new Sector[size];
}

Map::~Map()
{
}

int Map::AddShip(Ship *ship)
{

	if (ship->GetPersp()) { //adding ship Horizontaly
		for (int i = ship->GetX(); i < ship->GetX() + ship->GetLenght(); i++) {
			if (size <= i || map[i][ship->GetY()].occup) {
				return 0;
			}
		}
		for (int i = ship->GetX(); i < ship->GetX() + ship->GetLenght(); i++) {
			map[i][ship->GetY()].occup = true;
			map[i][ship->GetY()].allysymbol = 'S';
			map[i][ship->GetY()].ship = ship;

		}
		player->IncShips();
	}
	else { //adding ship Verticaly
		for (int i = ship->GetY(); i < ship->GetY() + ship->GetLenght(); i++) {
			if (size <= i || map[ship->GetX()][i].occup) {
				return 0;
			}
		}
		for (int i = ship->GetY(); i < ship->GetY() + ship->GetLenght(); i++) {
			map[ship->GetX()][i].occup = true;
			map[ship->GetX()][i].allysymbol = 'S';
			map[ship->GetX()][i].ship = ship;

		}
		player->IncShips();
	}
	return 1;
}

void Map::Shoot(int x, int y)
{

	if (map[x][y].occup && !map[x][y].chk) { //mark ship as hit
		map[x][y].enemysymbol = 'X';
		map[x][y].ship->ShipHit();
		map[x][y].chk = true;
	}
	else {
		map[x][y].chk = true; //mark sector as checked
		map[x][y].enemysymbol = 'O';
	}
}

void Map::DrawMap(Map *m1, Map *m2, int size)
{
	std::cout << m1->player->GetName();	//prining first name
	for (int x = 0; x < 4 * size - m1->player->GetName().length() + 11; x++) {
		std::cout << " ";
	}
	std::cout << m2->player->GetName() <<"\n ";	//printing 2nd name

	for (int x = 0; x < size; x++) {  //Numbers first row
		if (x > 9) {
			std::cout << " " << x << " ";
		}
		else std::cout << "  " << x << " ";
	}
	std::cout << "           ";
	for (int x = 0; x < size; x++) {  //Numbers first row 2
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
		std::cout << "+          ";
		for (int x = 0; x < size; x++) { //separating row 2
			std::cout << "+---";
		}
		std::cout << "+" << std::endl << char(y+65); //letters
		for (int x = 0; x < size; x++) {
			std::cout << "| " << m1->map[x][y].enemysymbol << " "; //Rows of map
		}
		std::cout << "|         ";
		std::cout <<char(y + 65); //letters 2
		for (int x = 0; x < size; x++) {
			std::cout << "| " << m2->map[x][y].allysymbol << " "; //Rows of map 2
		}
		std::cout << "|" << std::endl <<" ";
	}
	for (int x = 0; x < size; x++) { //last separating row
		std::cout << "+---";
	}
	std::cout << "+          ";
	for (int x = 0; x < size; x++) { //last separating row 2
		std::cout << "+---";
	}
	std::cout << "+" << std::endl;
}

Player* Map::GetPlayer()
{
	return player;
}

int Map::GetSize()
{
	return size;
}

bool Map::GetSectorCheck(int x, int y)
{
	return map[x][y].chk;
}

bool Map::WasShipHit(int x, int y)
{
	if (map[x][y].occup && map[x][y].chk) return true;
	else return false;
}


