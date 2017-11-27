#include <stdio.h>
#include <stdlib.h>
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
#include "queue.h"
#include "stacklist.h"
#include <string.h>

#define NEWLINE printf("\n" );

int main(){

  int pilihanMenu;
  MAP M;
  int type;
  char command[10];
  Queue Qturn;
  Stack S,S2;
  CreateEmpty2(&S);
  CreateEmpty2(&S2);

  Player P1 = create_new_player(1);
  Player P2 = create_new_player(2);

  printf("SELAMAT DATANG DI BATTLE OF OLYMPIA!\n");
  printf("Silahkan Pilih menu :\n" );
  printf("1. Start Game\n" );
  printf("2. Exit\n" );
  printf("Pilih menu : ");
  scanf("%d",&pilihanMenu);
  while(pilihanMenu != 1 && pilihanMenu!=2){
		printf("Wrong Input, please try again\n");
		scanf("%d",&pilihanMenu);
  }
	if (pilihanMenu==1){
		  NEWLINE;
		  M = Init_map();
		  setStartGame(&M, &P1, &P2);
		  printMap(M);
		  POINT info,recruit,move,RajaP1,RajaP2,undo;
		  CreateEmpty1(&Qturn,2);
		  Add(&Qturn,1);
		  Add(&Qturn,2);
		 
		  RajaP1 = get_unit_position(units(P1),1);
		  RajaP2 = get_unit_position(units(P2),1);
		  while(Hp(Unit(M,Absis(RajaP1),Ordinat(RajaP1))) > 0 && Hp(Unit(M,Absis(RajaP1),Ordinat(RajaP1))) > 0){
			  if(InfoHead(Qturn)==1){
				  Print_Player_Info(P1,M,Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
				  input_command(&command);
				  if (strcmp(command,"attack") == 0){
					  attack(&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))),&M,&units(P1), &units(P2),&Can_Atk(Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1))))));
				  }else if (strcmp(command,"recruit") == 0){
					  Recruit(&P1,&type, &M, &recruit,Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
				  }else if(strcmp(command,"map") ==0 ){
					  printMap(M);
				  }else if(strcmp(command,"change_unit") == 0){
					  CHANGE_UNIT(M,Qturn,units(P1),units(P2),&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
				  }else if(strcmp(command,"end_turn") == 0){
					  END_TURN(M,&Qturn,units(P1),units(P2),&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
				  }else if(strcmp(command,"info") == 0){
					  printf("Masukkan koordinat map : "); BacaPOINT(&info);
					  INFO(M,Absis(info),Ordinat(info));
				  }else if(strcmp(command,"move") == 0){
					  Push(&S,MakePOINT(Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
					  printf("Masukkan koordinat tujuan : ");
					  Move(&M ,&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))),move,&P1);
					  if(VillageType(Village(M,Absis(Info(units(P1))),Ordinat(Info(units(P1))))) == 'V'){
						  printf("You captured a village");
						  VillageOwner(Village(M,Absis(Info(units(P1))),Ordinat(Info(units(P1))))) = '1';
						  income(P1) += 3;
					  }
				  }else if(strcmp(command,"undo") == 0){
					  Undo(&undo,&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))),&S,&M,&P1);
				  }else if(strcmp(command,"exit") == 0){
					  printf("Thanks for playing this game...\n");
					  sleep(4);
					  exit(0);
				  }else{
					  printf("Wrong Command!!\n\n");
				  }
			  }else{
				  Print_Player_Info(P2,M,Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))));
				  input_command(&command);
				  if (strcmp(command,"attack") == 0){
					  attack(&Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))),&M,&units(P1), &units(P2),&Can_Atk(Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2))))));
				  }else if (strcmp(command,"recruit") == 0){
					  Recruit(&P2,&type, &M, &recruit,Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))));
				  }else if(strcmp(command,"map") ==0 ){
					  printMap(M);
				  }else if(strcmp(command,"change_unit") == 0){
					  CHANGE_UNIT(M,Qturn,units(P1),units(P2),&Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))));
				  }else if(strcmp(command,"end_turn") == 0){
					  END_TURN(M,&Qturn,units(P1),units(P2),&Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))));
				  }else if(strcmp(command,"info") == 0){
					  printf("Masukkan koordinat map : "); BacaPOINT(&info);
					  INFO(M,Absis(info),Ordinat(info));
				  }else if(strcmp(command,"move") == 0){
					  Push(&S2,MakePOINT(Absis(Info(units(P2))),Ordinat(Info(units(P2)))));
					  printf("Masukkan koordinat tujuan : "); 
					  Move(&M ,&Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))) ,move, &P2);
					  if(VillageType(Village(M,Absis(Info(units(P2))),Ordinat(Info(units(P2))))) == 'V'){
						  printf("You captured a village\n");
						  VillageOwner(Village(M,Absis(Info(units(P2))),Ordinat(Info(units(P2))))) = '2';
						  income(P2) += 3;
					  }
				  }else if(strcmp(command,"undo") == 0){
					  Undo(&undo,&Unit(M,Absis(Info(units(P2))),Ordinat(Info(units(P2)))),&S2,&M,&P2);
				  }
			  }
			  RajaP1 = get_unit_position(units(P1),1);
			  RajaP2 = get_unit_position(units(P2),1);
		  }
		  if(Hp(Unit(M,Absis(RajaP1),Ordinat(RajaP1)))<=0){
			printf("Player 2 Win, Congrats!!\n");
		  }else{
	    	printf("Player 1 Win, Congrats!!\n");
		  }
	}else if (pilihanMenu==2){
			printf("Thanks for playing this game...\n");
					  sleep(4);
					  exit(0);
	}

  return 0;
}
