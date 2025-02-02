#include "Human.h"

Human::Human(): Player("Human")
{
}

Human::Human(std::string name="Human") : Player(name)
{
}


Human::~Human()
{
}

void Human::MakeMove(Map *m)
{
	int x, y;
	char chy;

	std::cout << name << ", choose your target coordinates\n";
	std::cin >> x >> chy;
	//x--;	
	y = (chy - 65);
	
	while (std::cin.fail() || x < 0 || x >= m->GetSize() || y < 0 || y >= m->GetSize() || m->GetSectorCheck(x,y)) {
		std::cin.clear();
		std::cin.ignore();

		std::cout << "Location " << x << chy << " doesn't exist or sector has already been fired\n";
		std::cout << name << ", choose your target coordinates again\n";
		std::cin >> x >> chy;
		y = (chy - 65);
	}
	
	m->Shoot(x, y);
}