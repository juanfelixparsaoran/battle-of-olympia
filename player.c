#include "player.h"


void InitializeNewPlayer(Player *P, int ID){
	ID(*P) = ID;
	gold(*P) = 20;
	income(*P) = 0;
	upkeep(*P) = 0;

	if (ID==1){
		color(*P) = 'R';
	}
	else if (ID==2){
		color(*P) = 'G';
	}

	units(*P) = NULL;
	villages(*P) = NULL;

}

Player create_new_player(int ID){
	Player new_player;

	InitializeNewPlayer(&new_player, ID);
	return new_player;
}
