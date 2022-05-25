#include <stdio.h>
#include "chessmasters_piezas.h"
#include "chessmasters_funciones.h"


int main() {
    int i_0,j_0,i_1,j_1,contador=1,fin_partida=0;
    char tablero[8][8];
    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    do{
        introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador,tablero);
        if (introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador,tablero)==0) {
            if (comprobar(&i_0,&j_0,&i_1,&j_1,tablero)==0){
                mover_pieza(i_0,j_0,i_1,j_1,tablero);
            }else{
                printf("Introduzca un movimiento valido");
            }
        }else{
            printf("Introduzca un movimiento valido");
        }
        

    }while(fin_partida==0);



    return 0;
}
