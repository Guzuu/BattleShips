#include "Submarine.h"

Submarine::Submarine(int lenght, std::string name) :Ship(lenght, name)
{
}

Submarine::Submarine(const Submarine* Sub) : Ship(Sub->lenght, Sub->name)
{
}

Submarine::~Submarine()
{
}
