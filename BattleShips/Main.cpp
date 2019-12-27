#include <iostream>
#include "Map.h"
#include "Ship.h"

int main() {

	Map *m1 = new Map(5); //From 3 to 26
	Ship* s1 = new Ship(4,2,2,"Apacz",0);
	m1->DrawMap();
	m1->AddShip(s1, 1, 2, 3);
	m1->DrawMap();

	return 0;
}