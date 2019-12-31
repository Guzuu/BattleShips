#include "Submarine.h"

Submarine::Submarine(Player* owner, int lenght, std::string name) :Ship(owner, lenght, name)
{
}

Submarine::Submarine(Player* owner, const Submarine& Sub) : Ship(owner, Sub.lenght, Sub.name)
{
}

Submarine::~Submarine()
{
}
