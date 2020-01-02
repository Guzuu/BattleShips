#include "Bot.h"

Bot::Bot() :Player("Bot")
{
}

Bot::Bot(std::string name) : Player(name)
{
}

Bot::~Bot()
{
}

void Bot::MakeMove(Map* m)
{

	/*if (m->WasShipHit(PrevMove.x, PrevMove.y)) {
		int i=0;

		NextMoves[0].x = PrevMove.x + 1;
		NextMoves[0].y = PrevMove.y;

		NextMoves[1].x = PrevMove.x;
		NextMoves[1].y = PrevMove.y + 1;

		NextMoves[2].x = PrevMove.x - 1;
		NextMoves[2].y = PrevMove.y;

		NextMoves[3].x = PrevMove.x;
		NextMoves[3].y = PrevMove.y - 1;

		while (m->GetSectorCheck(NextMoves[i].x, NextMoves[i].y) || NextMoves[i].x >= m->GetSize() || NextMoves[i].y >= m->GetSize() || NextMoves[i].x < 0 || NextMoves[i].y < 0) {
			i++;
		}

		PrevMove.x = NextMoves[i].x * 2 / PrevMove.x
		PrevMove.y =
		m->Shoot(NextMoves[i].x, NextMoves[i].y);
		
	}
	else {*/
		int x, y;
		
		x = rand() % m->GetSize();
		y = rand() % m->GetSize();

		while (m->GetSectorCheck(x, y)) {
			x = rand() % m->GetSize();
			y = rand() % m->GetSize();
		}

		/*PrevMove.x = x;
		PrevMove.y = y;*/

		std::cout << name << " Shoots at " << x << char(y + 65) << std::endl;

		m->Shoot(x, y);
	/*}*/
}