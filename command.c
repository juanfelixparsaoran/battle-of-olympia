
#include "command.h"

#include <math.h>

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

void attack(UNIT *Current_Unit,MAP *M,UnitList *P1, UnitList *P2, boolean *can_attack){
	if(*can_attack){
		boolean adjacent;
		UnitList Enemy_Nearby;
		int pilihserang;
		Display_enemy_nearby(*Current_Unit,*M,*P1,*P2,&adjacent,&Enemy_Nearby);
		if (adjacent == false){
			printf("no enemy nearby\n\n");
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
		*can_attack = false;
		}
	}else{
		printf("this unit cant attack in this turn\n\n");
	}
			
}



void Recruit(Player *P,int *type, MAP *M, POINT *Point,UNIT U){
	if (Type(U) == 'K' && VillageType(Village(*M,Absis(Pos(U)),Ordinat(Pos(U)))) == 'T'){
		BacaPOINT(Point);
		int x = Absis(*Point);
		int y = Ordinat(*Point);
		if ((Type(Unit(*M,x,y)) != Nil) || VillageType(Village(*M,x,y)) != 'C' || VillageOwner(Village(*M,x,y)) != ID(*P)){
			printf("castle is not empty or it's not your castle or it's not a castle\n\n");
		}else{
			printf("List Unit\n");
			printf("1 Archer 	| Health : 100 | ATK : 15 | DEF : 15 | 1G\n");
			printf("2 Swordsman | Health : 100 | ATK : 20 | DEF : 15 | 2G\n");
			printf("Pilih yang mau direkruit\n"); scanf("%d",type);
			int Cost;
			if (*type ==1){
				Cost = 1;
			}else if(*type ==2){
				Cost = 2;
			}
			
			if (gold(*P) >= Cost){
				if (*type==1){
					Unit(*M, x, y) = Create_new_unit('A', ID(*P), x ,y);
					units(*P) = Insert_unit(units(*P), *Point, UnitNbElmt(units(*P)));
				}else if (*type==2){
					Unit(*M, x, y) = Create_new_unit('S', ID(*P), x ,y);
					units(*P) = Insert_unit(units(*P), *Point, UnitNbElmt(units(*P)));
				}
				gold(*P) -= Cost;
				
			}else{
				printf("Not enough money :(..\n\n");
			}
		}
	}else{
		printf("current unit is not a king or your king position is not in tower\n\n");
	}
}
		
				
		
		
		
		
		
	
	
	
					
		