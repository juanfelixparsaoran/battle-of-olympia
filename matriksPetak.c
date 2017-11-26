#include "matriksPetak.h"

void matriks_MakeMATRIKS(int NB, int NK, MATRIKS * M){
	matriks_NBrsEff(*M) = NB-1;
  matriks_NKolEff(*M) = NK-1;
}

boolean matriks_IsIdxValid(int i, int j){
	return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}
