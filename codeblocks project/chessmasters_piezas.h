#ifndef chessmasters_piezas_h
#define chessmasters_piezas_h

#include <stdio.h>

int peones (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int eval_aux[8][8]);
int caballos (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int eval_aux[8][8]);
int alfiles (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int eval_aux[8][8]);
int torres (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int eval_aux[8][8]);
int reyes (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int eval_aux[8][8]);
int damas (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int eval_aux[8][8]);

#endif /* chessmasters_piezas_h */
