#include "Cruiser.h"

Cruiser::Cruiser(int lenght, std::string name) :Ship(lenght, name)
{
}

Cruiser::Cruiser(const Cruiser* Cru) : Ship(Cru->lenght, Cru->name)
{
}

Cruiser::~Cruiser()
{
}