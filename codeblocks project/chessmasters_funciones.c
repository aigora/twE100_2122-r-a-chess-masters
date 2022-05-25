#include "chessmasters_funciones.h"

void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8]) {
    tablero[i_final][j_final] = tablero[i_inicial][j_inicial];
    tablero[i_inicial][j_inicial] = '.';
    imprimir_tablero(tablero);
}

int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final, int *j_final, int *contador_movimientos, char tablero[8][8]) {
    int numero_inicial=0,numero_final=0,turno_color=0;
    char letra_inicial=0,letra_final=0;
    
    if ((*contador_movimientos%2)==0) {
        printf("\n\tTurno de piezas NEGRAS\n");
        turno_color=1;

    }
    else{
        printf("\n\tTurno de piezas BLANCAS\n");
        turno_color=0;
    }
    printf("\nIntroduzca coordenadas de la pieza a mover (letra y numero):");
    scanf(" %c",&letra_inicial);
    scanf("%d",&numero_inicial);




    printf("\nprueba:Coordenadas introducidas %c%d \n",letra_inicial,numero_inicial);//test
    switch (letra_inicial) {
        case 'a':     //a
            *j_inicial=0;
            break;
        case 'b':     //b
            *j_inicial=1;
            break;
        case 'c':     //c
            *j_inicial=2;
            break;
        case 'd':    //d
            *j_inicial=3;
            break;
        case 'e':    //e
            *j_inicial=4;
            break;
        case 'f':    //f
            *j_inicial=5;
            break;
        case 'g':    //g
            *j_inicial=6;
            break;
        case 'h':    //h
            *j_inicial=7;
            break;
        
            
        default:
            return 1;
            break;
    }
    switch (numero_inicial) {
        case 8:     //0
            *i_inicial=0;
            break;
        case 7:     //1
            *i_inicial=1;
            break;
        case 6:     //2
            *i_inicial=2;
            break;
        case 5:     //3
            *i_inicial=3;
            break;
        case 4:     //4
            *i_inicial=4;
            break;
        case 3:     //5
            *i_inicial=5;
            break;
        case 2:     //6
            *i_inicial=6;
            break;
        case 1:     //7
            *i_inicial=7;
            break;
        
        default:
            return 1;
            break;
    }
    
    //impedir movimiento de fichas de otro color
    if ((turno_color==0)&&(((tablero[*i_inicial][*j_inicial])>='A')&&((tablero[*i_inicial][*j_inicial])<='T')))//turno_color=0 turno blancas
    {
        return 1;
    }else if ((turno_color==1)&&((tablero[*i_inicial][*j_inicial])>='a'))//turno_color=1 turno negras
    {
        return 1;
    }
    
    
    printf("\nprueba:Coordenadas introducidas %d%d \n",*i_inicial,*j_inicial);//test
    printf("\nIntroduzca las coordenadas donde quiere mover la pieza:");
    scanf(" %c",&letra_final);
    scanf("%d",&numero_final);
    
    switch (letra_final) {
        case 'a':     //a-0
            *j_final=0;
            break;
        case 'b':     //b-1
            *j_final=1;
            break;
        case 'c':     //c-2
            *j_final=2;
            break;
        case 'd':    //d-3
            *j_final=3;
            break;
        case 'e':    //e-4
            *j_final=4;
            break;
        case 'f':    //f-5
            *j_final=5;
            break;
        case 'g':    //g-6
            *j_final=6;
            break;
        case 'h':    //h-7
            *j_final=7;
            break;
            
        default:
            return 1;
            break;
    }
    switch (numero_final) {
        case 8:    //0
            *i_final=0;
            break;
        case 7:    //1
            *i_final=1;
            break;
        case 6:    //2
            *i_final=2;
            break;
        case 5:    //3
            *i_final=3;
            break;
        case 4:    //4
            *i_final=4;
            break;
        case 3:    //5
            *i_final=5;
            break;
        case 2:    //6
            *i_final=6;
            break;
        case 1:    //7
            *i_final=7;
            break;
        
        default:
            return 1;
            break;
    }
    
    printf("\nprueba:Coordenadas introducidas %c%d \n",letra_final,numero_final);//test
    printf("\nprueba:Coordenadas introducidas %d%d \n",*i_final,*j_final);//test
    *contador_movimientos= *contador_movimientos + 1;
    printf("\ncontador:%d\n",*contador_movimientos);//test
    
    return 0;
}


//libreria funciones


void tablero_inicial(char tablero[8][8]){ //rellenamos al inicio de partida la matriz del tablero
    int i,j;
    char primera_fila[8] = "TCADRACT";
    for(i=0;i<8;i++){
        tablero[0][i]=primera_fila[i];
        tablero[1][i]='P';
        tablero[6][i]='p';
        tablero[7][i]=primera_fila[i]+32;
        for(j=2;j<6;j++){
            tablero[j][i]='.';
        }
    }
}

void imprimir_tablero(char tablero[8][8]){//imprime por pantalla el tablero
    int i,j,k,l,m=0,n=1,num_margen;
    char margen_derecho[19]="  |8|7|6|5|4|3|2|1";
    printf("\n\n\n");
    printf("\t    ");
    for(i=0;i<8;i++){
        printf("%c ",i+97);
    }
    printf("\n");
    printf("\t  -------------------");
    num_margen=8;
    for(k=0;k<8;k++){
        printf(" %c %c\n\t%d |",margen_derecho[m],margen_derecho[n],num_margen);
        num_margen--;
        m=m+2;
        n=n+2;
        for(l=0;l<8;l++){
            /*
            switch (tablero[k][l])
            {
            case 'P':
                printf(" %s", "\u265F");
                break;
            case 'T':
                printf(" %s", "\u265C");
                break;
            case 'C':
                printf(" %s", "\u265E");
                break;
            case 'A':
                printf(" %s", "\u265D");
                break;
            case 'D':
                printf(" %s", "\u265B");
                break;
            case 'R':
                printf(" %s", "\u265A");
                break;
            case 'p':
                printf(" %s", "\u2659");
                break;
            case 't':
                printf(" %s", "\u2656");
                break;
            case 'c':
                printf(" %s", "\u2658");
                break;
            case 'a':
                printf(" %s", "\u2657");
                break;
            case 'd':
                printf(" %s", "\u2655");
                break;
            case 'r':
                printf(" %s", "\u2654");
                break;
            
            default:
                printf(" %c",tablero[k][l]);
                break;
            }*/ //unicode

            printf(" %c",tablero[k][l]); //sin unicode

        }
        if(k==7){
            printf(" %c %c ",margen_derecho[m],margen_derecho[n]);
        }
    }
    printf("\n");
    printf("\t  -------------------");
    printf("\n\t");
    printf("   ");
    for(j=0;j<8;j++){
        printf(" %c",j+97);
    }
    printf("\n\n\n");
}

void coronar(int *i_inicial, int *j_inicial,int *i_final, int *j_final, char tablero[8][8]){
    char opcion_sn=0,opcion_pieza=0;
    int control_seleccion=1;
    while(control_seleccion==1){
        printf("\nQuieres promocionar el peon?(S/N):");
        scanf("%c",&opcion_sn);
        control_seleccion=1;
        if ((opcion_sn=='S')||(opcion_sn=='s')) {
            printf("\nDama: escibe D\nTorre: escribe T\nCaballo: escribe C\nAlfil: escribe A\nElige una de las opciones:");
            scanf(" %c",&opcion_pieza);
            switch (opcion_pieza)
            {
                case 'D':
                    if (tablero[*i_inicial][*j_inicial]>='a')//peones blancos
                    {
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'd';
                        imprimir_tablero(tablero);
                    }else{//peones negros
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'D';
                        imprimir_tablero(tablero);
                    }
                    control_seleccion=0;
                    break;
        
                case 'T':
                    if (tablero[*i_inicial][*j_inicial]>='a')//peones blancos
                    {
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 't';
                        imprimir_tablero(tablero);
                    }else{//peones negros
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'T';
                        imprimir_tablero(tablero);
                    }
                    control_seleccion=0;
                    break;
        
                case 'C':
                    if (tablero[*i_inicial][*j_inicial]>='a')//piezas blancas
                    {
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'c';
                        imprimir_tablero(tablero);
                    }else{
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'C';
                        imprimir_tablero(tablero);
                    }
                    control_seleccion=0;
                    break;
        
                case 'A':
                    if (tablero[*i_inicial][*j_inicial]>='a')//piezas blancas
                    {
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'a';
                        imprimir_tablero(tablero);
                    }else{
                        tablero[*i_final][*j_final] = tablero[*i_inicial][*j_inicial];
                        tablero[*i_inicial][*j_inicial] = 'A';
                        imprimir_tablero(tablero);
                    }
                    control_seleccion=0;
                    break;
        
                default:
                    control_seleccion=1;
                    break;
            }

        }else if ((opcion_sn=='N')||(opcion_sn=='n')){
            printf("\nHas elegido no promocionar tu peon");
            control_seleccion=0;
        }else{
            control_seleccion=1;
        }
    }
}

int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){ //informa sobre si se puede realizar el movimiento indicado
    int i_0=*i_inicial, j_0=*j_inicial, i_1=*i_final, j_1=*j_final;
    int retorno_peones,retorno_caballos,retorno_alfiles,retorno_torres,retorno_reyes,retorno_damas;
    
    //int i,j;//para test imprimir matriz
    
    /*  //test entrada de datos
    printf("\ni_inicial=%d\nj_inicial=%d\ni_final=%d\nj_final=%d\n",i_0,j_0,i_1,j_1);
    printf("\ni_inicial=%d\nj_inicial=%d\ni_final=%d\nj_final=%d\n",*i_inicial,*j_inicial,*i_final,*j_final);
    printf("\npieza inicial=%c\n",tablero[i_0][j_0]);
    */
    
    /* //test matriz tablero
    for(i=0;i<8;i++){
        printf("\t\n");
        for(j=0;j<8;j++){
            printf(" %c",tablero[i][j]);
        }
    }
    */
    
    if (((tablero[*i_inicial][*j_inicial])=='P')||((tablero[*i_inicial][*j_inicial])=='p')) {
        retorno_peones=peones(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("\nretorno_peones=%d",retorno_peones);
        return retorno_peones;

    }else if (((tablero[*i_inicial][*j_inicial])=='C')||((tablero[*i_inicial][*j_inicial])=='c')) {
        retorno_caballos=caballos(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("\nretorno_caballos=%d",retorno_caballos);

        return caballos(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='A')||((tablero[*i_inicial][*j_inicial])=='a')) {
        retorno_alfiles=alfiles(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("\nretorno_alfiles=%d",retorno_alfiles);

        return alfiles(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='T')||((tablero[*i_inicial][*j_inicial])=='t')) {
        retorno_torres=torres(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("\nretorno_torres=%d",retorno_torres);

        return torres(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='R')||((tablero[*i_inicial][*j_inicial])=='r')) {
        retorno_reyes=reyes(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("\nretorno_reyes=%d",retorno_reyes);

        return reyes(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='D')||((tablero[*i_inicial][*j_inicial])=='d')) {
        retorno_damas=damas(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("\nretorno_damas=%d",retorno_damas);

        return damas(&i_0,&j_0,&i_1,&j_1,tablero);

    }else{
    return 1;
    }
}
