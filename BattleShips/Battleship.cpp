#include "Battleship.h"

Battleship::Battleship(Player* owner, int lenght, std::string name) :Ship(owner, lenght, name)
{
}

Battleship::Battleship(Player* owner, const Battleship &Bts) :Ship(owner, Bts.lenght, Bts.name)
{
}

Battleship::~Battleship()
{
}