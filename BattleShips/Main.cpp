#include <iostream>
#include "Game.h"

void MainMenu(Game* g1)
{
	std::cout << "Menu\n"
		<< "1 - Fast Game\n"
		<< "2 - Standard\n"
		<< "3 - Arcade\n"
		<< "0 - Quit\n";

	int x;
	std::cin >> x;
	switch (x) {
	default:
		std::cout << "Please choose valid option\n";
		MainMenu(g1);
		break;
	case 0:
		std::cout << "Goodbye!\n";
		g1->~Game();
		break;
	case 1:
		g1->FastGame();
		MainMenu(g1);
		break;
	case 2:
		g1->Standard();
		MainMenu(g1);
		break;
	case 3:
		g1->Arcade();
		MainMenu(g1);
		break;
	}
}

int main() {
	srand(time(NULL));

	Game* g1 = new Game();
	MainMenu(g1);

	return 0;
}

/*#include "Menu.h"

Menu::Menu()
{
	std::cout << "BattleShips v1.0 by Guzuu\n\n";
	MainMenu();
}

Menu::~Menu()
{
}

void Menu::MainMenu()
{
	std::cout << "Menu\n"
		<< "1 - Fast Game\n"
		<< "2 - Standard\n"
		<< "3 - Arcade\n"
		<< "0 - Quit\n";

	int x;
	std::cin >> x;
	switch (x) {
	default:
		std::cout << "Please choose valid option\n";
		MainMenu();
		break;
	case 0:
		std::cout << "Goodbye!\n";
		break;
	case 1:
		FastGame();
		MainMenu();
		break;
	case 2:
		Standard();
		MainMenu();
		break;
	case 3:
		Arcade();
		MainMenu();
		break;
	}
}

void Menu::FastGame()
{
	Game* g1 = new Game();
	g1->Arcade();

	g1->~Game();
}

void Menu::Standard()
{
	std::cout << "Standard Mode\n\n";
	/*Map* map = new Map(9);
	map->~Map();
}

int Menu::Arcade()
{
	std::cout << "Arcade Mode\n\n";
		<< "Choose a map size from 6 to 26\n";
	int s;
	std::cin >> s;
	if (s < 6 || s>26) {
		std::cout << "Given map size is invalid\n";
		Arcade();
		return 0;
	}

	Map* map = new Map(s);
	map->DrawMap();
	map->~Map();

	return 1;
}
*/