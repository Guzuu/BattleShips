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
	if (hits < 2) {
		if (shots == 0) {	//If last shot was a miss and no next moves are planned

			int x, y;
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
			shots++;
		}
		else if (hits == 0 && m->WasShipHit(Moves[0].x, Moves[0].y)) { //After Hitting Ship For the first time Get UP to 4 coordinates for next targets
			FirstHit = Moves[0];
			LastHit[0] = Moves[0];
			hits++;

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
			if (Moves[0].y - 1 >= 0 && !(m->GetSectorCheck(Moves[0].x, Moves[0].y - 1))) {
				move++;
				Moves[move].x = Moves[0].x;
				Moves[move].y = Moves[0].y - 1;
			}

			std::cout << name << " Shoots at " << Moves[move].x << char(Moves[move].y + 65) << std::endl;
			m->Shoot(Moves[move].x, Moves[move].y);
			shots++;
			move--;
		}
		else if (hits == 1 && m->WasShipHit(Moves[move+1].x, Moves[move+1].y)) {
			hits++;
			LastHit[1] = Moves[move + 1];
			SecondHit = Moves[move + 1];
			MakeMove(m);
		}
		else if (hits == 1 && move > 0) { //If last shot was a miss but there are next moves planned around first hit
			std::cout << name << " Shoots at " << Moves[move].x << char(Moves[move].y + 65) << std::endl;
				m->Shoot(Moves[move].x, Moves[move].y);
				shots++;
				move--;
		}
		else { //No next move get random one next
			shots = 0;
			hits = 0;
			move = 0;
			MakeMove(m);
		}
	}
	else {
		int tempx, tempy;
		move++;

			tempx = LastHit[1].x - LastHit[0].x + LastHit[1].x;
			tempy = LastHit[1].y - LastHit[0].y + LastHit[1].y;
			if (tempx >= 0 && tempx < m->GetSize() && tempy >= 0 && tempy < m->GetSize() && !(m->GetSectorCheck(tempx, tempy))) {
				m->Shoot(tempx, tempy);
				if (!(m->WasShipHit(tempx, tempy)))
				{
					if (EoSoM) {	//Ship sunk for sure
						move = 0;
						hits = 0;
						shots = 0;
					}
					else {			//first ship end rotate movement 
						EoSoM = true;
						LastHit[0] = SecondHit;
						LastHit[1] = FirstHit;
					}
				}
				else { 
					LastHit[0] = LastHit[1];
					LastHit[1].x = tempx;
					LastHit[1].y = tempy;
				}
			}
			else {					//end of map
				if (EoSoM) {		//Ship sunk for sure 
					move = 0;
					hits = 0;
					shots = 0;
					MakeMove(m);
					return;
				}
				else {				//first ship end rotate movement 
					EoSoM = true;
					LastHit[0] = SecondHit;
					LastHit[1] = FirstHit;
					MakeMove(m);
					return;
				}
			}
	}
}