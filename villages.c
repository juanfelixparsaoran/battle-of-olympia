
#include "villages.h"

void initVillage(VILLAGES *B, char type, int owner, int x, int y) {
	VillageType(*B) = type;
	VillageOwner(*B) = owner;
	VillagePos(*B) = MakePOINT(x, y);
}

VILLAGES createNewVillage(char type, int owner, int x, int y) {
	VILLAGES new_build;

	initVillage(&new_build, type, owner, x, y);
	return new_build;
}

void printVillageType(VILLAGES B) {
	char type = VillageType(B);
	if (type=='C'){
		printf("Castle");
	}
	else if (type=='T'){
		printf("Tower");
	}
	else if (type=='V'){
		printf("Village");
	}
}
