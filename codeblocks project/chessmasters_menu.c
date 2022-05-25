/*
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
            do{
                printf("\nModo de juego:\n\n");
                printf("1.Sin tiempo\n2.Cronometrado\n3.Atras\n");
                scanf("%d", modo_juego);
            }while(modo_juego<1||modo_juego>3);

            switch(modo_juego){
                case 1:
                    printf("\n:Modo de juego sin tiempo\n\n");
                    break;
                case 2:do{
                    printf("\nElige tiempo:\n\n");
                    printf("1. 15 minutos\n2. 10 minutos\n3. 5 minutos\n4. 1 minuto\n\n");
                    scanf("%d", cronometro);
                }while(cronometro<1||cronometro>4);

                    switch (cronometro){
                        case 1:
                            printf("\nHa seleccionado 15 minutos\n\n");
                            printf("Jugador de negras: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            printf("Jugador de blancas: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            //
                            printf("\nINICIANDO  PARTIDA, %s contra %s\n", blancas.name,negras.name);
                            return 0;
                        case 2:
                            printf("\nHa seleccionado 10 minutos\n\n");
                            printf("Jugador de negras: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            printf("Jugador de blancas: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            //
                            printf("\nINICIANDO  PARTIDA, %s contra %s\n", blancas.name,negras.name);
                            return 0;
                        case 3:
                            printf("\nHa seleccionado 5 minutos\n\n");
                            printf("Jugador de negras: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            printf("Jugador de blancas: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            //
                            printf("\nINICIANDO  PARTIDA, %s contra %s\n", blancas.name,negras.name);
                            return 0;
                        case 4:
                            printf("\nHa seleccionado 1 minuto\n\n");
                            printf("Jugador de negras: Introduzca su nombre\n");
                            //actualizar los datos en el struct
                            printf("Jugador de blancas: Introduzca su nombre\n");
                            //actualizar los datos en el struct

                            printf("\nINICIANDO  PARTIDA, %s contra %s\n", blancas.name,negras.name);
                            return 0;
                        }

                    case 3:
                        return 1;

                }

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
*/
