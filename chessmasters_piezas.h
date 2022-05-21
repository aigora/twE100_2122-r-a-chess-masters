#include <stdio.h>

int peones (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
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
}

int caballos (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
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
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial+2])) {//(+1,+2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial+1])) {//(-2,+1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-2][*j_inicial-1])) {//(-2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial+1])) {//(+2,+1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+2][*j_inicial-1])) {//(+2,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-2])) {//(-1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-2])) {//(+1,-2)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
    }
}

int alfiles (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
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
}

int torres (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
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
}

int reyes (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
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
            if ((*i_final<8)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
        
        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial+1])) {//(-1,+1)
            if ((*i_final>=0)&&(*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial-1])) {//(-1,-1)
            if ((*i_final>=0)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial-1])) {//(+1,-1)
            if ((*i_final<8)&&(*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial+1][*j_inicial])) {//(+1,0)
            if ((*i_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial-1][*j_inicial])) {//(-1,0)
            if ((*i_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial+1])) {//(0,+1)
            if ((*j_final<8)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }

        if ((tablero[*i_final][*j_final])==(tablero[*i_inicial][*j_inicial-1])) {//(0,-1)
            if ((*j_final>=0)&&(((tablero[*i_final][*j_final])>='A')&&((tablero[*i_final][*j_final])<='T'))||((tablero[*i_final][*j_final])=='.')) {
                return 0;
            }else{
                return 1;
            }
        }
    }
}

int damas (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
    
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


