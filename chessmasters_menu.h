#ifndef chessmasters_menu_h
#define chessmasters_menu_h

#include <stdio.h>
#include "chessmasters_funciones.h"
#include "chessmasters_ficheros.h"
typedef struct{
        char name[30];
} player;
int menu_principal();
int menu_partida(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos, char tablero[8][8],int mov_enroque[6]);


#endif /* chessmasters_menu_h */
