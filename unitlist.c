
/* Module to handle unit list */

#include "unitlist.h"
#include <stdio.h>

/****************** LIST INFO ******************/
int UnitList_empty(address L)
/* Check wether unit list is empty or not */
{
    return L == NULL;
}


address Alokasi_point(infotype X, int indeks)
    /* return Address of new alocated element */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));

    if (P != NULL){

        Index(P) = indeks + 1;
        Info(P) = X;
        Next(P) = NULL;
        return P;
    }
    else {
        return NULL;
    }
}


int UnitNbElmt(UnitList L)
    /* Element amount */
{
    if (!UnitList_empty(L)){
        return 1 + UnitNbElmt(Tail(L));
    }
    else{
        return 0;
    }
}


UnitList Tail(UnitList L)
{
    return Next(L);
}

/****************** ADD AND DEL ******************/
UnitList Insert_unit(UnitList L, POINT unit_pos, int indeks)
/* Insert a element into list */
{
    if (UnitList_empty(L)){
        return Alokasi_point(unit_pos, indeks);
    }

    else{
        Next(L) = Insert_unit(Tail(L), unit_pos, indeks);
        return L;
    }
}


void Delete_unit (UnitList L, int Index)
/* Delete an element at index X */
{

    address Prec = NULL;
    address Current = L;
    int found = 0;

    while((Current != NULL) && !found){

        if (Index(Current) == Index){
            found = 1;
        }

        else{

            Prec = Current;
            Current = Next(Current);
        }
    }

    if (found){

        Next(Prec) = Next(Current);
        free(Current);
    }
}

POINT get_unit_position(UnitList L, int Index){
    /* Function to return unit position stored in unitlist by indexing */

    if (UnitList_empty(L)){
        return MakePOINT(-999,-999);
    }

    else if (Index(L) == Index){
        return Info(L);
    }

    else{
        return get_unit_position(Tail(L), Index);
    }
}


void select_unit(MAP Map, UnitList Unit_list, UNIT * Current_unit, int Index){

    POINT unit_pos = get_unit_position(Unit_list, Index);
    int i = Absis(unit_pos);
    int j = Ordinat(unit_pos);

    if ( (i >= 0) && (i <= MapBrsEff(Map)) && (j >= 0) && (j <= MapKolEff(Map))){
        *Current_unit = Unit(Map,i,j);
        printf("current unit : unit < %.2d > \n", Index);
    }
    else{
        printf("You don't have such unit...\n");
    }
}


/****************** DISPLAY ******************/
void Display_unit_list (MAP M, UnitList L)
    /* Display unit index and unit position */
{
    if (!UnitList_empty(L)){

        printf("%d. ",Index(L));

        POINT unit_pos = get_unit_position(L, Index(L));
        show_unit_in_list(Unit(M, Absis(unit_pos), Ordinat(unit_pos)));
        printf("\n");
        Display_unit_list(M, Tail(L));
    }
}

void show_unit_in_list(UNIT U){
/* Function to show unit data */
    print_unit_type(U);
    printf("  ");
    TulisPOINT(Pos(U));
    printf(" | ");
    printf("Health %d", Hp(U));
}
