#include "Ship.h"

Ship::Ship(int lenght, int x, int y, std::string name, bool persp)
{
	this->lenght = lenght;
	this->x = x;
	this->y = y;
	this->name = name;
	this->persp = persp;
}

Ship::~Ship()
{
}

int Ship::GetLenght()
{
	return lenght;
}
