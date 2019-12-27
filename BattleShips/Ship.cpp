#include "Ship.h"

int Ship::count = 0;

Ship::Ship(int lenght, std::string name)
{
	this->lenght = lenght;
	this->name = name;
	count++;
}

Ship::Ship(const Ship& Ship)
{
	this->lenght = Ship.lenght;
	this->name = Ship.name;
}

Ship::~Ship()
{
	count--;
}

int Ship::GetLenght()
{
	return lenght;
}

void Ship::ResetShipsCount()
{
	count = 0;
}

int Ship::ShipsCount()
{
	return count;
}
