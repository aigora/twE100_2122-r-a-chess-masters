#include <stdio.h>
#include "chessmasters_funciones.h"
#include "chessmasters_piezas.h"

void mover_pieza(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, char tablero[8][8]);

void introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos);

int main() {
    int i_0,j_0,i_1,j_1,contador=0;
    char tablero[8][8];
    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador);
     
    
    return 0;
}

void mover_pieza(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, char tablero[8][8]) {
    tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
    tablero[*i_inicial][*j_inicial] = '.';
}

void introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final, int *j_final, int *contador_movimientos) {
    int letra_inicial,numero_inicial,letra_final,numero_final;
    *contador_movimientos++;
    if ((*contador_movimientos%2)==0) {
        printf("\n\tTurno de piezas NEGRAS\n");
    }else{
        printf("\n\tTurno de piezas BLANCAS\n");
    }
    printf("\nIntroduzca coordenadas de la pieza a mover (letra y numero):");
    scanf("%c",&letra_inicial);
    scanf(" %d",&numero_inicial);
    printf("Introduzca las coordenadas donde quiere mover la pieza:");
    scanf("%c",&letra_final);
    scanf(" %d",&numero_final);
}
