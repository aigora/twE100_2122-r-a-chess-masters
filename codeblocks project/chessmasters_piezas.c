#include "chessmasters_piezas.h"
int peones (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    
    printf("\ni_inicial=%d\nj_inicial=%d\ni_final=%d\nj_final=%d\n",*i_inicial,*j_inicial,*i_final,*j_final);
    
    
    if ((tablero[*i_inicial][*j_inicial])=='P') { //peon negras 4 movimientos posibles
        
        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial))) { //avanza 1
            if ((*i_final<8)&&((tablero[*i_final][*j_final])=='.')) {//limites del tablero y que la posicion este vacia
                if(*i_final==7){
                    coronar(&*i_inicial, &*j_inicial, &*i_final, &*j_final, tablero);
                }
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+2)) && ((*j_final)==(*j_inicial))) { //avanza 2
            if ((*i_inicial==1)&&((tablero[*i_final][*j_final])=='.')) {//desde la fila 1 y que la posicion este vacia
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial-1))) { //come hacia su derecha i_inicial+1 j_inicial-1
            if ((*i_final<8)&&((tablero[*i_final][*j_final])>='a')&&(0<=(*j_final))) {//limites del tablero y pieza en minusculas
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial+1))) { //come hacia su izquierda i_inicial+1 j_inicial+1
            if ((*i_final<8)&&((tablero[*i_final][*j_final])>='a')&&(*j_final<8)) { //limites tablero y pieza en minusculas
                return 0;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
    }
    
    
    if ((tablero[*i_inicial][*j_inicial])=='p') {//peon blancas
        
        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial))) {//avanza 1 i_inicial-1
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])=='.')) {//limites del tablero y que la posicion este vacia
             if(*i_final==0){
                    coronar(&*i_inicial, &*j_inicial, &*i_final, &*j_final, tablero);
                }
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-2)) && ((*j_final)==(*j_inicial))) {
            if ((*i_inicial==6)&&((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial-1))) {
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')&&(0<=(*j_final))) {//limites y contiene mayuscula
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial+1))) {
            if ((*i_final>=0)&&((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')&&(*j_final<8)) { // limites y contiene mayuscula
                return 0;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
    }
    return 1;
}

int caballos (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    if ((tablero[*i_inicial][*j_inicial])=='C') {//caballo negras 8 posibles posiciones
            
        if (((*i_final)==(*i_inicial+2))&&((*j_final)==(*j_inicial-1))) {//(+2,-1)
            if ((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+2))&&((*j_final)==(*j_inicial+1))) {//(+2,+1)
            if ((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+1))&&((*j_final)==(*j_inicial-2))) {//(+1,-2)
            if ((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-1))&&((*j_final)==(*j_inicial-2))) {//(-1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+1))&&((*j_final)==(*j_inicial+2))) {//(+1,+2)
            if ((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-1))&&((*j_final)==(*j_inicial+2))) {//(-1,+2)
            if ((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-2))&&((*j_final)==(*j_inicial-1))) {//(-2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-2))&&((*j_final)==(*j_inicial+1))) {//(-2,+1)
            if ((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
        
    }
    
    
    if ((tablero[*i_inicial][*j_inicial])=='c') {//caballo blancas
        
        if (((*i_final)==(*i_inicial+2))&&((*j_final)==(*j_inicial-1))) {//(+2,-1)
            if (((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+2))&&((*j_final)==(*j_inicial+1))) {//(+2,+1)
            if (((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+1))&&((*j_final)==(*j_inicial-2))) {//(+1,-2)
            if (((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-1))&&((*j_final)==(*j_inicial-2))) {//(-1,-2)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial+1))&&((*j_final)==(*j_inicial+2))) {//(+1,+2)
            if (((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-1))&&((*j_final)==(*j_inicial+2))) {//(-1,+2)
            if (((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-2))&&((*j_final)==(*j_inicial-1))) {//(-2,-1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else if (((*i_final)==(*i_inicial-2))&&((*j_final)==(*j_inicial+1))) {//(-2,+1)
            if (((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
    }
    return 1;
}

int alfiles (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]) {
    int comprobar_diagonales=0,i,j;
    
    if ((tablero[*i_inicial][*j_inicial])=='A') { //alfil negras
        if ((tablero[*i_final][*j_final]>='a')||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*j_final)>(*j_inicial))&&((*i_final)>(*i_inicial))) {
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*j_final)>(*j_inicial))&&((*i_final)<(*i_inicial))) {
                for (j=*i_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial-1; j>(*j_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*j_final)<(*j_inicial))&&((*i_final)<(*i_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial-1; j>(*i_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*j_final)<(*j_inicial))&&((*i_final)>(*i_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
    }

    if ((tablero[*i_inicial][*j_inicial])=='a') { //alfil blancas
        if (((tablero[*i_final][*j_final]>='A')&&(tablero[*i_final][*j_final]<='T'))||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*j_final)>(*j_inicial))&&((*i_final)>(*i_inicial))) {
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*j_final)>(*j_inicial))&&((*i_final)<(*i_inicial))) {
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial-1; j>(*i_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*j_final)<(*j_inicial))&&((*i_final)<(*i_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial-1; j>(*i_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*j_final)<(*j_inicial))&&((*i_final)>(*i_inicial))) {
                for (j=*j_inicial-1; j>(*i_final); j--) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else{
                return 1;
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
            
            if (((*i_final)>(*i_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*i_inicial+1); i<(*i_final); i++) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else if (((*i_final)<(*i_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*i_inicial-1); i>(*i_final); i--) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else if (((*j_final)>(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else if (((*j_final)<(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
        
    }

    if ((tablero[*i_inicial][*j_inicial])=='t') { //torre blancas
        if (((tablero[*i_final][*j_final]>='A')&&(tablero[*i_final][*j_final]<='T'))||(tablero[*i_final][*j_final]=='.')) {
            
            if (((*i_final)>(*i_inicial))&&((*j_final)==(*j_inicial))) {
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
            
            if (((*j_final)>(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*j_final)<(*j_inicial))&&((*i_final)==(*i_inicial))) {
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
        
        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial+1))) {//(+1,+1)
            if ((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial+1))) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial-1))) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial-1))) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial))) {//(+1,0)
            if ((*i_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial))) {//(-1,0)
            if ((*i_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial)) && ((*j_final)==(*j_inicial+1))) {//(0,+1)
            if ((*j_final<8)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial)) && ((*j_final)==(*j_inicial-1))) {//(0,-1)
            if ((*j_final>=0)&&(((tablero[*i_final][*j_final])>='a')||((tablero[*i_final][*j_final])=='.'))) {
                return 0;
            }else{
                return 1;
            }
        }
    }
    
     if ((tablero[*i_inicial][*j_inicial])=='r') { //rey blancas
        
        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial+1))) {//(+1,+1)
            if (((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial+1))) {//(-1,+1)
            if (((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial-1))) {//(-1,-1)
            if (((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial-1))) {//(+1,-1)
            if (((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial+1)) && ((*j_final)==(*j_inicial))) {//(+1,0)
            if (((*i_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial-1)) && ((*j_final)==(*j_inicial))) {//(-1,0)
            if (((*i_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial)) && ((*j_final)==(*j_inicial+1))) {//(0,+1)
            if (((*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T')))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if (((*i_final)==(*i_inicial)) && ((*j_final)==(*j_inicial-1))) {//(0,-1)
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
            
            if (((*j_final)>(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*j_final)<(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)>(*j_inicial))) { //movimientos como alfil
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)>(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial-1; j>(*j_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial-1; j>(*i_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }
            
            if (((*i_final)<(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
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
            }else if (((*i_final)<(*i_inicial))&&((*j_final)==(*j_inicial))) {
                for (i=(*i_inicial-1); i>(*i_final); i--) {
                    if ((tablero[i][*j_inicial])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else if (((*j_final)>(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial+1); i<(*j_final); i++) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else if (((*j_final)<(*j_inicial))&&((*i_final)==(*i_inicial))) {
                for (i=(*j_inicial-1); i>(*j_final); i--) {
                    if ((tablero[*i_inicial][i])!='.') {
                        comprobar_ejes=1;
                    }
                }
                return comprobar_ejes;
            }else if (((*i_final)>(*i_inicial))&&((*j_final)>(*j_inicial))) { //movimientos como alfil
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*i_final)>(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (j=*j_inicial+1; j<(*j_final); j++) {
                    for (i=*i_inicial-1; j>(*i_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*i_final)<(*i_inicial))&&((*j_final)<(*j_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial-1; j>(*i_final); i--) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else if (((*i_final)<(*i_inicial))&&((*j_final)>(*j_inicial))) {
                for (j=*j_inicial-1; j>(*j_final); j--) {
                    for (i=*i_inicial+1; j<(*i_final); i++) {
                        if ((tablero[i][j])!='.') {
                            comprobar_diagonales=1;
                        }
                    }
                }
                return comprobar_diagonales;
            }else{
                return 1;
            }
            
        }else{
            return 1;
        }
    }
    return 1;
}
