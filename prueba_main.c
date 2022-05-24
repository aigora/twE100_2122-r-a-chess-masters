#include <stdio.h>
//#include "chessmasters_piezas.h"
//#include "chessmasters_funciones.h"


void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8]);

int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, int *contador_movimientos);


void tablero_inicial(char tablero[8][8]);
void imprimir_tablero(char tablero[8][8]);
int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);


int peones (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);
int caballos (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);
int alfiles (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);
int torres (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);
int reyes (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);
int damas (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]);


int main() {
    int i_0,j_0,i_1,j_1,contador=1,fin_partida=0;
    char tablero[8][8];

    int retorno_introduce_coordenadas,retorno_comprobar;//test

    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    do{
        retorno_introduce_coordenadas = introduce_coordenadas(&i_0,&j_0,&i_1,&j_1,&contador);
        printf("\nretorno_introduce_coordenadas=%d\n",retorno_introduce_coordenadas);

        if ((retorno_introduce_coordenadas)==0) {

            retorno_comprobar = comprobar(&i_0,&j_0,&i_1,&j_1,tablero);
            printf("\nretorno_comprobar=%d\n",retorno_comprobar);

            if ((retorno_comprobar)==0){
                mover_pieza(i_0,j_0,i_1,j_1,tablero);
                
            }else{
                printf("\nIntroduzca un movimiento valido");
                contador=contador-1;
            }
        }else{
            printf("\nIntroduzca un movimiento valido");
            contador=contador-1;
        }
        

    }while(fin_partida==0);
 


    return 0;
}

void mover_pieza(int i_inicial, int j_inicial, int i_final,   int j_final, char tablero[8][8]) {
    tablero[i_final][j_final] = tablero[i_inicial][j_inicial];
    tablero[i_inicial][j_inicial] = '.';
    imprimir_tablero(tablero);
}

int introduce_coordenadas(int *i_inicial, int *j_inicial, int *i_final, int *j_final, int *contador_movimientos) {
    int numero_inicial=0,numero_final=0;
    char letra_inicial=0,letra_final=0;
    
    if ((*contador_movimientos%2)!=0) {
        printf("\n\tTurno de piezas NEGRAS\n");
    }
    else{
        printf("\n\tTurno de piezas BLANCAS\n");
    }
    printf("\nIntroduzca coordenadas de la pieza a mover (letra y numero):");
    scanf("%c",&letra_inicial);
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
            *i_inicial=2;
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
            printf(" %c",tablero[k][l]);
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

int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){ //informa sobre si se puede realizar el movimiento indicado
    int i_0=*i_inicial, j_0=*j_inicial, i_1=*i_final, j_1=*j_final;
    int retorno_peones,retorno_caballos,retorno_alfiles,retorno_torres,retorno_reyes,retorno_damas;
    
    int i,j;//para test imprimir matriz
    
    printf("\ni_inicial=%d\nj_inicial=%d\ni_final=%d\nj_final=%d\n",i_0,j_0,i_1,j_1);
    printf("\ni_inicial=%d\nj_inicial=%d\ni_final=%d\nj_final=%d\n",*i_inicial,*j_inicial,*i_final,*j_final);
    printf("\npieza inicial=%c\n",tablero[i_0][j_0]);
    
    for(i=0;i<8;i++){
        printf("\t\n");
        for(j=0;j<8;j++){
            printf(" %c",tablero[i][j]);
        }
    }
    
    if (((tablero[*i_inicial][*j_inicial])=='P')||((tablero[*i_inicial][*j_inicial])=='p')) {
        retorno_peones=peones(&i_0,&j_0,&i_1,&j_1,tablero);
        printf("retorno_peones=%d",retorno_peones);
        return retorno_peones;

    }else if (((tablero[*i_inicial][*j_inicial])=='C')||((tablero[*i_inicial][*j_inicial])=='c')) {
        return caballos(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='A')||((tablero[*i_inicial][*j_inicial])=='a')) {
        return alfiles(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='T')||((tablero[*i_inicial][*j_inicial])=='t')) {
        return torres(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='R')||((tablero[*i_inicial][*j_inicial])=='r')) {
        return reyes(&i_0,&j_0,&i_1,&j_1,tablero);

    }else if (((tablero[*i_inicial][*j_inicial])=='D')||((tablero[*i_inicial][*j_inicial])=='d')) {
        return damas(&i_0,&j_0,&i_1,&j_1,tablero);

    }else{
    return 1;
    }
}

int peones (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    
    printf("\ni_inicial=%d\nj_inicial=%d\ni_final=%d\nj_final=%d\n",*i_inicial,*j_inicial,*i_final,*j_final);
    
    
    if ((tablero[*i_inicial][*j_inicial])=='P') { //peon negras 4 movimientos posibles
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+1])) {
            if ((*j_final<8)&&((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+2])) {
            if ((*j_inicial==1)&&((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {
            if ((*j_final<8)&&((tablero[*i_final][*j_final])>='a')&&(0<=(*i_final))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {
            if ((*j_final<8)&&((tablero[*i_final][*j_final])>='a')&&(*i_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    
    
    if ((tablero[*i_inicial][*j_inicial])=='p') {//peon blancas
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-1])) {
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-2])) {
            if ((*j_inicial==6)&&((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')&&(0<=(*i_final))) {//limites y contiene mayuscula
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')&&(*i_final<8)) { // limites y contiene mayuscula
                return 0;
            }else{
                return 1;
            }
        }
    }
    return 1;
}

int caballos (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    if ((tablero[*i_inicial][*j_inicial])=='C') {//caballo negras 8 posibles posiciones
            
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+2])) {//(-1,+2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+2])) {//(+1,+2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+1])) {//(-2,+1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-1])) {//(-2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+1])) {//(+2,+1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-1])) {//(+2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-2])) {//(-1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-2])) {//(+1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
    }
    
    
    if ((tablero[*i_inicial][*j_inicial])=='c') {//caballo blancas
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+2])) {//(-1,+2)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+2])) {//(+1,+2)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+1])) {//(-2,+1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-1])) {//(-2,-1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+1])) {//(+2,+1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-1])) {//(+2,-1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-2])) {//(-1,-2)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-2])) {//(+1,-2)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    return 1;
}

int alfiles (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    int comprobar_diagonales=0,i,j;
    
    if ((tablero[*i_inicial][*j_inicial])=='A') { //alfil negras
        if ((tablero[*i_final][*j_final]>='a')||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*i_final)>(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
        }else{
            return 1;
        }
    }

    if ((tablero[*i_inicial][*j_inicial])=='a') { //alfil blancas
        if (((tablero[*i_final][*j_final]>='A')&&(tablero[*i_final][*j_final]<='T'))||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*i_final)>(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
        }else{
            return 1;
        }
    }
    return 1;
}

int torres (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    
    int i,comprobar_ejes=0;
    
    if ((tablero[*i_inicial][*j_inicial])=='T') { //torre negras
        if ((tablero[*i_final][*j_final]>='a')||(tablero[*i_final][*j_final]=='.')) {
            
            if ((*i_final)>(*i_inicial)) {
                for (i=(*i_inicial+1); i<(*i_final); i++) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if ((*i_final)<(*i_inicial)) {
                for (i=(*i_inicial-1); i>(*i_final); i--) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if ((*j_final)>(*j_inicial)) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if ((*j_final)<(*j_inicial)) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
        }else{
            return 1;
        }
        
    }

    if ((tablero[*i_inicial][*j_inicial])=='t') { //torre blancas
        if (((tablero[*i_final][*j_final]>='A')&&(tablero[*i_final][*j_final]<='T'))||(tablero[*i_final][*j_final]=='.')) {
            
            if ((*i_final)>(*i_inicial)) {
                for (i=(*i_inicial+1); i<(*i_final); i++) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if ((*i_final)<(*i_inicial)) {
                for (i=(*i_inicial-1); i>(*i_final); i--) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if ((*j_final)>(*j_inicial)) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if ((*j_final)<(*j_inicial)) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
        }else{
            return 1;
        }
    }
    return 1;
}

int reyes (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    
    if ((tablero[*i_inicial][*j_inicial])=='R') { //rey negras
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {//(+1,+1)
            if ((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial])) {//(+1,0)
            if ((*i_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial])) {//(-1,0)
            if ((*i_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+1])) {//(0,+1)
            if ((*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-1])) {//(0,-1)
            if ((*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    
     if ((tablero[*i_inicial][*j_inicial])=='r') { //rey blancas
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {//(+1,+1)
            if (((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if (((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if (((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial])) {//(+1,0)
            if (((*i_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial])) {//(-1,0)
            if (((*i_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+1])) {//(0,+1)
            if (((*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-1])) {//(0,-1)
            if (((*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    return 1;
}

int damas (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    
    int comprobar_diagonales=0, comprobar_ejes=0, i, j;
    
    if ((tablero[*i_inicial][*j_inicial])=='D') { //dama negras
        if ((tablero[*i_final][*j_final]>='a')||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*i_final)>(*i_inicial))&&((*j_final)==(*j_inicial))) {//movimientos como torre
                for (i=(*i_inicial+1); i<(*i_final); i++) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*i_inicial-1); i>(*i_final); i--) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*j_final)>(*j_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*j_final)<(*j_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)>(*j_inicial))) { //movimientos como alfil
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
        }else{
            return 1;
        }
    }

    if ((tablero[*i_inicial][*j_inicial])=='d') { //dama blancas
        if (((tablero[*i_final][*j_final]>='A')&&(tablero[*i_final][*j_final]<='T'))||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*i_final)>(*i_inicial))&&((*j_final)==(*j_inicial))) {//movimientos como torre
                for (i=(*i_inicial+1); i<(*i_final); i++) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*i_inicial-1); i>(*i_final); i--) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*j_final)>(*j_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*j_final)<(*j_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)>(*j_inicial))) { //movimientos como alfil
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial+1; i<(*i_final); i++) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial-1; i>(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (i=*i_inicial-1; i>(*i_final); i--) {
                    for (j=*j_inicial+1; i<(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
        }else{
            return 1;
        }
    }
    return 1;
}

