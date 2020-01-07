#include "Ship.h"

Ship::Ship(Player* owner, int lenght, std::string name)
{
	this->owner = owner;
	this->lenght = lenght;
	this->name = name;
	this->health = lenght;
}

Ship::Ship(Player *owner, const Ship& ship)
{
	this->owner = owner;
	this->lenght = ship.lenght;
	this->name = ship.name;
	this->health = ship.lenght;
}

Ship::~Ship()
{
	owner->DecShips();
}

int Ship::GetLenght()
{
	return lenght;
}

int Ship::GetX()
{
	return x;
}

int Ship::GetY()
{
	return y;
}

bool Ship::GetPersp()
{
	return persp;
}

Player* Ship::GetOwner()
{
	return owner;
}

void Ship::SetX(int x)
{
	this->x = x;
}

void Ship::SetY(int y)
{
	this->y = y;
}

void Ship::SetPersp(bool persp)
{
	this->persp = persp;
}

void Ship::ShipHit()
{
	std::cout<<owner->GetName()<<"'s " << name << " has been damaged\n";
	health--;
	if (health == 0) {
		std::cout << owner->GetName() << "'s " << name << " has been destroyed\n";
		this->~Ship();
		std::cout <<owner->GetName() << " has " << owner->GetShipsCount()<<" ships remaining\n";
	}
}