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
    
    return 1;
}

int torres (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
    return 1;
}

int reyes (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
    return 1;
}

int damas (int *i_inicial, int *j_inicial, int *i_final, int *j_final, char tablero[8][8]){
    
    return 1;
}


