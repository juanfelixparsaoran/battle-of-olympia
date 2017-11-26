#ifndef COMMAND_H
#define COMMAND_H

#include "unitlist.h"
#include "unit.h"
#include "point.h"
#include "map.h"
#include "boolean.h"
#include "player.h"

void Display_enemy_nearby(UNIT Current_Unit,MAP M, UnitList P1, UnitList P2,boolean *adjacent,UnitList *Enemy_Nearby);
void attack(UNIT *Current_Unit,MAP *M,UnitList *P1, UnitList *P2);
void Recruit(Player *P,int type, MAP *M, POINT Point);

#endif