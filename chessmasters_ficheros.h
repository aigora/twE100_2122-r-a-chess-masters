#ifndef chessmasters_ficheros_h
#define chessmasters_ficheros_h

#include <stdio.h>
#include <string.h>
typedef struct{
        char name[30];
} player;
int imprimir_reglas();
int guardar_partida(int *contador_movimientos, char tablero[8][8]);
int cargar_partida();


#endif /* chessmasters_ficheros_h */
