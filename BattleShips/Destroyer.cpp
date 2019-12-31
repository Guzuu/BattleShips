#include "Destroyer.h"

Destroyer::Destroyer(Player* owner, int lenght, std::string name) :Ship(owner, lenght, name)
{
}

Destroyer::Destroyer(Player* owner, const Destroyer& Dst):Ship(owner, Dst.lenght, Dst.name)
{
}

Destroyer::~Destroyer()
{
}
