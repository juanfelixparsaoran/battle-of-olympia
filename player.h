#ifndef PLAYER_H
#define PLAYER_H

#include "pcolor.h"
#include "unitlist.h"
#include "villagelist.h"


typedef struct {
	int ID;
	int gold;
	int income;
	int upkeep;
	char color;
	UnitList units;
	VillageList villages;
} Player;

#define ID(P)		(P).ID
#define gold(P)		(P).gold
#define income(P)	(P).income
#define upkeep(P)	(P).upkeep
#define color(P)	(P).color
#define units(P)	(P).units
#define villages(P)	(P).villages

void InitializeNewPlayer(Player *P, int ID);

Player create_new_player(int D);

#endif
