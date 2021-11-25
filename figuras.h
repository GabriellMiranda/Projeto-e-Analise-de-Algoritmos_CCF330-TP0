//
// Created by pedro on 24/11/2021.
//

#ifndef AJUDA_FIGURAS_H
#define AJUDA_FIGURAS_H

#define LINHASIMBOLOSOMA 3
#define COLUNASSIMBOLOSOMA 3
#define LINHASSIMBOLOPONTO 3
#define COLUNASSIMBOLOPONTO 3
#define LINHASSIMBOLOX 3
#define COLUNASSIMBOLOX 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allocaEspaco(int linhas,int colunas);
char** criaFiguraSoma();
char** criaFiguraPonto();
char** criaFiguraX();
void imprimeFigura(char **figura,int linhas,int colunas);

#endif //AJUDA_FIGURAS_H
