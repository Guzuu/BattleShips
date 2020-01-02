#include "Player.h"

Player::Player(std::string name)
{
	this->name = name;
}

Player::~Player()
{
}

void Player::IncShips()
{
	ships++;
}

void Player::DecShips()
{
	ships--;
}

int Player::GetShipsCount()
{
	return ships;
}

std::string Player::GetName()
{
	return name;
}
