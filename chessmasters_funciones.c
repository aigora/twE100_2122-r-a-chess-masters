#include "chessmasters_funciones.h"


/*
* piezas[0]->torre00      piezas[16]->torre70
* piezas[1]->caballo01    piezas[17]->caballo71
* piezas[2]->alfil02      piezas[18]->alfil72
* piezas[3]->dama03       piezas[19]->dama73
* piezas[4]->rey04        piezas[20]->rey74
* piezas[5]->alfil05      piezas[21]->alfil75
* piezas[6]->caballo06    piezas[22]->caballo76
* piezas[7]->torre07      piezas[23]->torre77
* piezas[8]->peon10       piezas[24]->peon60
* piezas[9]->peon11       piezas[25]->peon61
* piezas[10]->peon12      piezas[26]->peon62
* piezas[11]->peon13      piezas[27]->peon63
* piezas[12]->peon14      piezas[28]->peon64
* piezas[13]->peon15      piezas[29]->peon65
* piezas[14]->peon16      piezas[30]->peon66
* piezas[15]->peon17      piezas[31]->peon67
*/

void inicializar_matrices(eval piezas[32]){
   
}

void limpiar_pantalla() {
printf("\x1b[2J");
/*
    //necesario incluir stdlib.h
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
*/
}
void inicio_juego(int *contador_movimientos, char tablero[8][8], int mov_enroque[6]){
    int i_0,j_0,i_1,j_1,fin_partida=0,retorno_introduce_coordenadas,retorno_comprobar;
    
    imprimir_tablero(tablero);
    
    
    do{
        retorno_introduce_coordenadas = introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&*contador_movimientos,tablero,mov_enroque);
        //printf("\nretorno_introduce_coordenadas=%d\n",retorno_introduce_coordenadas);//test

        if ((retorno_introduce_coordenadas)==0) {

            retorno_comprobar = comprobar(&i_0,&j_0,&i_1,&j_1,tablero,*&contador_movimientos);
            //printf("\nretorno_comprobar=%d\n",retorno_comprobar);//test

            if ((retorno_comprobar)==0){
                if (((tablero[i_1][j_1])=='R')||((tablero[i_1][j_1])=='r'))
                {
                    printf("Jaque mate, fin de la partida");
                    fin_partida=1;
                }else if ((((tablero[i_0][j_0])=='P')&&((i_0==1)&&(i_1==3)))||(((tablero[i_0][j_0])=='p')&&((i_0==6)&&(i_1==4))))//inicio moviendo dos casillas el peon
                {
                    mover_pieza(i_0,j_0,i_1,j_1,tablero,mov_enroque);
                    captura_alpaso(i_0,j_0,&i_0,&j_0,&i_1,&j_1,&*contador_movimientos,tablero,mov_enroque);
                }else {
                mover_pieza(i_0,j_0,i_1,j_1,tablero,mov_enroque);
                }
            }else{
                printf("\nIntroduzca un movimiento valido");
                *contador_movimientos=(*contador_movimientos-1);
            }
        }else {
            printf("\nIntroduzca un movimiento valido");
           
        }
    }while(fin_partida==0);
    menu_principal();

}


void mover_pieza(int i_inicial, int j_inicial, int i_final, int j_final, char tablero[8][8],int mov_enroque[6]) {

    tablero[i_final][j_final] = tablero[i_inicial][j_inicial];
    tablero[i_inicial][j_inicial] = '.';

    if ((i_inicial==0)&&(j_inicial==0))//movimientos torre izquierda negra
    {
        mov_enroque[0]++;
    }else if ((i_inicial==0)&&(j_inicial==7))//movimientos torre derecha negra
    {
        mov_enroque[1]++;
    }else if ((i_inicial==7)&&(j_inicial==0))//movimientos torre izquierda blanca
    {
        mov_enroque[2]++;
    }else if ((i_inicial==7)&&(j_inicial==7))//movimientos torre derecha blanca
    {
        mov_enroque[3]++;
    }else if ((i_inicial==7)&&(j_inicial==4))//movimientos rey blanco
    {
        mov_enroque[4]++;
    }else if ((i_inicial==0)&&(j_inicial==4))//movimientos rey negro
    {
        mov_enroque[5]++;
    }
    
    imprimir_tablero(tablero);
}

int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final, int *j_final, int *contador_movimientos, char tablero[8][8], int mov_enroque[6]) {
    int numero_inicial=0,numero_final=0,turno_color=0,control_sn;
    char letra_inicial=0,letra_final=0,seleccion_sn;
    
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
    if (letra_inicial=='m'||letra_inicial=='M')
    {
        menu_partida(&*i_inicial,&*j_inicial,&*i_final,&*j_final,&*contador_movimientos,tablero,mov_enroque);
    }
    if (letra_inicial=='E')
    {
        do
        {
           printf("\nQuieres enrocar?(S/N):");
           scanf("%c ",&seleccion_sn);
           if ((seleccion_sn=='S')||(seleccion_sn=='s')) {
               control_sn=0;
               enrocar(mov_enroque);
           }else if ((seleccion_sn=='N')||(seleccion_sn=='n')) {
              control_sn=0;
              introduce_coordenadas(&*i_inicial,&*j_inicial,&*i_final,&*j_final,&*contador_movimientos,tablero,mov_enroque);
           }else {
               control_sn=1;
           }
           
           
        } while (control_sn==1);
        
        
    }
    
    scanf("%d",&numero_inicial);

    //printf("\nprueba:Coordenadas introducidas %c%d \n",letra_inicial,numero_inicial);//test
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

    //
    
    
    
    //printf("\nprueba:Coordenadas introducidas %d%d \n",*i_inicial,*j_inicial);//test
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
    
    //printf("\nprueba:Coordenadas introducidas %c%d \n",letra_final,numero_final);//test
    //printf("\nprueba:Coordenadas introducidas %d%d \n",*i_final,*j_final);//test
    *contador_movimientos= *contador_movimientos + 1;
    //printf("\ncontador:%d\n",*contador_movimientos);//test
    
    return 0;
}



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
    int i,j,k,l,m=0,n=1,num_margen,sistema_operativo=0;
    
    #ifdef _WIN32
        sistema_operativo=1;//el SO es windows
    #endif
    
    char margen_derecho[19]="  |8|7|6|5|4|3|2|1";
    printf("\n\n");
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
            if (sistema_operativo==1) {

               printf(" %c",tablero[k][l]); //sin unicode
                
                
            }else {
                //SO es linux o macos

                switch (tablero[k][l]){
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
            
                    default:
                        printf(" %c",tablero[k][l]);
                        break;
                }
             //unicode 
            }
            

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
    printf("\n\n");
}

void coronar(int *i_inicial, int *j_inicial,int *i_final, int *j_final, char tablero[8][8]){
    char opcion_sn=0,opcion_pieza=0;
    int control_seleccion=1;
    do{
            printf("\nPromocionar peon:\nDama: escibe D\nTorre: escribe T\nCaballo: escribe C\nAlfil: escribe A\nElige una de las opciones:");
            scanf(" %c",&opcion_pieza);
            switch (opcion_pieza)
            {
                case 'D':
                    if (tablero[*i_inicial][*j_inicial]=='p')//peones blancos
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
                    if (tablero[*i_inicial][*j_inicial]=='p')//peones blancos
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
                    if (tablero[*i_inicial][*j_inicial]=='p')//piezas blancas
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
                    if (tablero[*i_inicial][*j_inicial]=='p')//piezas blancas
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
    }while (control_seleccion==1);     
}

void enrocar(int mov_enroque[6]){


}
void captura_alpaso(int i_anterior, int j_anterior, int *i_inicial, int *j_inicial, int *i_final, int *j_final, int *contador_movimientos, char tablero[8][8], int mov_enroque[6])
{
    int i_0=*i_inicial,j_0=*j_inicial,i_1=*i_final,j_1=*j_final,fin_partida=0,retorno_introduce_coordenadas,retorno_comprobar;

    //printf("captura al paso:\ni_anterior=%d\nj_anterior=%d\n",i_anterior,j_anterior);//test

    do{
        retorno_introduce_coordenadas = introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&*contador_movimientos,tablero,mov_enroque);
        //printf("\nretorno_introduce_coordenadas=%d\n",retorno_introduce_coordenadas);//test
        if ((retorno_introduce_coordenadas)==0) 
        {
            if ((((tablero[i_0][j_0])=='P')&&(((i_0==4)&&(i_1==5))&&((j_0==j_1+1)||(j_0==j_1-1))))||(((tablero[i_0][j_0])=='p')&&(((i_0==3)&&(i_1==2))&&((j_0==j_1+1)||(j_0==j_1-1)))))
            {
                if ((i_1==(i_anterior-1))&&(j_1==j_anterior))
                {
                    tablero[i_1][j_1] = tablero[i_0][j_0];
                    tablero[i_0][j_0] = '.';
                    tablero[i_anterior-2][j_anterior]='.';
                    
                    inicio_juego(&*contador_movimientos,tablero,mov_enroque);   
                }else if ((i_1==(i_anterior+1))&&(j_1==j_anterior))
                {
                    tablero[i_1][j_1] = tablero[i_0][j_0];
                    tablero[i_0][j_0] = '.';
                    tablero[i_anterior+2][j_anterior]='.';
                    
                    inicio_juego(&*contador_movimientos,tablero,mov_enroque);
                }else{
                    printf("\nIntroduzca un movimiento valido");
                    *contador_movimientos=*contador_movimientos-1;
                }
            }
            retorno_comprobar = comprobar(&i_0,&j_0,&i_1,&j_1,tablero,&*contador_movimientos);
            //printf("\nretorno_comprobar=%d\n",retorno_comprobar);//test
            if ((retorno_comprobar)==0){
                if (((tablero[i_1][j_1])=='R')||((tablero[i_1][j_1])=='r'))
                {
                    printf("Jaque mate, fin de la partida");
                    fin_partida=1;
                }else {
                mover_pieza(i_0,j_0,i_1,j_1,tablero,mov_enroque);
                inicio_juego(&*contador_movimientos,tablero,mov_enroque);
                }
            }else{
                printf("\nIntroduzca un movimiento valido");
                *contador_movimientos=*contador_movimientos-1;
            }
        }else {
            printf("\nIntroduzca un movimiento valido");
           
        }
    }while(fin_partida==0);
    menu_principal();
}

void matrices_evaluacion(int blancas_defensa[8][8],int negras_defensa[8][8]){
    //inicializar_matrices(piezas);

    
}

int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8],int *contador_movimientos){ //informa sobre si se puede realizar el movimiento indicado
    int i_0=*i_inicial, j_0=*j_inicial, i_1=*i_final, j_1=*j_final;
    int retorno_peones,retorno_caballos,retorno_alfiles,retorno_torres,retorno_reyes,retorno_damas,retorno_comprobar,i,j,k;
    int eval_blancas[8][8],eval_negras[8][8],eval_aux[8][8];
    eval piezas[32];
    if(*contador_movimientos==1){//inicializacion matrices de evaluacion
        for (k=0; k<32; k++){
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    eval_blancas[i][j]=0;
                }
            }
        }
        for (k=0; k<32; k++){
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    eval_negras[i][j]=0;
                }
            }
        }
        for (k=0; k<32; k++){
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    piezas[k].matriz[i][j]=0;
                }
            }
        }
        piezas[1].matriz[2][0]=1;//caballo01
        piezas[1].matriz[2][2]=1;
        piezas[6].matriz[2][5]=1;//caballo06
        piezas[6].matriz[2][7]=1;
        piezas[8].matriz[2][1]=1;//peon11
        piezas[9].matriz[2][2]=1;
        piezas[10].matriz[2][1]=1;//peon12
        piezas[10].matriz[2][3]=1;
        piezas[11].matriz[2][2]=1;//peon13 
        piezas[11].matriz[2][4]=1;
        piezas[12].matriz[2][3]=1;//peon14
        piezas[12].matriz[2][5]=1;
        piezas[13].matriz[2][4]=1;//peon15
        piezas[13].matriz[2][6]=1;
        piezas[14].matriz[2][5]=1;//peon16 
        piezas[14].matriz[2][7]=1;
        piezas[15].matriz[2][6]=1;//peon17

        piezas[17].matriz[5][0]=1;//caballo71
        piezas[17].matriz[5][2]=1;
        piezas[22].matriz[5][5]=1;//caballo76
        piezas[22].matriz[5][7]=1;
        piezas[24].matriz[5][1]=1;//peon60
        piezas[25].matriz[5][0]=1;//peon61
        piezas[25].matriz[5][2]=1;
        piezas[26].matriz[5][1]=1;//peon62
        piezas[26].matriz[5][3]=1;
        piezas[27].matriz[5][2]=1;//peon63
        piezas[27].matriz[5][4]=1;
        piezas[28].matriz[5][3]=1;//peon64
        piezas[28].matriz[5][5]=1;
        piezas[29].matriz[5][4]=1;//peon65
        piezas[29].matriz[5][6]=1;
        piezas[30].matriz[5][5]=1;//peon66
        piezas[30].matriz[5][7]=1;
        piezas[31].matriz[5][6]=1;//peon67

        for (k=16;k<32;k++){
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    eval_blancas[i][j]=eval_blancas[i][j]+piezas[k].matriz[i][j];
                    if ((eval_blancas[i][j])>1)
                    {
                        eval_blancas[i][j]=1;
                    }
                }
            }
        }

        for (k=0;k<16;k++){
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    eval_negras[i][j]=eval_negras[i][j]+piezas[k].matriz[i][j];
                    if ((eval_negras[i][j])>1)
                    {
                        eval_negras[i][j]=1;
                    }
                }
            }
        }
    }
    
    for (k=0; k<32; k++){
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    eval_aux[i][j]=0;
                }
            }
        }
   
    
    if (((tablero[*i_inicial][*j_inicial])=='P')||((tablero[*i_inicial][*j_inicial])=='p')) {
        retorno_peones=peones(&i_0,&j_0,&i_1,&j_1,tablero,eval_aux);

    }else if (((tablero[*i_inicial][*j_inicial])=='C')||((tablero[*i_inicial][*j_inicial])=='c')) {
        retorno_caballos=caballos(&i_0,&j_0,&i_1,&j_1,tablero,eval_aux);

    }else if (((tablero[*i_inicial][*j_inicial])=='A')||((tablero[*i_inicial][*j_inicial])=='a')) {
        retorno_alfiles=alfiles(&i_0,&j_0,&i_1,&j_1,tablero,eval_aux);

    }else if (((tablero[*i_inicial][*j_inicial])=='T')||((tablero[*i_inicial][*j_inicial])=='t')) {
        retorno_torres=torres(&i_0,&j_0,&i_1,&j_1,tablero,eval_aux);

    }else if (((tablero[*i_inicial][*j_inicial])=='R')||((tablero[*i_inicial][*j_inicial])=='r')) {
        retorno_reyes=reyes(&i_0,&j_0,&i_1,&j_1,tablero,eval_aux);

    }else if (((tablero[*i_inicial][*j_inicial])=='D')||((tablero[*i_inicial][*j_inicial])=='d')) {
        retorno_damas=damas(&i_0,&j_0,&i_1,&j_1,tablero,eval_aux);

    }else{
    return 1;
    }
    if ((retorno_peones==0)||(retorno_caballos==0)||(retorno_alfiles==0)||(retorno_torres==0)||(retorno_reyes==0)||(retorno_damas==0))
    {
        retorno_comprobar=0;
    }else{
        return 1;
    }
    printf("Retorno_comprobar=%d",retorno_comprobar);
    return retorno_comprobar;
}
