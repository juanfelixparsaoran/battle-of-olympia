/* Move and Undo Command for Battle for Olympia*/

#include <stdio.h>
#include <stdlib.h>
#include "move.h"

/**************** Procedure to create Move Command***************************/
void ReadMoveValue(POINT *P){
/*I.S. X dan Y sembarang*/
/*F.S. X dan Y adalah nilai perpindahan unit ke petak yang adjacent dengan petak sebelumnya*/
	BacaPOINT(P);
}

int MovementsRemain (UNIT U){
/*I.S. Unit telah move ke beberapa petak*/
/*F.S. Sisa move point dari suatu unit*/
	return Mov(U);
}

boolean CanUnitMove(UNIT U, MAP M , POINT P){
/*I.S. Unit berada pada suatu petak*/
/*F.S. Unit akan dapat berpindah apabila move point masih > 0 dan petak tempat dia akan berpindah masih kosong*/
	return (MovementsRemain(U) > 0) && IsSquareEmpty(M,P);
}

boolean IsSquareEmpty(MAP M , POINT P){
/*I.S. Petak pada map*/
/*F.S. Sebuah petak sedang tidak ditempati oleh sebuah unit*/
	return Type(Unit(M,Absis(P), Ordinat(P)))==Nil;
}

void ChangeUnitPos(UNIT *U , POINT P){
/*I.S. Unit siap dipindahkan ke sebuah petak. Dibaca sebuah titik*/
/*F.S. Unit berpindah ke sebuah petak yang adjacent dengan petak sebelumnya*/
	Absis(Pos(*U))= Absis(P);
	Ordinat(Pos(*U)) = Ordinat(P);
}

boolean IsSquareAdjacent(UNIT U , POINT P){
/*I.S. Dibaca sebuah koordinat petak*/
/*F.S. Sebuah koordinat petak yang adjacent dengan petak posisi unit*/
	return (Absis(Pos(U))- Absis(P)==0 || Ordinat(Pos(U)) - Ordinat(P)==0) && (abs(Absis(Pos(U)) - Absis(P))==1 || abs(Ordinat(Pos(U))-Ordinat(P))==1);
}

void Move(MAP M , UNIT U , POINT P){
/*I.S. Unit pada sebuah petak, siap untuk berpindah ke petak lain. Unit dapat berpindah ke sebuah petak apabila 
	   Petak yang akan ditempati masih kosong dan movement pointnya  masih > 0*/
/*F.S. Dibaca nilai titik perpindahan. Sebuah unit akan berpindah menuju titik yang dituju*/
	/*Kamus*/
	boolean move;
	/*Algoritma*/ 
	if(MovementsRemain(U)>0){
			ReadMoveValue(&P);
			move = false;
			while(!move){ /*Kondisi pengulangan apabila masukan koordinat petak salah*/
			if(IsSquareEmpty(M,P) && IsSquareAdjacent(U,P)){
				ChangeUnitPos(&U,P);
				move = true;
			}else{
				printf("You can't move there\n");
				ReadMoveValue(&P);
			}
		}
		Mov(U) = MovementsRemain(U) - 1;
	}else{
		printf("You can't move again. Your movement point is not enough\n");
	}
}

/******Procedure to create Undo Command*******/





