#include <stdio.h>
#include <stdlib.h>
#include "unitlist.h"
#include "villagelist.h"
#include "matriksPetak.h"
#include "player.h"
#include "point.h"
#include "unit.h"
#include "villages.h"
#include "startingGame.h"
#include "command.c"

#define NEWLINE printf("\n" );

int main(){

  int pilihanMenu;
  MAP M;

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
      break;
    case 2:
      break;
    default:
      break;
  }

  return 0;
}
