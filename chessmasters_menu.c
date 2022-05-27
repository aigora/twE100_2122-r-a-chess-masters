#include "chessmasters_menu.h"
#include "chessmasters_ficheros.h"


int menu_principal(){
     //Inicializaciones
    int menu,contador=1, mov_enroque[6]={0,0,0,0,0,0};
    char c;
    char tablero[8][8];
    

    //switch menu principal
    do{
        printf("\n\nAJEDREZ\n\n");
        printf("\n1.Nueva partida\n2.Cargar partida\n3.Reglas Ajedrez\nSeleccione una opcion:");
        scanf("%d",&menu);
        
    }while(menu<1||menu>4);
 
    switch(menu){
        case 1: //nueva partida
            printf("\nINICIANDO  PARTIDA\nPara acceder al menu durante la partida pulse 'M'\nPara ver si puede enrocar pulse 'E'\nPara finalizar la partida en tablas pulse 'T'\n");
            tablero_inicial(tablero);
            inicio_juego(&contador,tablero,mov_enroque);
            return 0;

        case 2: //cargar partida
            cargar_partida();
    
        case 3://Instrucciones Ajedrez
            imprimir_reglas();
            menu_principal();
    }
    return 1;
}

int menu_partida(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos, char tablero[8][8], int mov_enroque[6]){
    int seleccion_menu;
    printf("\n\nMENU DE PARTIDA\n");
    do{
    printf("1.Volver a la partida\n2.Guardar partida\n3.Salir a menu principal\nSeleccione una opcion:");
    scanf("%d",&seleccion_menu);
    }while ((seleccion_menu!=1)&&(seleccion_menu!=2)&&(seleccion_menu!=3));
    
    switch (seleccion_menu)
    {
    case 1://continuar
        imprimir_tablero(tablero);
        introduce_coordenadas(&*i_inicial,&*j_inicial,&*i_final,&*j_final,&*contador_movimientos,tablero,mov_enroque);
        break;
    case 2://guardar
        guardar_partida(&*contador_movimientos,tablero);
        break;
    case 3://Salir a menu principal
        menu_principal();
        return 0;
        break;
    
    default:
        printf("Error");
        break;
    }


    return 1;
}

