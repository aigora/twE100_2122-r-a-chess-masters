#include <stdio.h>
#include "chessmasters_piezas.h"
#include "chessmasters_funciones.h"


void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8]);

int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos);

int main() {
    int i_0,j_0,i_1,j_1,contador=1,fin_partida=0;
    char tablero[8][8];
    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    do{
        introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador);
        if (introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador)==0) {
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

void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8]) {
    tablero[i_final][j_final] = tablero[i_inicial][j_inicial];
    tablero[i_inicial][j_inicial] = '.';
}

int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final, int *j_final, int *contador_movimientos) {
    int numero_inicial,numero_final;
    char letra_inicial,letra_final;
    
    if ((*contador_movimientos%2)!=0) {
        printf("\n\tTurno de piezas NEGRAS\n");
    }
    else{
        printf("\n\tTurno de piezas BLANCAS\n");
    }
    printf("\nIntroduzca coordenadas de la pieza a mover (letra y numero):");
    scanf("%c",&letra_inicial);
    scanf(" %d",&numero_inicial);
    switch (letra_inicial) {
        case 97:     //a
            *j_inicial=0;
            break;
        case 98:     //b
            *j_inicial=1;
            break;
        case 99:     //c
            *j_inicial=2;
            break;
        case 100:    //d
            *j_inicial=3;
            break;
        case 101:    //e
            *j_inicial=4;
            break;
        case 102:    //f
            *j_inicial=5;
            break;
        case 103:    //g
            *j_inicial=6;
            break;
        case 104:    //h
            *j_inicial=7;
            break;
        
            
        default:
            return 1;
            break;
    }
    switch (numero_inicial) {
        case 8:     //a
            *i_inicial=0;
            break;
        case 7:     //b
            *i_inicial=1;
            break;
        case 6:     //c
            *i_inicial=2;
            break;
        case 5:     //d
            *i_inicial=3;
            break;
        case 4:     //e
            *i_inicial=4;
            break;
        case 3:     //f
            *i_inicial=5;
            break;
        case 2:     //g
            *i_inicial=6;
            break;
        case 1:     //h
            *i_inicial=7;
            break;
        
        default:
            return 1;
            break;
    }
    
    
    printf("Introduzca las coordenadas donde quiere mover la pieza:");
    scanf("%c",&letra_final);
    scanf(" %d",&numero_final);
    
    switch (letra_final) {
        case 97:     //a
            *j_final=0;
            break;
        case 98:     //b
            *j_final=1;
            break;
        case 99:     //c
            *j_final=2;
            break;
        case 100:    //d
            *j_final=3;
            break;
        case 101:    //e
            *j_final=4;
            break;
        case 102:    //f
            *j_final=5;
            break;
        case 103:    //g
            *j_final=6;
            break;
        case 104:    //h
            *j_final=7;
            break;
            
        default:
            return 1;
            break;
    }
    switch (numero_final) {
        case 8:    //a
            *i_final=0;
            break;
        case 7:    //b
            *i_final=1;
            break;
        case 6:    //c
            *i_final=2;
            break;
        case 5:    //d
            *i_final=3;
            break;
        case 4:    //e
            *i_final=4;
            break;
        case 3:    //f
            *i_final=5;
            break;
        case 2:    //g
            *i_final=6;
            break;
        case 1:    //h
            *i_final=7;
            break;
        
        default:
            return 1;
            break;
    }
    
    return 0;
}

