
/* Module to handle unit list */

#ifndef unitlist_H
#define unitlist_H

#include "unit.h"
#include "map.h"
#include "point.h"
#include <stdlib.h>

typedef POINT infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    int index;
	infotype info;
	address next;
} ElmtList;

typedef address UnitList;

#define Index(P) (P)->index
#define Info(P) (P)->info
#define Next(P) (P)->next


/****************** ADD AND DEL ******************/
UnitList Insert_unit(UnitList L, POINT unit_pos, int indeks);
/* Insert a element into list */

void Delete_unit (UnitList *L, int Index);
/* Delete an element at index X */

POINT get_unit_position(UnitList L, int Index);

void select_unit(MAP *Map, UnitList *Unit_list, UNIT * Current_unit, int Index);
/****************** DISPLAY ******************/
void Display_unit_list (MAP M, UnitList L);
/* Display unit index and unit position */

void show_unit_in_list(UNIT U);
/* Function to show unit data  */

/****************** SHOULD NOT BE USED DIRECTLY ******************/
int UnitList_empty(address L);

address Alokasi_point(infotype X, int indeks);

int UnitNbElmt(UnitList L);

UnitList Tail(UnitList L);

#endif
