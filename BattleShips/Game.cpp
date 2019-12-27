#include "Game.h"

Game::Game()
{
	std::cout << "Fast Mode\n\n";
	Map* map = new Map(6);
	Carrier* s1 = new Carrier();
	Battleship* s2 = new Battleship();
	Battleship* s3 = new Battleship(s2);
	Destroyer* s4 = new Destroyer();
	std::cout << Ship::ShipsCount() << std::endl;
	
	map->AddShipRand(s1);
	map->AddShipRand(s2);
	map->AddShipRand(s3);
	map->AddShipRand(s4);
	map->DrawMap();

	map->~Map();
}

Game::~Game()
{
	std::cout << "Game Over\n";
}
