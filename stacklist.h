/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include "point.h"
#include <stdlib.h>

/* Konstanta */
#define Nul NULL
/* Deklarasi infotype */
typedef POINT infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address2;
typedef struct tElmtStack { 
	infotype InfoS;
	address2 NextS; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
	address2 TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info 
#define NextS(P) (P)->NextS
#define InfoS(P) (P)->InfoS

/* Prototype manajemen memori */
void Alokasi2 (address2 *P, infotype X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi2 (address2 P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty2 (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty2 (Stack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infotype * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif