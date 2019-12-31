#include "Carrier.h"

Carrier::Carrier(Player* owner, int lenght, std::string name) :Ship(owner, lenght, name)
{
}

Carrier::Carrier(Player *owner, const Carrier& Carr) : Ship(owner, Carr)
{
}

Carrier::~Carrier()
{
}