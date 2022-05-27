#include "chessmasters_ficheros.h"
int imprimir_reglas(){
    char caracteres;
    FILE *pf_reglas;
  
    pf_reglas = fopen("reglas_ajedrez.txt", "r");
            

    if (pf_reglas == NULL) {
        fclose (pf_reglas);
        printf("\nError al abrir el fichero.\n");
        return 1;
    }

    while (!feof (pf_reglas)) {//bucle para imprimir en terminal
        caracteres = getc (pf_reglas);
        printf ("%c", caracteres);
    }
    fclose(pf_reglas);
    return 0;
 }

 int guardar_partida(int *contador_movimientos, char tablero[8][8]){
    int seleccion_slot=0,i,j;
    char caracter_matriz;
    player blancas, negras;
    printf("\nIntroduzcan sus nombres para guardar la partida:");
    printf("\nJugador de piezas blancas, introduzca su nombre:");
    scanf("%s", blancas.name);
    printf("\nJugador de piezas negras, introduzca su nombre:");
    scanf("%s", negras.name);
    
    printf("Escojan uno de los slots de guardado:\n");
    printf("\nSlot 1\nSlot 2\nSlot 3\nSlot 4\nSlot 5\nSeleccione una opcion:");

    do{
        scanf("%d",&seleccion_slot);
    }while((seleccion_slot<1)||(seleccion_slot>5));

    if (seleccion_slot==1) {

        FILE *slot1 = fopen("slot1.txt","w");
        if (slot1 == NULL) {
            fclose (slot1);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    fputc(tablero[i][j],slot1);
                }
            
            }
        }
        fclose (slot1);
        FILE *valores1 = fopen("valores1.csv","w");
        if (valores1 == NULL) {
            fclose (valores1);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fprintf(valores1, "%s,%s,%d",blancas.name, negras.name, *contador_movimientos);
            fclose(valores1);

        }
        printf("Partida guardada con éxito");
        menu_principal();

    }else if (seleccion_slot==2) {

        FILE *slot2 = fopen("slot2.txt","w");
        if (slot2 == NULL) {
            fclose (slot2);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    fputc(tablero[i][j],slot2);
                }
            
            }
        }
        fclose (slot2);
        FILE *valores2 = fopen("valores2.csv","w");
        if (valores2 == NULL) {
            fclose (valores2);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fprintf(valores2, "%s,%s,%d",blancas.name, negras.name, *contador_movimientos);
            fclose(valores2);

        }
        printf("Partida guardada con éxito");
        menu_principal();
        
 
    }else if (seleccion_slot==3) {
        FILE *slot3 = fopen("slot3.txt","w");
        if (slot3 == NULL) {
            fclose (slot3);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    fputc(tablero[i][j],slot3);
                }
            
            }
        }
        fclose (slot3);
        FILE *valores3 = fopen("valores3.csv","w");
        if (valores3 == NULL) {
            fclose (valores3);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fprintf(valores3, "%s,%s,%d",blancas.name, negras.name, *contador_movimientos);
            fclose(valores3);

        }
        printf("Partida guardada con éxito");
        menu_principal();
       

    }else if (seleccion_slot==4) {
        FILE *slot4 = fopen("slot4.txt","w");
        if (slot4 == NULL) {
            fclose (slot4);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    fputc(tablero[i][j],slot4);
                }
            
            }
        }
        fclose (slot4);
        FILE *valores4 = fopen("valores4.csv","w");
        if (valores4 == NULL) {
            fclose (valores4);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fprintf(valores4, "%s,%s,%d",blancas.name, negras.name, *contador_movimientos);
            fclose(valores4);

        }
        printf("Partida guardada con éxito");
        menu_principal();
        

    }else if (seleccion_slot==5) {
        FILE *slot5 = fopen("slot5.txt","w");
        if (slot5 == NULL) {
            fclose (slot5);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    fputc(tablero[i][j],slot5);
                }
            
            }
        }
        fclose (slot5);
        FILE *valores5 = fopen("valores5.csv","w");
        if (valores5 == NULL) {
            fclose (valores5);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fprintf(valores5, "%s,%s,%d",blancas.name, negras.name, *contador_movimientos);
            fclose(valores5);

        }
        printf("Partida guardada con éxito");
        menu_principal();
        

    }

     return 1;
 }

int cargar_partida(){
    player blancas, negras;
    int contador=0,seleccion_slot,i,j,control_sn, mov_enroque[6]={0,0,0,0,0,0};
    char seleccion_sn, tablero[8][8], vacio[10]="Empty";

    printf("\nSlot 1\nSlot 2\nSlot 3\nSlot 4\nSlot 5\nVolver al menu principal 6\nIntroduzca el numero del slot que quiere cargar:");
    do{
        scanf("%d",&seleccion_slot);
    }while((seleccion_slot<1)||(seleccion_slot>6));

    if (seleccion_slot==6) {
        menu_principal();
    }else if (seleccion_slot==1) {
        FILE *valores1 = fopen("valores1.csv","r");
        if (valores1 == NULL) {
            fclose (valores1);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fscanf(valores1, "%[^,],%[^,],%d",blancas.name, negras.name, &contador);
            fclose(valores1);
        }
        if (strcmp(blancas.name, vacio)==0) {
            printf("\nEl slot esta vacio");
            cargar_partida();
        }else{
        printf("\nQuiere reanudar la partida %s VS %s ?(S/N):",blancas.name,negras.name );
        }
        do{
            scanf("%c",&seleccion_sn);
            switch (seleccion_sn)
            {
            case 'S':
                control_sn=0;
                break;
            case 's':
                control_sn=0;
                break;
            case 'N':
                control_sn=0;
                break;
            case 'n':
                control_sn=0;
                break;
            default:
                control_sn=1;
                break;
            }
        }while(control_sn==1);
        //(seleccion_sn!='S')||(seleccion_sn!='s')||(seleccion_sn!='N')||(seleccion_sn!='n')
        if ((seleccion_sn=='N')||(seleccion_sn=='n')) {
            cargar_partida();
        }else{
            FILE *slot1 = fopen("slot1.txt","r");
            if (slot1 == NULL) {
                fclose (slot1);
                printf("\nError al abrir el fichero.\n");
                return 1;
            }else{
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        fscanf(slot1, "%c",&tablero[i][j]);
                    }
                }
            }
            fclose (slot1);
            inicio_juego(&contador,tablero,mov_enroque);
        }
        

    }else if (seleccion_slot==2) {

        FILE *valores2 = fopen("valores2.csv","r");
        if (valores2 == NULL) {
            fclose (valores2);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fscanf(valores2, "%[^,],%[^,],%d",blancas.name, negras.name, &contador);
            fclose(valores2);
        }
        if (strcmp(blancas.name, vacio)==0) {
            printf("\nEl slot esta vacio");
            cargar_partida();
        }else{
        printf("\nQuiere reanudar la partida %s VS %s?(S/N);",blancas.name,negras.name );
        }
        do{
            scanf("%c",&seleccion_sn);
            switch (seleccion_sn)
            {
            case 'S':
                control_sn=0;
                break;
            case 's':
                control_sn=0;
                break;
            case 'N':
                control_sn=0;
                break;
            case 'n':
                control_sn=0;
                break;
            default:
                control_sn=1;
                break;
            }
        }while(control_sn==1);
        if ((seleccion_sn=='N')||(seleccion_sn=='n')) {
            cargar_partida();
        }else{
            FILE *slot2 = fopen("slot2.txt","r");
            if (slot2 == NULL) {
                fclose (slot2);
                printf("\nError al abrir el fichero.\n");
                return 1;
            }else{
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        fscanf(slot2, "%c",&tablero[i][j]);
                    }
                }
            }
            fclose (slot2);
            inicio_juego(&contador,tablero,mov_enroque);
        }
    
    }else if (seleccion_slot==3) {
        FILE *valores3 = fopen("valores3.csv","r");
        if (valores3 == NULL) {
            fclose (valores3);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fscanf(valores3, "%[^,],%[^,],%d",blancas.name, negras.name, &contador);
            fclose(valores3);
        }
        if (strcmp(blancas.name, vacio)==0) {
            printf("\nEl slot esta vacio");
            cargar_partida();
        }else{
        printf("\nQuiere reanudar la partida %s VS %s?(S/N):",blancas.name,negras.name );
        }
       do{
            scanf("%c",&seleccion_sn);
            switch (seleccion_sn)
            {
            case 'S':
                control_sn=0;
                break;
            case 's':
                control_sn=0;
                break;
            case 'N':
                control_sn=0;
                break;
            case 'n':
                control_sn=0;
                break;
            default:
                control_sn=1;
                break;
            }
        }while(control_sn==1);
        if ((seleccion_sn=='N')||(seleccion_sn=='n')) {
            cargar_partida();
        }else{
            FILE *slot3 = fopen("slot3.txt","r");
            if (slot3 == NULL) {
                fclose (slot3);
                printf("\nError al abrir el fichero.\n");
                return 1;
            }else{
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        fscanf(slot3, "%c",&tablero[i][j]);
                    }
                }
            }
            fclose (slot3);
            inicio_juego(&contador,tablero,mov_enroque);
        } 
    }else if (seleccion_slot==4) {

        FILE *valores4 = fopen("valores4.csv","r");
        if (valores4 == NULL) {
            fclose (valores4);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fscanf(valores4, "%[^,],%[^,],%d",blancas.name, negras.name, &contador);
            fclose(valores4);
        }
        if (strcmp(blancas.name, vacio)==0) {
            printf("\nEl slot esta vacio");
            cargar_partida();
        }else{
        printf("\nQuiere reanudar la partida %s VS %s?(S/N):",blancas.name,negras.name );
        }
       do{
            scanf("%c",&seleccion_sn);
            switch (seleccion_sn)
            {
            case 'S':
                control_sn=0;
                break;
            case 's':
                control_sn=0;
                break;
            case 'N':
                control_sn=0;
                break;
            case 'n':
                control_sn=0;
                break;
            default:
                control_sn=1;
                break;
            }
        }while(control_sn==1);
        if ((seleccion_sn=='N')||(seleccion_sn=='n')) {
            cargar_partida();
        }else{
            FILE *slot4 = fopen("slot4.txt","r");
            if (slot4 == NULL) {
                fclose (slot4);
                printf("\nError al abrir el fichero.\n");
                return 1;
            }else{
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        fscanf(slot4, "%c",&tablero[i][j]);
                    }
                }
            }
            fclose (slot4);
            inicio_juego(&contador,tablero,mov_enroque);
        }
    }else if (seleccion_slot==5) {

        FILE *valores5 = fopen("valores5.csv","r");
        if (valores5 == NULL) {
            fclose (valores5);
            printf("\nError al abrir el fichero.\n");
            return 1;
        }else{
            fscanf(valores5, "%[^,],%[^,],%d",blancas.name, negras.name, &contador);
            fclose(valores5);
        }
        if (strcmp(blancas.name, vacio)==0) {
            printf("\nEl slot esta vacio");
            cargar_partida();
        }else{
        printf("\nQuiere reanudar la partida %s VS %s?(S/N):",blancas.name,negras.name );
        }
        do{
            scanf("%c",&seleccion_sn);
            switch (seleccion_sn)
            {
            case 'S':
                control_sn=0;
                break;
            case 's':
                control_sn=0;
                break;
            case 'N':
                control_sn=0;
                break;
            case 'n':
                control_sn=0;
                break;
            default:
                control_sn=1;
                break;
            }
        }while(control_sn==1);
        if ((seleccion_sn=='N')||(seleccion_sn=='n')) {
            cargar_partida();
        }else{
            FILE *slot5 = fopen("slot5.txt","r");
            if (slot5 == NULL) {
                fclose (slot5);
                printf("\nError al abrir el fichero.\n");
                return 1;
            }else{
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        fscanf(slot5, "%c",&tablero[i][j]);
                    }
                }
            }
            fclose (slot5);
            inicio_juego(&contador,tablero,mov_enroque);
        }
    }
    return 1;
}
