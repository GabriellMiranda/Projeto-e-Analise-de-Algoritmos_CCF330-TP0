//
// Created by pedro on 24/11/2021.
//

#include "figuras.h"
char** allocaEspaco(int linhas,int colunas){
    char **matriz = (char**) malloc(linhas*2*sizeof(char));
    for(int i = 0;i<linhas;i++){
        matriz[i] = (char*) malloc(colunas *2* sizeof(char));
    }
    return matriz;
}

char** criaFiguraPonto(){
    char **ponto = allocaEspaco(LINHASSIMBOLOPONTO,COLUNASSIMBOLOPONTO);
    for(int i = 0;i<LINHASSIMBOLOPONTO;i++){
        for(int j = 0;j<COLUNASSIMBOLOPONTO;j++){
            if(i == 1 && j == 1){
                ponto[i][j] = '*';
            }
            else{
                ponto[i][j] = ' ';
            }
        }
    }
    return ponto;
}
char** criaFiguraSoma(){
    char **figura = allocaEspaco(LINHASIMBOLOSOMA,COLUNASSIMBOLOSOMA);
    for(int i = 0;i<LINHASIMBOLOSOMA;i++){
        for(int j = 0;j<COLUNASSIMBOLOSOMA;j++){
            if((i == 0 || i == LINHASIMBOLOSOMA - 1) && j%2 == 0){
                figura[i][j] = ' ';
            }
            else{
                figura[i][j] = '*';
            }
        }
    }
    return figura;
}

char** criaFiguraX(){
    char **figura = allocaEspaco(LINHASSIMBOLOX,COLUNASSIMBOLOX);
    for(int i = 0;i<LINHASSIMBOLOX;i++){
        for(int j = 0;j<COLUNASSIMBOLOX;j++){
            if(((i == 0 || i == 2) && j%2 == 0) || (i==1 && j == 1)){
                figura[i][j] = '*';
            }
            else{
                figura[i][j] = ' ';
            }
        }
    }
    return figura;
}

void imprimeFigura(char **figura,int linhas,int colunas){
    for(int i = 0;i<linhas;i++){
        for(int j = 0;j<colunas;j++){
            printf("%c",figura[i][j]);
        }
        printf("\n");
    }
}