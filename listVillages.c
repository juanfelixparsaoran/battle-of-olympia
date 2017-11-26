#include "boolean.h"
#include "point.h"
#include "villages.h"
#include "listVillages.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList (ListVillages *L){
  First(*L) = NULL;
}

address Alokasi (infotype X){
  address P;

  /* Algoritma */
  P = (address) malloc (sizeof (ElmtList));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = NULL;
    return P;
  } else {
    return NULL;
  }
}

void Dealokasi (address *P){
  free(*P);
}

void InsVLast (ListVillages *L, infotype X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != NULL) {
      InsertLast(L,P);
    }
}

void InsertFirst (ListVillages *L, address P) {
    /* Kamus Lokal */

    /* Algoritma */
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter (ListVillages *L, address P, address Prec) {
  /* Kamus Lokal */

  /* Algoritma */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (ListVillages *L, address P) {
    /* Kamus Lokal */
    address Last;

    /* Algoritma */
    Last = First(*L);
    if (First(*L) == NULL) {
      InsertFirst(L,P);
    } else {
      while (Next(Last) != NULL) {
        Last = Next(Last);
      }
      InsertAfter(L,P,Last)
    }
}

void DelVFirst (ListVillages *L, infotype *X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = NULL;
    Dealokasi(P);
}

void DelVLast (ListVillages *L, infotype *X) {
     /* Kamus Lokal */
    address P;

    /* Algoritma */
    DelLast(L,P);
    (*X) = Info(P);
    Dealokasi(P);
}

void DelLast (ListVillages *L, address P) {
  /* Kamus Lokal */
  address Last, PrecLast;

  /* Algoritma */
  Last = First(*L);
  PrecLast = NULL;
  while (Next(Last) != NULL) {
    PrecLast = Last;
    Last = Next(Last);
  }
  P = Last;
  if (PrecLast == NULL) {
    First(*L) = NULL;
  } else {
    Next(PrecLast) = NULL;
  }
}
