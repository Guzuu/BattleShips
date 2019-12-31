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
		if (size > ship->GetY()) {
			for (int i = ship->GetX(); i < ship->GetX() + ship->GetLenght(); i++) {
				if (size <= i || map[i][ship->GetY()].occup) {
					return 0;
				}
			}
			for (int i = ship->GetX(); i < ship->GetX() + ship->GetLenght(); i++) {
				map[i][ship->GetY()].occup = true;
				map[i][ship->GetY()].allysymbol = 'S';
				map[i][ship->GetY()].ship = ship;
				ship->GetOwner()->IncShips();
			}
		}
	}
	else { //adding ship Verticaly
		if (size > ship->GetX()) {
			for (int i = ship->GetY(); i < ship->GetY() + ship->GetLenght(); i++) {
				if (size <= i || map[ship->GetX()][i].occup) {
					return 0;
				}
			}
			for (int i = ship->GetY(); i < ship->GetY() + ship->GetLenght(); i++) {
				map[ship->GetX()][i].occup = true;
				map[ship->GetX()][i].allysymbol = 'S';
				map[ship->GetX()][i].ship = ship;
				ship->GetOwner()->IncShips();
			}
		}
	}
	return 1;
}

int Map::Shoot()
{
	int coordX, coordY;
	char chcoordY;

	std::cout<<GetPlayer()->GetName() << ", choose your target coordinates\n";
	std::cin >> coordX >> chcoordY;
	//coordX--;	
	coordY = (chcoordY - 65);

	if (coordX < 0 || coordX >= size || coordY < 0 || coordY >= size) {
		std::cout << "Location " << coordX << chcoordY << " doesn't exist\n";
			Shoot();
			return 0;
	}

	if (map[coordX][coordY].occup && !map[coordX][coordY].chk) { //mark ship as hit
		map[coordX][coordY].enemysymbol = 'X';
		map[coordX][coordY].ship->ShipHit();
		map[coordX][coordY].chk = true;
	}
	else if(!map[coordX][coordY].chk){
		map[coordX][coordY].chk = true; //mark sector as checked
		map[coordX][coordY].enemysymbol = 'O';
	}
	else {
		std::cout << "Coordinates already checked make a new target\n";
		Shoot();
		return 0;
	}
	return 1;
}

void Map::DrawMap(Map *m1, Map *m2, int size)
{
	std::cout << m1->player->GetName() << std::endl;

	std::cout << " ";
	for (int x = 0; x < size; x++) {  //Numbers first row
		if (x > 9) {
			std::cout << " " << x << " ";
		}
		else std::cout << "  " << x << " ";
	}
	std::cout << "          ";
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


