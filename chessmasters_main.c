#include <stdio.h>

void tablero_inicial(char tablero[8][8]);
void imprimir_tablero(char tablero[8][8]);


int main(){
    char tablero[8][8];
    tablero_inicial(tablero);
    imprimir_tablero(tablero);
    
     
    
    return 0;
}
void tablero_inicial(char tablero[8][8]){
    int i,j;
    char primera_fila[8] = "tcadract";
    for(i=0;i<8;i++){
        tablero[0][i]=primera_fila[i];
        tablero[1][i]='p';
        tablero[6][i]='P';
        tablero[7][i]=primera_fila[i]-32;
        for(j=2;j<6;j++){
            tablero[j][i]='.';
        }
    }
}

void imprimir_tablero(char tablero[8][8]){
    int i,j,k,l,m=0,n=1,num_margen;
    char margen_derecho[19]="  |8|7|6|5|4|3|2|1";
    printf("   ");
    for(i=0;i<8;i++){
        printf(" %c",i+97);
    }
    printf("\n");
    printf("  -------------------");
    num_margen=8;
    for(k=0;k<8;k++){
        printf(" %c %c\n%d |",margen_derecho[m],margen_derecho[n],num_margen);
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
    printf("  -------------------");
    printf("\n");
    printf("   ");
    for(j=0;j<8;j++){
        printf(" %c",j+97);
    }
    printf("\n\n");
}
