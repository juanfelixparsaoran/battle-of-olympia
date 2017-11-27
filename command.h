#ifndef COMMAND_H
#define COMMAND_H

#include "unitlist.h"
#include "unit.h"
#include "point.h"
#include "map.h"
#include "boolean.h"
#include "player.h"
#include "queue.h"
#include "stacklist.h"
#include <stdio.h>
#include <stdlib.h>


void Display_enemy_nearby(UNIT Current_Unit,MAP M, UnitList P1, UnitList P2,boolean *adjacent,UnitList *Enemy_Nearby);
void attack(UNIT *Current_Unit,MAP *M,UnitList *P1, UnitList *P2,boolean *can_attack);
void Recruit(Player *P,int *type, MAP *M, POINT *Point,UNIT U);
void CHANGE_UNIT (MAP M,Queue QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT *Current_unit);
void END_TURN(MAP M,Queue *QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT *Current_UNIT);
void INFO (MAP M,int i,int j);
void CreateEmpty(UnitList *L);
void ReadMoveValue(POINT *P);
void Undo(POINT *P,UNIT *U , Stack *S, MAP *M, Player *Play);
/*I.S. X dan Y sembarang*/
/*F.S. X dan Y adalah nilai perpindahan unit ke petak yang adjacent dengan petak sebelumnya*/

int MovementsRemain (UNIT U);
/*I.S. Unit telah move ke beberapa petak*/
/*F.S. Sisa move point dari suatu unit*/

boolean CanUnitMove(UNIT U, MAP M , POINT P);
/*I.S. Unit berada pada suatu petak*/
/*F.S. Unit akan dapat berpindah apabila move point masih > 0 dan petak tempat dia akan berpindah masih kosong*/

boolean IsSquareEmpty(MAP M , POINT P);
/*I.S. Petak pada map*/
/*F.S. Sebuah petak sedang tidak ditempati oleh sebuah unit*/

void ChangeUnitPos(UNIT *U , POINT P, MAP *M, Player *Play);


void Move(MAP *M , UNIT *U , POINT P, Player *Play);
/*I.S. Unit pada sebuah petak, siap untuk berpindah ke petak lain. Unit dapat berpindah ke sebuah petak apabila 
	   Petak yang akan ditempati masih kosong dan movement pointnya  masih > 0*/
/*F.S. Dibaca nilai titik perpindahan. Sebuah unit akan berpindah menuju titik yang dituju*/

boolean IsSquareAdjacent(UNIT U , POINT P);
/*I.S. Dibaca sebuah koordinat petak*/
/*F.S. Sebuah koordinat petak yang adjacent dengan petak posisi unit*/
#endif