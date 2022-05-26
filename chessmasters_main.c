#include <stdio.h>
#include "chessmasters_piezas.h"
#include "chessmasters_funciones.h"
#include "chessmasters_menu.h"


int main() {
    int i_0,j_0,i_1,j_1,contador=1,fin_partida=0;
    char tablero[8][8];


    int retorno_introduce_coordenadas,retorno_comprobar;
    menu_principal();
    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    do{
        retorno_introduce_coordenadas = introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador,tablero);
        printf("\nretorno_introduce_coordenadas=%d\n",retorno_introduce_coordenadas);//test

        if ((retorno_introduce_coordenadas)==0) {

            retorno_comprobar = comprobar(&i_0,&j_0,&i_1,&j_1,tablero);
            printf("\nretorno_comprobar=%d\n",retorno_comprobar);//test

            if ((retorno_comprobar)==0){
                mover_pieza(i_0,j_0,i_1,j_1,tablero);
                
            }else{
                printf("\nIntroduzca un movimiento valido");
                contador=contador-1;
            }
        }else{
            printf("\nIntroduzca un movimiento valido");
           
        }
        

    }while(fin_partida==0);
 


    return 0;
}
