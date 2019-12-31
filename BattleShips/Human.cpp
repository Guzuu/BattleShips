#include "Human.h"

Human::Human(std::string name="Human"+PlayersCount) : Player(name)
{
}

Human::Human(const Human &Hum) :Player(Hum.name)
{
}

Human::~Human()
{
	PlayersCount--;
}
