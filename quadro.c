#include "quadro.h"

void criaQuadro(Tela *tela){
    for(int i = 0;i<LINHAS;i++){
        for(int j = 0;j<COLUNAS;j++){
            if(i == 0 || i == (LINHAS - 1)){
                tela->quadro[i][j] = '-';
            }
            else if(j == 0 || j == (COLUNAS - 1)){
                tela->quadro[i][j] = '|';
            }
            else{
                tela->quadro[i][j] = ' ';
            }
        }
    }
}

void imprimeQuadro(Tela *tela){
    for(int i = 0;i<LINHAS;i++){
        for(int j = 0;j<COLUNAS;j++){
            printf("%c",tela->quadro[i][j]);
        }
        printf("\n");
    }
}