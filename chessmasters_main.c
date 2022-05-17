#include <stdio.h>

void tablero_inicial(char tablero[8][8]);
void imprimir_tablero(char tablero[8][8]);
int comprobar(int *i_inicial, int *j_inicial, int *i_final,   int *j_final, char tablero[8][8]);


int main(){
    char tablero[8][8];
    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    
     
    
    return 0;
}
void tablero_inicial(char tablero[8][8]){
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

void imprimir_tablero(char tablero[8][8]){
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

int comprobar(int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
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
            if ((*j_final<8)&&((tablero[*i_final][*j_final])!='.')&&(0<=(*i_final))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {
            if ((*j_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*i_final<8)) {
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
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(0<=(*i_final))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*i_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
    }
        
    if ((tablero[*i_inicial][*j_inicial])=='C') {//caballo negras 8 posibles posiciones
            
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+2])) {//(-1,+2)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+2])) {//(+1,+2)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+1])) {//(-2,+1)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-1])) {//(-2,-1)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+1])) {//(+2,+1)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-1])) {//(+2,-1)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-2])) {//(-1,-2)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-2])) {//(+1,-2)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
    }
    
    
    if ((tablero[*i_inicial][*j_inicial])=='c') {//caballo blancas
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+2])) {//(-1,+2)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+2])) {//(+1,+2)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+1])) {//(-2,+1)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-1])) {//(-2,-1)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+1])) {//(+2,+1)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-1])) {//(+2,-1)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final>=0)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-2])) {//(-1,-2)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-2])) {//(+1,-2)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])!='.')&&(*j_final<8)) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    
    if ((tablero[*i_inicial][*j_inicial])=='T') { //torre negras
        }

    if ((tablero[*i_inicial][*j_inicial])=='t') { //torre blancas
        }
    if ((tablero[*i_inicial][*j_inicial])=='A') { //alfil negras
        }

    if ((tablero[*i_inicial][*j_inicial])=='a') { //alfil blancas
        }
    
    
    return 1;
}

