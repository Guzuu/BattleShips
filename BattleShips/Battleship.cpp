#include "Battleship.h"

Battleship::Battleship(int lenght, std::string name) :Ship(lenght, name)
{
}

Battleship::Battleship(const Battleship *Bts) :Ship(Bts->lenght, Bts->name) 
{
}

Battleship::~Battleship()
{
}