#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	std::cout << "Goodbye!\n";
}

void Game::FastGame()
{
	std::cout << "Fast Mode\n\n";
	Human* p1 = new Human("Human1");		//players initialization
	Bot* p2 = new Bot("Bot1");

	Map* map = new Map(p1, 6);		//maps initialization
	Map* map2 = new Map(p2, 6);

	Carrier* s1 = new Carrier(p1);		//Ships initialization		
	Carrier* s2 = new Carrier(p2);
	Destroyer* s3 = new Destroyer(p1);
	Destroyer* s4 = new Destroyer(p2);
	Cruiser* s5 = new Cruiser(p1);
	Cruiser* s6 = new Cruiser(p2);

	map->RandPlacement(s1);		//Placing Ships on the map
	map2->RandPlacement(s2);
	map->RandPlacement(s3);
	map2->RandPlacement(s4);
	map->RandPlacement(s5);
	map2->RandPlacement(s6);

	Map::DrawOneMap(map, 6);

	while (!surrender) {	//Game Rounds
		p1->MakeMove(map2);
		if (p2->GetShipsCount() == 0) {
			Map::DrawOneMap(map2, 6);
			std::cout << p1->GetName() << " Wins!\n";
			break;
		}
		p2->MakeMove(map);
		if (p1->GetShipsCount() == 0) {
			Map::DrawOneMap(map, 6);
			std::cout << p2->GetName() << " Wins!\n";
			break;
		}
		Map::DrawMap(map2, map, 6);
	}

	map->~Map();
	map2->~Map();
	p1->~Human();
	p2->~Bot();
	surrender = false;
	std::cout << "Game Over\n";
}

void Game::Standard()
{
	std::cout << "Standard Mode\n\n";
	Human* p1 = new Human("Human1");		//players initialization
	Bot* p2 = new Bot("Bot1");

	Map* map = new Map(p1, 9);
	Map* map2 = new Map(p2, 9);
	
	Carrier* s1 = new Carrier(p1);		//Ships initialization		
	Carrier* s2 = new Carrier(p2);
	Battleship* s3 = new Battleship(p1);
	Battleship* s4 = new Battleship(p2);
	Cruiser* s5 = new Cruiser(p1);
	Cruiser* s6 = new Cruiser(p2);
	Submarine* s7 = new Submarine(p1);
	Submarine* s8 = new Submarine(p2);
	Destroyer* s9 = new Destroyer(p1);
	Destroyer* s10 = new Destroyer(p2);

	Map::DrawOneMap(map, 9);

	map->UserPlacement(s1);		//Placing Ships on the map
	map2->RandPlacement(s2);
	map->UserPlacement(s3);
	map2->RandPlacement(s4);
	map->UserPlacement(s5);
	map2->RandPlacement(s6);
	map->UserPlacement(s7);
	map2->RandPlacement(s8);
	map->UserPlacement(s9);
	map2->RandPlacement(s10);

	while (!surrender) {	//Game Rounds
		p1->MakeMove(map2);
		if (p2->GetShipsCount() == 0) {
			Map::DrawOneMap(map2, 9);
			std::cout << p1->GetName() << " Wins!\n";
			break;
		}
		p2->MakeMove(map);
		if (p1->GetShipsCount() == 0) {
			Map::DrawOneMap(map, 9);
			std::cout << p2->GetName() << " Wins!\n";
			break;
		}
		Map::DrawMap(map2, map, 9);
	}

	map->~Map();
	map2->~Map();
	p1->~Human();
	p2->~Bot();
	surrender = false;
	std::cout << "Game Over\n";
}

int Game::Arcade()
{
	std::cout << "Arcade Mode\n\n"
	<< "Choose a map size from 6 to 26\n";
	int s;
	std::cin >> s;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();

		std::cout << "Something went wrong try again...\n";
		std::cin >> s;
	}

	if (s < 6 || s>26) {
		std::cout << "Given map size is invalid\n";
		Arcade();
		return 0;
	}
	Human* p1 = new Human("Human1");		//players initialization
	Bot* p2 = new Bot("Bot1");

	Map* map = new Map(p1, s);
	Map* map2 = new Map(p2, s);

	/*while (shipSectors > 0) {
		std::cout << "Pick a ship for your fleet\n\n 1 - Carrier\n 2 - Battleship\n 3 - Cruiser\n 4 - Submarine\n 5 - Destroyer\n You have to cover " << shipSectors << " more sectors.\n";
		int x;
		std::cin >> x;

		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();

			std::cout << "Something went wrong try again...\n";
			std::cin >> x;
		}

		switch (x) {
		default:
			std::cout << "This ship does not exist\n";
			break;
		case 1:
			Carrier * s1 = new Carrier(p1);
			Carrier* s2 = new Carrier(p2);

			map->UserPlacement(s1);
			map2->RandPlacement(s2);
			break;
		case 2:
			Battleship * s3 = new Battleship(p1);
			Battleship* s4 = new Battleship(p2);

			map->UserPlacement(s3);
			map2->RandPlacement(s4);
			break;
		}
	}*/

	Carrier* s1 = new Carrier(p1);		//Ships initialization		
	Carrier* s2 = new Carrier(p2);
	Battleship* s3 = new Battleship(p1);
	Battleship* s4 = new Battleship(p2);
	Cruiser* s5 = new Cruiser(p1);
	Cruiser* s6 = new Cruiser(p2);
	Submarine* s7 = new Submarine(p1);
	Submarine* s8 = new Submarine(p2);
	Destroyer* s9 = new Destroyer(p1);
	Destroyer* s10 = new Destroyer(p2);

	Map::DrawOneMap(map, s);

	map->UserPlacement(s1);		//Placing Ships on the map
	map2->RandPlacement(s2);
	map->UserPlacement(s3);
	map2->RandPlacement(s4);
	map->UserPlacement(s5);
	map2->RandPlacement(s6);
	map->UserPlacement(s7);
	map2->RandPlacement(s8);
	map->UserPlacement(s9);
	map2->RandPlacement(s10);

	while (!surrender) {	//Game Rounds
		p1->MakeMove(map2);
		if (p2->GetShipsCount() == 0) {
			std::cout << p1->GetName() << " Wins!\n";
			break;
		}
		p2->MakeMove(map);
		if (p1->GetShipsCount() == 0) {
			std::cout << p2->GetName() << " Wins!\n";
			break;
		}
		Map::DrawMap(map2, map, s);
	}

	map->~Map();
	map2->~Map();
	p1->~Human();
	p2->~Bot();
	surrender = false;
	std::cout << "Game Over\n";

	return 1;
}
