#include "startingGame.h"

void setStartGame(MAP *M, Player *P1, Player *P2){

  int absisMap = MapBrsEff(*M);
  int ordinatMap = MapKolEff(*M);

  char towerType = 'T';
  char castleType = 'C';
  char villageType = 'V';
  int totalVillage = (int) ((absisMap+1) * (ordinatMap+1) * 0.05);
  srand (time(NULL));

  //buat titik titik tower dan castle
  POINT towerSatu, towerDua;
  POINT castleSatuP1, castleDuaP1, castleTigaP1, castleEmpatP1;
  POINT castleSatuP2, castleDuaP2, castleTigaP2, castleEmpatP2;

  towerSatu = MakePOINT( absisMap-1, 1);
  towerDua = MakePOINT( 1, ordinatMap-1);
  castleSatuP1 = MakePOINT( Absis(towerSatu), Ordinat(towerSatu)-1);
  castleDuaP1 = MakePOINT( Absis(towerSatu), Ordinat(towerSatu)+1);
  castleTigaP1 = MakePOINT( Absis(towerSatu)-1, Ordinat(towerSatu));
  castleEmpatP1 = MakePOINT( Absis(towerSatu)+1, Ordinat(towerSatu));
  castleSatuP2 = MakePOINT( Absis(towerDua), Ordinat(towerDua)-1);
  castleDuaP2 = MakePOINT( Absis(towerDua), Ordinat(towerDua)+1);
  castleTigaP2 = MakePOINT( Absis(towerDua)-1, Ordinat(towerDua));
  castleEmpatP2 = MakePOINT( Absis(towerDua)+1, Ordinat(towerDua));

  /* taro tower dan castle */
  setElement(M, towerSatu, towerType,1);
  setElement(M, towerDua, towerType,2);

    setElement(M, castleSatuP1, castleType,1);
    setElement(M, castleDuaP1, castleType,1);
    setElement(M, castleTigaP1, castleType,1);
    setElement(M, castleEmpatP1, castleType,1);

    setElement(M, castleSatuP2, castleType,2);
    setElement(M, castleDuaP2, castleType,2);
    setElement(M, castleTigaP2, castleType,2);
    setElement(M, castleEmpatP2, castleType,2);

    while(totalVillage != 0){

        /* Create village location */
        POINT village = MakePOINT(rand() % absisMap, rand() % ordinatMap);

        /* Check enability of map to put village in that position */
        char content = VillageType(Village(*M, Absis(village), Ordinat(village)));

        if (content != castleType && content != towerType && content != villageType){

            /* If possible */
            setElement(M, village, villageType,0);
            totalVillage--;

        }
    }

    /* raja ! */
    Unit(*M, Absis(towerSatu), Ordinat(towerSatu)) = Create_new_unit('K', 1, Absis(towerSatu) ,Ordinat(towerSatu));
    Unit(*M, Absis(towerDua), Ordinat(towerDua)) = Create_new_unit('K', 2, Absis(towerDua) ,Ordinat(towerDua));
    units(*P1) = Insert_unit(units(*P1), towerSatu, UnitNbElmt(units(*P1)));
    units(*P2) = Insert_unit(units(*P2), towerDua, UnitNbElmt(units(*P2)));
}

//set data tempat y ada di indeks map
void setElement(MAP *M, POINT index, char type,int owner){
  VillageType(Village(*M, Absis(index), Ordinat(index))) = type;
  VillageOwner(Village(*M, Absis(index), Ordinat(index))) = owner;
  VillagePos(Village(*M, Absis(index), Ordinat(index))) = index;
}
