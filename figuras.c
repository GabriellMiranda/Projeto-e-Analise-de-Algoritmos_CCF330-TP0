//
// Created by pedro on 24/11/2021.
//

#include "figuras.h"
char** allocaEspaco(int linhas,int colunas){
    char **matriz = (char**) malloc(linhas*sizeof(char));
    for(int i = 0;i<linhas;i++){
        matriz[i] = (char*) malloc(colunas * sizeof(char));
    }
    return matriz;
}
void criaFiguraSoma(simboloSoma *simbolosoma){
    simbolosoma->figura = allocaEspaco(LINHASIMBOLOSOMA,COLUNASSIMBOLOSOMA);
    for(int i = 0;i<LINHASIMBOLOSOMA;i++){
        for(int j = 0;j<COLUNASSIMBOLOSOMA;j++){
            if((i == 0 || i == LINHASIMBOLOSOMA - 1) && j%2 == 0){
                simbolosoma->figura[i][j] = ' ';
            }
            else{
                simbolosoma->figura[i][j] = '*';
            }
        }
    }
}

void imprimeFigura(char **figura,int linhas,int colunas){
    for(int i = 0;i<linhas;i++){
        for(int j = 0;j<colunas;j++){
            printf("%c",figura[i][j]);
        }
        printf("\n");
    }
}