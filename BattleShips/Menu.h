#pragma once
#ifndef _Menu_h
#define _Menu_h

#include <string>
#include <iostream>
#include "Game.h"

class Menu
{
public:
	Menu();
	~Menu();

	void MainMenu();
	void FastGame();
	void Standard();
	void Arcade();

private:
};

#endif // !_Menu_h
