#ifndef chessmasters_funciones_h
#define chessmasters_funciones_h

#include <stdio.h>
#include "chessmasters_piezas.h"
#include "chessmasters_menu.h"

void reinicio_juego(int *contador_movimientos, char tablero[8][8]);
void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8]);
int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos, char tablero[8][8]);
void tablero_inicial(char tablero[8][8]);
void imprimir_tablero(char tablero[8][8]);
int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);
void coronar(int *i_inicial, int *j_inicial,int *i_final, int *j_final, char tablero[8][8]);

#endif /* chessmasters_funciones_h */
