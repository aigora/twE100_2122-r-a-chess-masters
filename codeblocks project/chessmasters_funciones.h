#ifndef chessmasters_funciones_h
#define chessmasters_funciones_h

#include <stdio.h>
#include "chessmasters_piezas.h"
#include "chessmasters_menu.h"
#include "chessmasters_ficheros.h"
#include <stdlib.h>

typedef struct
{
  int matriz[8][8];

} eval;

int menu_principal();
int menu_partida(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos, char tablero[8][8],int mov_enroque[6]);


void captura_alpaso(int i_anterior, int j_anterior, int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos, char tablero[8][8], int mov_enroque[6]);
void limpiar_pantalla();
void inicio_juego(int *contador_movimientos, char tablero[8][8], int mov_enroque[6]);
void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8], int mov_enroque[6]);
int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos, char tablero[8][8], int mov_enroque[6]);
void tablero_inicial(char tablero[8][8]);
void imprimir_tablero(char tablero[8][8]);
int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int *contador_movimientos);
void coronar(int *i_inicial, int *j_inicial,int *i_final, int *j_final, char tablero[8][8]);
void enrocar(int mov_enroque[6]);
void matrices_evaluacion(int blancas_defensa[8][8],int negras_defensa[8][8]);
void inicializar_matrices(eval piezas[32]);
void coronar(int *i_inicial, int *j_inicial,int *i_final, int *j_final, char tablero[8][8]);

#endif /* chessmasters_funciones_h */
