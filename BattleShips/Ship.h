#pragma once
#ifndef _Ship_h
#define _Ship_h

#include <string>

class Ship
{
public:
	Ship(int lenght, int x, int y, std::string name, bool persp);
	~Ship();

	int GetLenght();

protected:
	int lenght, x, y;
	std::string name;
	bool persp;
};

#endif // !_Ship_h
