#include "Cruiser.h"

Cruiser::Cruiser(Player *owner, int lenght, std::string name) :Ship(owner, lenght, name)
{
}

Cruiser::Cruiser(Player* owner, const Cruiser& Cru) : Ship(owner, Cru.lenght, Cru.name)
{
}

Cruiser::~Cruiser()
{
}