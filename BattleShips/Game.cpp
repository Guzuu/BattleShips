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
	Bot* p1 = new Bot();
	Bot* p2 = new Bot();

	Map* map = new Map(p1, 6);
	Map* map2 = new Map(p2, 6);

	Carrier* s1 = new Carrier(p1);
	Carrier* s2 = new Carrier(p2);
	Destroyer* s3 = new Destroyer(p1);
	Destroyer* s4 = new Destroyer(p2);
	Cruiser* s5 = new Cruiser(p1);
	Cruiser* s6 = new Cruiser(p2);

	map->RandPlacement(s1);
	map2->RandPlacement(s2);
	map->RandPlacement(s3);
	map2->RandPlacement(s4);
	map->RandPlacement(s5);
	map2->RandPlacement(s6);

	Map::DrawMap(map, map2, 6);

	while (p1->GetShipsCount() != 0 && p2->GetShipsCount() != 0) {
		p1->MakeMove(map2);
		Map::DrawMap(map, map2, 6);
		p2->MakeMove(map);
		Map::DrawMap(map2, map, 6);
	}

	if (p1->GetShipsCount() == 0) std::cout << p2->GetName() << " Wins!\n";
	else std::cout << p1->GetName() << " Wins!\n";

	map->~Map();
	map2->~Map();
}

void Game::Standard()
{
	std::cout << "Standard Mode\n\n";
	Human* p1 = new Human("Mateusz");
	Bot* p2 = new Bot("NastyBot");

	Map* map = new Map(p1, 9);
	Map* map2 = new Map(p2, 9);
	
	

	map->~Map();
	map2->~Map();
}

int Game::Arcade()
{
	std::cout << "Arcade Mode\n\n"
	<< "Choose a map size from 6 to 26\n";
	int s;
	std::cin >> s;
	if (s < 6 || s>26) {
		std::cout << "Given map size is invalid\n";
		Arcade();
		return 0;
	}
	Human* p1 = new Human("Mateusz");
	Bot* p2 = new Bot("NastyBot");

	Map* map = new Map(p1, s);
	Map* map2 = new Map(p2, s);



	map->~Map();
	map2->~Map();

	return 1;
}