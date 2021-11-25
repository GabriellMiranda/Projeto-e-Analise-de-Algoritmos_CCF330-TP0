//
// Created by pedro on 24/11/2021.
//

#ifndef AJUDA_FIGURAS_H
#define AJUDA_FIGURAS_H

#define LINHASIMBOLOSOMA 3
#define COLUNASSIMBOLOSOMA 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char **figura;
}simboloSoma;

char** allocaEspaco(int linhas,int colunas);
void criaFiguraSoma(simboloSoma *simbolosoma);
void imprimeFigura(char **figura,int linhas,int colunas);

#endif //AJUDA_FIGURAS_H
