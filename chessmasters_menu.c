#include "chessmasters_menu.h"

int menu_principal(){
    //Inicializaciones
    int modo_juego, tiempo, menu,cronometro ;
    player blancas;
    player negras;

    //switch menu principal
    do{
        printf("AJEDREZ\n\n");
        printf("\n1.Nueva partida\n2.Cargar partida\n3.Registro de partidas\n4.Reglas Ajedrez\n");
        scanf("%d",&menu);
        
    }while(menu<1||menu>4);
 
    switch(menu){
        case 1: //nueva partida
            printf("Jugador de negras: Introduzca su nombre\n");
            //actualizar los datos en el struct
            printf("Jugador de blancas: Introduzca su nombre\n");
            //actualizar los datos en el struct
            //
            printf("\nINICIANDO  PARTIDA, %s contra %s\n", blancas.name,negras.name);
            return 0;

             
        case 2: //cargar partida
            do{
                printf("\n\nSeleccione una partida guardada\n\n");
                //completar
            }while();
        
        case 3://registro de partidas

        case 4://Instrucciones Ajedrez
    }
    return 1;
}