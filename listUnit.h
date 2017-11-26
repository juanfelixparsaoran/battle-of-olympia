#ifndef LISTUNIT_H
#define LISTUNIT_H

#include "boolean.h"
#include "point.h"
#include "unit.h"
#include <stdio.h>
#include <stdlib.h>

typedef UNIT infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype Info;
	address Next;
} ElmtList;
typedef address ListUnit

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define First(L) (L)

void CreateList (ListUnit *L);

address Alokasi (infotype X);

void Dealokasi (address *P);

void InsVLast (ListUnit *L, infotype X);

void InsertLast (ListUnit *L, address P);

void InsertFirst (ListUnit *L, address P);

void InsertAfter (ListUnit *L, address P, address Prec) ;

void DelVFirst (ListUnit *L, infotype *X);

void DelVLast (ListUnit *L, infotype *X) ;

void DelLast (ListUnit *L, address P);


#endif
