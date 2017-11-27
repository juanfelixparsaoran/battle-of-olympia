#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include <stdlib.h>
#include "unitlist.h"
#include "unitlist.h"
#include "villagelist.h"
#include "matriksPetak.h"
#include "player.h"
#include "point.h"
#include "unit.h"
#include "map.h"
#include "villages.h"
#include "startingGame.h"
#include "command.h"
#include "move.h"
#include "math.h"
#include "stacklist.h"

void ReadMoveValue(POINT *P);
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


void Move(MAP *M , UNIT *U , POINT P, Player *Play,Stack *S);
/*I.S. Unit pada sebuah petak, siap untuk berpindah ke petak lain. Unit dapat berpindah ke sebuah petak apabila 
	   Petak yang akan ditempati masih kosong dan movement pointnya  masih > 0*/
/*F.S. Dibaca nilai titik perpindahan. Sebuah unit akan berpindah menuju titik yang dituju*/

boolean IsSquareAdjacent(UNIT U , POINT P);
/*I.S. Dibaca sebuah koordinat petak*/
/*F.S. Sebuah koordinat petak yang adjacent dengan petak posisi unit*/

void ChangeUnitPosUndo(UNIT *U , POINT P, MAP *M, Player *Play);

void Undo(POINT *P,UNIT *U , Stack *S, MAP *M, Player *Play);
#endif