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
#include <string.h>

#define NEWLINE printf("\n" );

int main(){

  int pilihanMenu;
  MAP M;
  int type;
  char command[10];
  POINT recruit;
  Queue Qturn;

  Player P1 = create_new_player(1);
  Player P2 = create_new_player(2);

  printf("SELAMAT DATANG DI BATTLE OF OLYMPIA!\n");
  printf("Silahkan Pilih menu :\n" );
  printf("1. Start Game\n" );
  printf("2. Exit\n" );
  printf("Pilih menu : ");
  scanf("%d",&pilihanMenu);

  switch (pilihanMenu) {
    case 1:
      NEWLINE;
      M = Init_map();
      setStartGame(&M, &P1, &P2);
      printMap(M);
	  CreateEmpty(&Qturn,2);
	  Add(&Qturn,1);
	  Add(&Qturn,2);
	  while(!UnitList_empty(units(P1)) || !UnitList_empty(units(P1))){
		  Print_Player_Info(P1,M);
		  input_command(&command);
		  if (strcmp(command,"attack") == 0){
			  attack(&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))),&M,&units(P1), &units(P2),&Can_Atk(Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1))))));
		  }else if (strcmp(command,"recruit") == 0){
			  Recruit(&P1,&type, &M, &recruit,Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
		  }else if(strcmp(command,"map") ==0 ){
			  printMap(M);
		  }else if(strcmp(command,"change_unit") == 0){
			  CHANGE_UNIT(M,Qturn,units(P1),units(P2),&Unit(M,Absis(Info(units(P1))),Ordinat(Info(units(P1)))));
		  }			  
			  
	  }
      break;
    case 2:
      break;
    default:
      break;
  }

  return 0;
}
