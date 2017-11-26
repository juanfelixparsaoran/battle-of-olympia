#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "ListUnit.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList (ListUnit *L){
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

void InsVLast (ListUnit *L, infotype X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != NULL) {
      InsertLast(L,P);
    }
}

void InsertLast (ListUnit *L, address P) {
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

void InsertFirst (ListUnit *L, address P) {
    /* Kamus Lokal */

    /* Algoritma */
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter (ListUnit *L, address P, address Prec) {
  /* Kamus Lokal */

  /* Algoritma */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void DelVFirst (ListUnit *L, infotype *X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = NULL;
    Dealokasi(P);
}

void DelVLast (ListUnit *L, infotype *X) {
     /* Kamus Lokal */
    address P;

    /* Algoritma */
    DelLast(L,P);
    (*X) = Info(P);
    Dealokasi(P);
}

void DelLast (ListUnit *L, address P) {
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
