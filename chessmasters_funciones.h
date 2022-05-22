#ifndef chessmasters_funciones_h
#define chessmasters_funciones_h

#include <stdio.h>
#include "chessmasters_piezas.h"

void tablero_inicial(char tablero[8][8]);
void imprimir_tablero(char tablero[8][8]);
int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);


#endif /* chessmasters_funciones_h */
