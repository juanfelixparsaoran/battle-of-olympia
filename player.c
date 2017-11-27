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

void Print_Player_Info(Player P,MAP M){
	printf("Player %d Turn\n",ID(P));
	printf("Cash : %d | Income : %d | Upkeep : %d\n",gold(P),income(P),upkeep(P));
	printf("Unit : %c(%d,%d) | ",Type(Unit(M,Absis(Info(units(P))),Ordinat(Info(units(P))))),Absis(Info(units(P))),Ordinat(Info(units(P))));
	printf("movement point : %d | " , Mov(Unit(M,Absis(Info(units(P))),Ordinat(Info(units(P))))));
	printf("Can attack : "); if (Can_Atk(Unit(M,Absis(Info(units(P))),Ordinat(Info(units(P)))))){ printf("yes\n");} else printf("no\n");
}