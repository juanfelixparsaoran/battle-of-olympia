
/* Module to handle village list */

#include "villagelist.h"
#include <stdio.h>

/****************** LIST INFO ******************/
int VillageList_empty(village_address L)
/* Check wether village list is empty or not */
{
    return L == NULL;
}

village_address Alokasi_village_point(infotype X, int indeks)
    /* return village_address of new alocated element */
{
    VillageElmtList *P = (VillageElmtList *) malloc(sizeof(VillageElmtList));

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

int VillageNbElmt(VillageList L)
    /* Element amount */
{
    if (!VillageList_empty(L)){
        return 1 + VillageNbElmt(VillageTail(L));
    }
    else{
        return 0;
    }
}


VillageList VillageTail(VillageList L)
{
    return Next(L);
}

/* ***************** ADD AND DEL ***************** */
VillageList Insert_village(VillageList L, POINT village_pos, int indeks)
/* Insert a element into list */
{
    if (VillageList_empty(L)){
        return Alokasi_village_point(village_pos, indeks);
    }

    else{
        Next(L) = Insert_village(VillageTail(L), village_pos, indeks);
        return L;
    }
}


void Delete_village (VillageList L, int Index)
/* Delete an element at index X */
{

    village_address Prec = NULL;
    village_address Current = L;
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

POINT get_village_position(VillageList L, int Index){
    /* Function to return village position stored in villagelist by indexing */

    if (VillageList_empty(L)){
        return MakePOINT(-999,-999);
    } else if (Index(L) == Index){
        return Info(L);
    } else{
        return get_village_position(VillageTail(L), Index);
    }
}

/****************** DISPLAY ******************/
void Display_village_list (MAP M, VillageList L)
    /* Display village index and village position */
{
    if (!VillageList_empty(L)){

        printf("%d. ",Index(L));

        POINT village_pos = get_village_position(L, Index(L));
        show_village_in_list(Village(M, Absis(village_pos), Ordinat(village_pos)));
        printf("\n");
        Display_village_list(M, VillageTail(L));
    }
}

void show_village_in_list(VILLAGES U){
/* Function to show village data */
    printf("  ");
    TulisPOINT(VillagePos(U));
}
