
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


void Recruit(Player *P,int type, MAP *M, POINT Point){
	int x = Absis(Point);
	int y = Ordinat(Point);
	if (Type(Unit(*M,x,y)) != Nil){
		printf("lagi ada orang disitu\n");
	}else{
		int Cost;
		if (type ==1){
			Cost = 100;
		}else{
			Cost = 200;
		}
		
		if (gold(*P) >= Cost){
			units(*P) = Insert_unit(units(*P), Point, UnitNbElmt(units(*P)));
			
		}else{
			printf("uangmu gak cukup oi\n");
		}
	}
}
		
				
		
		
		
		
		
	
	
	
					
		