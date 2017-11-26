#ifndef COMMAND_H
#define COMMAND_H

#include "unitlist.h"
#include "unit.h"
#include "point.h"
#include "map.h"
#include "boolean.h"
#include "player.h"
#include "queue.h"


void Display_enemy_nearby(UNIT Current_Unit,MAP M, UnitList P1, UnitList P2,boolean *adjacent,UnitList *Enemy_Nearby);
void attack(UNIT *Current_Unit,MAP *M,UnitList *P1, UnitList *P2,boolean *can_attack);
void Recruit(Player *P,int *type, MAP *M, POINT *Point,UNIT U);
void CHANGE_UNIT (MAP M,Queue QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT *Current_unit);
void END_TURN(MAP M,Queue *QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT *Current_UNIT);
void INFO (MAP M,int i,int j);

#endif