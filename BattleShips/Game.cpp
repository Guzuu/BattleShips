#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	std::cout << "Game Over\n";
}

void Game::FastGame()
{

	std::cout << "Fast Mode\n\n";
	Human* p1 = new Human("Mateusz");
	Bot* p2 = new Bot("NastyBot");

	Map* map = new Map(p1, 6);
	Map* map2 = new Map(p2, 6);

	Carrier* s1 = new Carrier(p1);
	Carrier* s2 = new Carrier(p2);
	Destroyer* s3 = new Destroyer(p1);
	Destroyer* s4 = new Destroyer(p2);
	Cruiser* s5 = new Cruiser(p1);
	Cruiser* s6 = new Cruiser(p2);

	map->RandPlacement(s1);
	map->RandPlacement(s3);
	map->RandPlacement(s5);
	map2->RandPlacement(s2);
	map2->RandPlacement(s4);
	map2->RandPlacement(s6);

	Map::DrawMap(map, map2, 6);

	while (p1->GetShipsCount() != 0 && p2->GetShipsCount() != 0) {
		map->Shoot();
		Map::DrawMap(map, map2, 6);
		map2->Shoot();
		Map::DrawMap(map2, map, 6);
	}

	map->~Map();
}

void Game::Standard()
{
}

int Game::Arcade()
{
	return 0;
}

