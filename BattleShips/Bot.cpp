#include "Bot.h"

Bot::Bot(std::string name = "Bot" + PlayersCount) : Player(name)
{
}

Bot::Bot(const Bot& Bot) : Player(Bot.name)
{
}

Bot::~Bot()
{
	PlayersCount--;
}
