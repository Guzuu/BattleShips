#include "Carrier.h"

Carrier::Carrier(int lenght, std::string name) :Ship(lenght, name)
{

}

Carrier::Carrier(const Carrier* Carr) : Ship(Carr->lenght, Carr->name)
{
}

Carrier::~Carrier()
{
}