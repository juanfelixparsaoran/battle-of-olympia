#include "unitlist.h"
#include "unit.h"
#include "point.h"
#include "map.h"
#include "boolean.h"
#include "player.h"
#include <math.h>
/* queue.h ga jalan */
void Display_enemy_nearby(UNIT Current_Unit,MAP M, UnitList P1, UnitList P2,boolean *adjacent,UnitList *Enemy_Nearby){
	POINT P;
	int i,sum=0;
	if (Owner(Current_Unit) == 1){
		for (i=1;i<=UnitNbElmt(P2);i++){
			P = get_unit_position(P2,i);
			if (abs(Absis(Pos(Current_Unit)) - Absis(P)) + abs(Ordinat(Pos(Current_Unit)) - Ordinat(P)) == 1){
				sum += 1;
				printf("%d. ",sum);
				show_unit_in_list(Unit(M, Absis(P), Ordinat(P)));
				Insert_unit(*Enemy_Nearby,P,i);	
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
				Insert_unit(*Enemy_Nearby,P,i);
			}
		}
		if (sum==0){
			*adjacent = false;
		}else{
			*adjacent = true;
		}
	}
}

void attack(UNIT *Current_Unit,MAP *M,UnitList *P1, UnitList *P2){
	boolean adjacent;
	UnitList Enemy_Nearby;
	int pilihserang;
	Display_enemy_nearby(*Current_Unit,*M,*P1,*P2,&adjacent,&Enemy_Nearby);
	if (adjacent == false){
		printf("no enemy nearby\n");
	}else{
		printf("Pilih musuh yang akan diserang : "); scanf("%d",&pilihserang); /* pilihserang == indeks di enemy_nearby*/
		address P = Enemy_Nearby;
		while(P != NULL){
			if(Index(P) == pilihserang){
				if(Atk_Type(*Current_Unit) == Atk_Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) || 
				Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) != 'K'){ /*retaliates*/
					Hp(*Current_Unit) -= Atk(Unit(*M,Absis(Info(P)),Ordinat(Info(P))));
					Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) -= Atk(*Current_Unit);
				}else if((Atk_Type(*Current_Unit) != Atk_Type(Unit(*M,Absis(Info(P)),Ordinat(Info(P))))) && 
				(Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P))))-Atk(*Current_Unit) == 0)){
					Hp(Unit(*M,Absis(Info(P)),Ordinat(Info(P)))) -= Atk(*Current_Unit);
				}
			}else{
				P = Next(P);
			}
		}
	}
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
        printf("No Unit");
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
}

void END_TURN(MAP M,Queue QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT Current_UNIT){
        int x,i;
        if (InfoHead(QTURN)==1){
        for (i=1;i<=UnitNbElmt(ListUnitP1);i++){
            select_unit(M,ListUnitP1,&Current_UNIT,i);
            Mov(Current_UNIT) = M_Mov(Current_UNIT);
            Can_Atk(Current_UNIT)		= true;
        }
        }
        else{
            for (i=1;i<=UnitNbElmt(ListUnitP2);i++){
            select_unit(M,ListUnitP2,&Current_UNIT,i);
            Mov(Current_UNIT) = M_Mov(Current_UNIT);
            Can_Atk(Current_UNIT)		= true;
        }
        Del(&QTURN,&x);
        Add(&QTURN,x);
	}
}

void CHANGE_UNIT (MAP M,Queue QTURN,UnitList ListUnitP1,UnitList ListUnitP2,UNIT Current_unit) {
    int x;
    if (InfoHead(QTURN)==1){
        printf("Unit List of Player 1 :\n");
        Display_unit_list (M, ListUnitP1);
        printf("Please enter the no. Unit: \n");
        scanf("%d",&x);
        select_unit(M,ListUnitP1,&Current_unit,x);
    }
    else {
        printf("Unit List of Player 2 :\n");
        Display_unit_list (M, ListUnitP2);
        printf("Please enter the no. Unit: \n");
        scanf("%d",&x);
        select_unit(M,ListUnitP2,&Current_unit,x);
	}
}

void Recruit(Player *P,int type, MAP *M, int x, int y){
	if (Type(Unit(*M,x,y)) != Nil){
		printf("lagi ada orang disitu\n");
	}else{
		int Cost;
		if (type ==1){
			Cost = 1;
		}else{
			Cost = 2;
		}
		
		if (gold(*P) >= Cost){
			POINT Point = MakePOINT(x,y);
			units(*P) = Insert_unit(units(*P), Point, UnitNbElmt(units(*P)));
		}else{
			printf("uangmu gak cukup oi\n");
		}
	}
}
		
				
		
		
		
		
		
	
	
	
					
		