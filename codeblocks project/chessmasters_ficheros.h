#ifndef chessmasters_ficheros_h
#define chessmasters_ficheros_h

#include <stdio.h>
#include <string.h>
#include "chessmasters_funciones.h"
#include "chessmasters_menu.h"
typedef struct{
        char name[30];
} player;
int imprimir_reglas();
int guardar_partida(int *contador_movimientos, char tablero[8][8]);
int cargar_partida();


#endif /* chessmasters_ficheros_h */
