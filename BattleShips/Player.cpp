#include "Player.h"

int Player::PlayersCount = 1;

Player::Player(std::string name)
{
	this->name = name;
	PlayersCount++;
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
