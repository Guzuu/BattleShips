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

	if (move == 0 && m->WasShipHit(Moves[0].x, Moves[0].y) ) { //After Hitting Ship For the first time Get UP to 4 coordinates for next targets
		LastHit = Moves[0];

		if (Moves[0].x + 1 < m->GetSize() && !(m->GetSectorCheck(Moves[0].x + 1, Moves[0].y))) {
			move++;
			Moves[move].x = Moves[0].x + 1;
			Moves[move].y = Moves[0].y;
		}
		if (Moves[0].y + 1 < m->GetSize() && !(m->GetSectorCheck(Moves[0].x, Moves[0].y + 1))) {
			move++;
			Moves[move].x = Moves[0].x;
			Moves[move].y = Moves[0].y + 1;
		}
		if (Moves[0].x - 1 >= 0 && !(m->GetSectorCheck(Moves[0].x - 1, Moves[0].y))) {
			move++;
			Moves[move].x = Moves[0].x - 1;
			Moves[move].y = Moves[0].y;
		}
		if (Moves[0].y - 1 >=0 && !(m->GetSectorCheck(Moves[0].x, Moves[0].y - 1))) {
			move++;
			Moves[move].x = Moves[0].x;
			Moves[move].y = Moves[0].y - 1;
		}

		m->Shoot(Moves[move].x, Moves[move].y);
	}

	else if (move > 0 && m->WasShipHit(Moves[move].x, Moves[move].y)) { //If there are next moves planned and last shot was a hit
		LastHit = Moves[move];
		
		int tempx = Moves[move].x + Moves[move].x - LastHit.x, tempy = Moves[move].y + Moves[move].y - LastHit.y;
		if (tempx >= 0 && tempx < m->GetSize() && tempy >= 0 && tempy < m->GetSize() && !(m->GetSectorCheck(tempx, tempy))) {
			move++;
			Moves[move].x = tempx;
			Moves[move].y = tempy;
		}
		tempx = LastHit.x - Moves[move].x + LastHit.x;
		tempy = LastHit.y - Moves[move].y + LastHit.y;
		if (tempx >= 0 && tempx < m->GetSize() && tempy >= 0 && tempy < m->GetSize() && !(m->GetSectorCheck(tempx, tempy))) {
			move++;
			Moves[move].x = tempx;
			Moves[move].y = tempy;
		}

		m->Shoot(Moves[move].x, Moves[move].y);
	}

	else if (move > 0) { //If last shot was a miss but there are next moves planned
		m->Shoot(Moves[move].x, Moves[move].y);
		move--;
	}
	else {	//If last shot was a miss and no next moves are planned
		int x, y;
		move = 0;
		
		x = rand() % m->GetSize();
		y = rand() % m->GetSize();

		while (m->GetSectorCheck(x, y)) {
			x = rand() % m->GetSize();
			y = rand() % m->GetSize();
		}

		Moves[move].x = x;
		Moves[move].y = y;

		std::cout << name << " Shoots at " << x << char(y + 65) << std::endl;

		m->Shoot(x, y);
	/*}*/
}