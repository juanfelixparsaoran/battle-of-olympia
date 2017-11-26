#ifndef LISTVILLAGES_H
#define LISTVILLAGES_H

#include "boolean.h"
#include "point.h"
#include "villages.h"
#include <stdio.h>
#include <stdlib.h>

typedef VILLAGES infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype Info;
	address Next;
} ElmtList;
typedef address ListVillages

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define First(L) (L)

void CreateList (ListVillages *L);

address Alokasi (infotype X);

void Dealokasi (address *P);

void InsVLast (ListVillages *L, infotype X);

void DelLast (ListVillages *L, address P);

void InsertLast (ListVillages *L, address P);

void InsertFirst (ListVillages *L, address P);

void InsertAfter (ListVillages *L, address P, address Prec);

/* Penghapusan ELemen */
void DelVFirst (ListVillages *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
void DelVLast (ListVillages *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */

#endif
