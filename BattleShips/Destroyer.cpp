#include "Destroyer.h"

Destroyer::Destroyer(int lenght, std::string name) :Ship(lenght, name)
{
}

Destroyer::Destroyer(const Destroyer* Dst) : Ship(Dst->lenght, Dst->name)
{
}

Destroyer::~Destroyer()
{
}
