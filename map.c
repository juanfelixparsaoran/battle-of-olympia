// body map.h

#include "map.h"
#include <stdio.h>
#include <stdlib.h>


// ----------Constructor----------
void createMap(MAP *M, int row, int col) {
	matriks_MakeMATRIKS(row, col, M);

	for (int i = 0; i <= MapBrsEff(*M); i++) {
		for (int j = 0; j <= MapKolEff(*M); j++) {
			VillageType(Village(*M, i, j)) = Nil;
			Unit(*M, i, j).unit_type = Nil;
		}
	}

}
// membuat map berukuran baris row dan kolom col

MAP Init_map() {
	MAP M;
	int col, row;
	printf("input your size of map (ex : 8 8): ");
	scanf("%d %d", &row, &col);
	while (!map_IsIdxValid(row,col)) {
		printf("size is not allowed. please input again :");
		scanf("%d %d", &row, &col);
	}
	createMap(&M,row,col);
	return M;
}

// ----------Output----------
void printMap(MAP M) {
	int i, j;

	printf("  ");
	for (j = 0; j <= MapKolEff(M); j++) {
		if (j <= 9) {
			printf("   %d", j);
		}
		else {
			printf("  %d", j);
		}
	}
	printf("\n   ");

	for (i = 0; i <= MapBrsEff(M); i++) {
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("****");
		}
		printf("*\n   ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (VillageType(Village(M, i, j)) == Nil) {
				printf("  ");
			}
			else {
				if(VillageOwner(Village(M, i, j))==1){
					//print_red(VillageType(Village(M, i, j)));
					printf("%c", VillageType(Village(M, i, j)));
					printf(" ");
				}else if(VillageOwner(Village(M, i, j))==2){
					//print_blue(VillageType(Village(M, i, j)));
					printf("%c", VillageType(Village(M, i, j)));
					printf(" ");
				}else{
					//print_magenta(VillageType(Village(M, i, j)));
					printf("%c", VillageType(Village(M, i, j)));
					printf(" ");
				}
			}
		}
		printf("*\n");
		if (i <= 9) {
			printf("%d  ", i);
		}
		else {
			printf("%d ", i);
		}
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (Type(Unit(M, i, j)) == Nil) {
				printf("  ");
			}
			else {
				printf("%c ", Type(Unit(M, i, j)));
				/*if (Owner(Unit(M, i, j)) == 1) {
					print_red(Type(Unit(M, i, j)));
					printf(" ");
				}
				else if (Owner(Unit(M, i, j)) == 2) {
					print_blue(Type(Unit(M, i, j)));
					printf(" ");
				}
				else {
					printf("%c ", Type(Unit(M, i, j)));
				}*/
			}
		}
		printf("*\n   ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("*   ");
		}
		printf("*\n   ");
	}
	for (j = 0; j <= MapKolEff(M); j++) {
		printf("****");
	}
	printf("*\n");
}

boolean map_IsIdxValid(int row, int col) {
	return col >= 8 && col <= KolMax && row <= BrsMax && row >= 8;
}
