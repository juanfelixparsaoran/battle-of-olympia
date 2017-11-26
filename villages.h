#ifndef VILLAGES_H
#define VILLAGES_H

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

typedef struct{
    char type;
    int owner;
    POINT position;
}VILLAGES;

#define VillageType(B) (B).type
#define VillageOwner(B) (B).owner
#define VillagePos(B) (B).position

void initVillage(VILLAGES *B, char type, int owner, int x, int y);

VILLAGES createNewVillage(char type, int owner, int x, int y);

void printVillageType(VILLAGES B);


#endif
