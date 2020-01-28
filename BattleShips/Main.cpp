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

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();

		std::cout << "Something went wrong try again...\n";
		std::cin >> x;
	}

	switch (x) {
	default:
		std::cout << "Please choose valid option\n";
		MainMenu(g1);
		break;
	case 0:
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