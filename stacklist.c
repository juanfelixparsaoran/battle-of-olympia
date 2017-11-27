#include "stacklist.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
/* Prototype manajemen memori */
void Alokasi2 (address2 *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	address2 Q = (address2) malloc(sizeof(infotype));
	InfoS(Q) = X;
	NextS(Q) = Nul;
	*P = Q;
}
void Dealokasi2 (address2 P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
{
	free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty2 (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
	return Top(S)==Nul;
}

void CreateEmpty2 (Stack * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{
	Top(*S)=Nul;
}

void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
	if(IsEmpty2(*S)){
		Alokasi2(&Top(*S),X);
	}else{
		address2 ntop;
		Alokasi2 (&ntop,X);
		if(ntop!=Nul){
			NextS(ntop) = Top(*S);
			Top(*S) = ntop;
		}
	}
}
void Pop (Stack * S, infotype * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
	address2 P;
	P = Top(*S);
	*X = InfoS(P);
	Top(*S) = NextS(P);
	NextS(P) =Nul;
	free(P); 
}
