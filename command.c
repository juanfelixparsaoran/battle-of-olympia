
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void CreateEmpty(UnitList *L){
	*L = NULL;
}
void Display_enemy_nearby(UNIT Current_Unit,MAP M, UnitList P1, UnitList P2,boolean *adjacent,UnitList *Enemy_Nearby){
	POINT P;
	int i,sum=0;
	if (Owner(Current_Unit) == 1){
		for (i=0;i<=UnitNbElmt(P2);i++){
			P = get_unit_position(P2,i);
			if (abs(Absis(Pos(Current_Unit)) - Absis(P)) + abs(Ordinat(Pos(Current_Unit)) - Ordinat(P)) == 1){
				sum += 1;
				printf("%d. ",sum);
				show_unit_in_list(Unit(M, Absis(P), Ordinat(P)));
				*Enemy_Nearby = Insert_unit(*Enemy_Nearby,P,sum-1);
			}
		}
		if (sum==0){
			*adjacent = false;
		}else{
			*adjacent = true;
		}
	}else if (Owner(Current_Unit) == 2){
		for (i=1;i<=UnitNbElmt(P1);i++){
		P = get_unit_position(P1,i);
		if (abs(Absis(Pos(Current_Unit)) - Absis(P)) + abs(Ordinat(Pos(Current_Unit)) - Ordinat(P)) == 1){
				sum += 1;
				printf("%d. ",sum);
				show_unit_in_list(Unit(M, Absis(P), Ordinat(P)));
				*Enemy_Nearby= Insert_unit(*Enemy_Nearby,P,i);
			}
		}
		if (sum==0){
			*adjacent = false;
		}else{
			*adjacent = true;
		}
	}
}

void attack(UNIT *Current_Unit,MAP *M,UnitList *P1, UnitList *P2, boolean *can_attack){
	boolean adjacent;
	UnitList Enemy_Nearby;
	int pilihserang;
	if(*can_attack){
			CreateEmpty(&Enemy_Nearby);
			Display_enemy_nearby(*Current_Unit,*M,*P1,*P2,&adjacent,&Enemy_Nearby);
			if (adjacent){
				printf("\nPilih musuh yang akan diserang : \n"); scanf("%d",&pilihserang); /* pilihserang == indeks di enemy_nearby*/
				address P = Enemy_Nearby;
				while(P != NULL){
					if(Index(P) == pilihserang){
						if(Atk_Type(*Current_Unit) == Atk_Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) ||
						Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) != 'K'){ /*retaliates*/
							Hp(*Current_Unit) -= Atk(Unit(*M,Absis(Info(P)),Ordinat(Info(P))));
							Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) -= Atk(*Current_Unit);
							printf("enemy unit take %d damage\n",Atk(*Current_Unit));
							printf("your unit take %d damage\n",Atk(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))));
						}else if((Atk_Type(*Current_Unit) != Atk_Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P))))) ||
						(Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P))))-Atk(*Current_Unit) == 0)){
							Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) -= Atk(*Current_Unit);
							printf("enemy unit take %d damage\n",Atk(*Current_Unit));
						}
						
						if (Hp(*Current_Unit) == 0){
							printf("Your unit has been killed\n");
							Type(*Current_Unit) = Nil;
							Delete_unit(P1,Index(P));
						}
						if (Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) == 0){
							printf("Enemy unit has been killed\n");
							Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) = Nil;
							Delete_unit(P2,Index(P));
						}
						break;
					}
					P = Next(P);
				}
				*can_attack = false;
			}else{
				printf("no enemy nearby..\n\n");
			}
	}else{
		printf("this unit cant attack in this turn\n\n");
	}

}



void Recruit(Player *P,int *type, MAP *M, POINT *Point,UNIT U){
	if (Type(U) == 'K' && VillageType(Village(*M,Absis(Pos(U)),Ordinat(Pos(U)))) == 'T'){
		printf("Masukkan koordinat castle yang kosong : "); BacaPOINT(Point);
		int x = Absis(*Point);
		int y = Ordinat(*Point);
		if ((Type(Unit(*M,x,y)) != Nil) || VillageType(Village(*M,x,y)) != 'C' || VillageOwner(Village(*M,x,y)) != ID(*P)){
			printf("castle is not empty or it's not your castle or it's not a castle\n\n");
		}else{
			printf("List Unit\n");
			printf("1 Archer | Health : 100 | ATK : 15 | DEF : 15 | 1G\n");
			printf("2 Swordsman | Health : 100 | ATK : 20 | DEF : 15 | 2G\n");
			printf("Pilih yang mau direkruit\n"); scanf("%d",type);
			int Cost;
			if (*type ==1){
				Cost = 1;
			}else if(*type ==2){
				Cost = 2;
			}else{
				printf("wrong input");
			}

			if (gold(*P) >= Cost){
				if (*type==1){
					Unit(*M, x, y) = Create_new_unit('A', ID(*P), x ,y);
					units(*P) = Insert_unit(units(*P), *Point, UnitNbElmt(units(*P)));
				}else if (*type==2){
					Unit(*M, x, y) = Create_new_unit('S', ID(*P), x ,y);
					units(*P) = Insert_unit(units(*P), *Point, UnitNbElmt(units(*P)));
				}else{
					printf("wrong input");
				}
				gold(*P) -= Cost;
				upkeep(*P) += Cost; 

			}else{
				printf("Not enough money :(..\n\n");
			}
		}
	}else{
		printf("current unit is not a king or your king position is not in tower\n\n");
	}
}

void CHANGE_UNIT (MAP M,Queue QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT *Current_unit) {
    int x;
    if (InfoHead(QTURN)==1){
        printf("Unit List of Player 1 :\n");
        Display_unit_list (M, ListUnitP1);
        printf("Please enter the no. Unit: \n");
        scanf("%d",&x);
        select_unit(&M,&ListUnitP1,Current_unit,x);
    }
    else {
        printf("Unit List of Player 2 :\n");
        Display_unit_list (M, ListUnitP2);
        printf("Please enter the no. Unit: \n");
        scanf("%d",&x);
		select_unit(&M,&ListUnitP2,Current_unit,x);		
	}
}

void END_TURN(MAP M,Queue *QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT *Current_UNIT){
        int x,i;
        if (InfoHead(*QTURN)==1){
					for (i=1;i<=UnitNbElmt(ListUnitP1);i++){
						Mov(*Current_UNIT) = M_Mov(*Current_UNIT);
						Can_Atk(*Current_UNIT)		= true;
					}
        }
        else{
          for (i=1;i<=UnitNbElmt(ListUnitP2);i++){
          Mov(*Current_UNIT) = M_Mov(*Current_UNIT);
          Can_Atk(*Current_UNIT)		= true;
        	}
			  }
				Del(QTURN,&x);
				Add(QTURN,x);
}

void INFO (MAP M,int i,int j){
    printf("== Cell Info ==\n");
    if(VillageType(Village(M, i, j)) == Nil){
        printf("Normal\n");
    }
    else if(VillageType(Village(M, i, j)) == 'T'){
        printf("Tower\n");
        printf("Owned by Player %d\n",VillageOwner(Village(M, i, j)));
    }
    else if (VillageType(Village(M, i, j)) == 'C'){
        printf("Castle\n");
        printf("Owned by Player %d\n",VillageOwner(Village(M, i, j)));
    }
    else if (VillageType(Village(M, i, j)) == 'V'){
        printf("Village\n");
        if(VillageOwner(Village(M, i, j))==1){
        printf("Owned by Player 1\n");
        }
        else if(VillageOwner(Village(M, i, j))==2){
        printf("Owned by Player 2\n");
        }
        else {
        printf("Not Owned by both Player\n");
        }
    }
    printf("\n");
    printf("== Unit Info ==\n");
    if (Type(Unit(M, i, j)) == Nil){
        printf("No Unit\n");
    }
    else if (Type(Unit(M, i, j)) == 'K'){
        printf("King\n");
        if (Owner(Unit(M,i,j))==1){
          printf("Owned by Player 1\n");
        }
        else if (Owner(Unit(M,i,j))==2){
          printf("Owned by Player 2\n");
        }
    }
    else if (Type(Unit(M, i, j)) == 'A'){
        printf("Archer\n");
        if (Owner(Unit(M,i,j))==1){
          printf("Owned by Player 1\n");
        }
        else if (Owner(Unit(M,i,j))==2){
          printf("Owned by Player 2\n");
        }
    }
    else if (Type(Unit(M, i, j)) == 'S'){
        printf("Swordsman\n");
        if (Owner(Unit(M,i,j))==1){
          printf("Owned by Player 1\n");
        }
        else if (Owner(Unit(M,i,j))==2){
          printf("Owned by Player 2\n");
        }
    }
	printf("\n");

}

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

void ChangeUnitPos(UNIT *U ,POINT P, MAP *M, Player *Play){
/*I.S. Unit siap dipindahkan ke sebuah petak. Dibaca sebuah titik*/
/*F.S. Unit berpindah ke sebuah petak yang adjacent dengan petak sebelumnya*/
	Unit(*M, Absis(P), Ordinat(P))= Create_new_unit(Type(*U), ID(*Play), Absis(P) ,Ordinat(P));
	Type(Unit(*M, Absis(Pos(*U)), Ordinat(Pos(*U))))= Nil;
	Absis(Info(units(*Play)))=Absis(P);
	Ordinat(Info(units(*Play)))=Ordinat(P);
}

boolean IsSquareAdjacent(UNIT U , POINT P){
/*I.S. Dibaca sebuah koordinat petak*/
/*F.S. Sebuah koordinat petak yang adjacent dengan petak posisi unit*/
	return (abs(Absis(Pos(U)) - Absis(P)) + abs(Ordinat(Pos(U)) - Ordinat(P)) == 1);
}

void Move(MAP *M , UNIT *U , POINT P, Player *Play, Stack *S){
/*I.S. Unit pada sebuah petak, siap untuk berpindah ke petak lain. Unit dapat berpindah ke sebuah petak apabila 
	   Petak yang akan ditempati masih kosong dan movement pointnya  masih > 0*/
/*F.S. Dibaca nilai titik perpindahan. Sebuah unit akan berpindah menuju titik yang dituju*/
	/*Algoritma*/
	if(MovementsRemain(*U)>0){
			while(!IsSquareEmpty(*M,P) || !IsSquareAdjacent(*U,P)){
				printf("You can't move there, please enter valid coordinate\n");
				ReadMoveValue(&P);
			}
			Push(S,P);
			ChangeUnitPos(U,P,M,Play);
			Mov(Unit(*M,Absis(Info(units(*Play))), Ordinat(Info(units(*Play))))) -= 1;
			Mov(*U) -= 1;
			printf("You have succesfully moved to");printf(" "); TulisPOINT(P); printf("\n");
	}else{
		printf("You can't move again. Your movement point is not enough\n");
	}
}

/******Procedure to create Undo Command*******/
void Undo(POINT *P,UNIT *U , Stack *S, MAP *M, Player *Play){
	if (IsEmpty2(*S)){
		printf("You can't undo. You haven't move yet\n");
	}else{
	Pop(S,P);
	ChangeUnitPos(U,*P,M,Play);
	Mov(Unit(*M, Absis(*P), Ordinat(*P))) += 1;
	}	
}

/******Procedure to create Undo Command*******/
