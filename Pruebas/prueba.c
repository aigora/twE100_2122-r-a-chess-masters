#include <stdio.h>

typedef struct
{
  int matriz[8][8];
  
} eval;

struct ptr *piezas[32];

void modificar_piezas(struct ptr *ptr_piezas);



int main()
{
    int i,j,k;
    //test_t (*test_array_ptr)[];
    //test_array_ptr = &array_t1;
    //(*test_array_ptr)[0] = new_struct;
   
    eval piezas[32];

   for (i = 0; i < 32; i++)
    {
        piezas[i] = malloc(sizeof(struct ptr_piezas));
    }
    struct ptr *(*ptr_piezas)[32] = &piezas;



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

    int eval_blancas[8][8];
    int eval_negras[8][8];
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
    
    //inicializar_matrices(piezas);

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

    modificar_piezas(&ptr_piezas);

    for(i=0;i<8;i++){
        printf("\n");
        for(j=0;j<8;j++){
            printf("%d",eval_negras[i][j]);
        }
    }
    printf("\n");
    /*
    char tablero[8][8];
    for(i=0;i<8;i++){
        printf("\n");
        for(j=0;j<8;j++){
            printf("%c",tablero[i][j]);
        }
    }
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
   */

    return 0;
}
void modificar_piezas(struct ptr *ptr_piezas){
    ptr_piezas[6]->matriz[3][3]=1;
    ptr_piezas[6]->matriz[4][4]=1;
}