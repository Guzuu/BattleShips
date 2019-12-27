#pragma once
#ifndef _Ship_h
#define _Ship_h

#include <string>

class Ship
{
public:
	Ship(int lenght, std::string name);
	Ship(const Ship &Ship);
	~Ship();

	int GetLenght();
	static void ResetShipsCount();
	static int ShipsCount();

private:
	static int count;

protected:
	int lenght, x, y;
	std::string name;
	bool persp;
};

#endif // !_Ship_h
