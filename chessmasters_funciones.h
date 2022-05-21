#include <stdio.h>

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
    int comprobar_diagonales=1,i,j;
    
    if (((tablero[*i_inicial][*j_inicial])=='P')||((tablero[*i_inicial][*j_inicial])=='p')) {
        if (peones==0) {
            return 0;
        }else if (peones==1){
            return 1;
        }
    }
    
        
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
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+2])) {//(+1,+2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+1])) {//(-2,+1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-1])) {//(-2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+1])) {//(+2,+1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-1])) {//(+2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-2])) {//(-1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-2])) {//(+1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.'))) {
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
    
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {//(+1,+1)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
                
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
                
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
                
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+2])) {//(+2,+2)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-2])) {//(-2,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+2])) {//(-2,+2)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-2])) {//(+2,-2)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+3][*j_inicial+3])) {//(+3,+3)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-3][*j_inicial-3])) {//(-3,-3)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-3][*j_inicial+3])) {//(-3,+3)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+3][*j_inicial-3])) {//(+3,-3)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+4][*j_inicial+4])) {//(+4,+4)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-4][*j_inicial-4])) {//(-4,-4)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-4][*j_inicial+4])) {//(-4,+4)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+4][*j_inicial-4])) {//(+4,-4)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+5][*j_inicial+5])) {//(+5,+5)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-5][*j_inicial-5])) {//(-5,-5)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-5][*j_inicial+5])) {//(-5,+5)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+5][*j_inicial-5])) {//(+5,-5)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+6][*j_inicial+6])) {//(+6,+6)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-6][*j_inicial-6])) {//(-6,-6)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-6][*j_inicial+6])) {//(-6,+6)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+6][*j_inicial-6])) {//(+6,-6)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+7][*j_inicial+7])) {//(+7,+7)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-7][*j_inicial-7])) {//(-7,-7)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-7][*j_inicial+7])) {//(-7,+7)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+7][*j_inicial-7])) {//(+7,-7)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='a')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }
    }

    if ((tablero[*i_inicial][*j_inicial])=='a') {//alfil blancas
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {//(+1,+1)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+2])) {//(+2,+2)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-2])) {//(-2,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+2])) {//(-2,+2)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-2])) {//(+2,-2)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+3][*j_inicial+3])) {//(+3,+3)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-3][*j_inicial-3])) {//(-3,-3)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-3][*j_inicial+3])) {//(-3,+3)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+3][*j_inicial-3])) {//(+3,-3)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+4][*j_inicial+4])) {//(+4,+4)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-4][*j_inicial-4])) {//(-4,-4)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-4][*j_inicial+4])) {//(-4,+4)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+4][*j_inicial-4])) {//(+4,-4)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+5][*j_inicial+5])) {//(+5,+5)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-5][*j_inicial-5])) {//(-5,-5)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-5][*j_inicial+5])) {//(-5,+5)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+5][*j_inicial-5])) {//(+5,-5)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+6][*j_inicial+6])) {//(+6,+6)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-6][*j_inicial-6])) {//(-6,-6)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-6][*j_inicial+6])) {//(-6,+6)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+6][*j_inicial-6])) {//(+6,-6)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+7][*j_inicial+7])) {//(+7,+7)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-7][*j_inicial-7])) {//(-7,-7)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-7][*j_inicial+7])) {//(-7,+7)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial-1; i>=(*i_final); i--) {
                    for (j=*j_inicial+1; i<=(*j_final); j++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+7][*j_inicial-7])) {//(+7,-7)
            if ((*i_final<8)&&(*j_final<=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                for (i=*i_inicial+1; i<=(*i_final); i++) {
                    for (j=*j_inicial-1; i>=(*j_final); j--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                if (comprobar_diagonales==0) {
                    return 0;
                }
            }else{
                return 1;
            }
        }
    }
    
    if ((tablero[*i_inicial][*j_inicial])=='R') { //rey negras
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {//(+1,+1)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial])) {//(+1,0)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial])) {//(-1,0)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+1])) {//(0,+1)
            if ((*j_final<8)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-1])) {//(0,-1)
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])>='a')) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    
     if ((tablero[*i_inicial][*j_inicial])=='r') { //rey blancas
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+1])) {//(+1,+1)
            if ((*i_final<8)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial])) {//(+1,0)
            if ((*i_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial])) {//(-1,0)
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+1])) {//(0,+1)
            if ((*j_final<8)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-1])) {//(0,-1)
            if ((*j_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    
    
    
    return 1;
}

