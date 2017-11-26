#ifndef MATRIKSPETAK_H
#define MATRIKSPETAK_H

#include "villages.h"
#include "unit.h"
#include "boolean.h"

#define BrsMin 0
#define BrsMax 25
#define KolMin 0
#define KolMax 25

typedef struct {
	UNIT chr;	//karakter
	VILLAGES bld;	//building
	boolean move;
	boolean select;
} PETAK;

typedef struct {
	PETAK P[BrsMax][KolMax]; /*	Matriks */
	int NBrsEff; /*	banyaknya/ukuran baris yang terdefinisi */
	int NKolEff; /*	banyaknya/ukuran kolom yang terdefinisi */
} MATRIKS;

#define matriks_NBrsEff(M) (M).NBrsEff
#define matriks_NKolEff(M) (M).NKolEff
#define matriks_Elmt(M,i,j) (M).P[(i)][(j)]

void matriks_MakeMATRIKS(int NB, int NK, MATRIKS * M);

boolean matriks_IsIdxValid(int i, int j);

#endif
