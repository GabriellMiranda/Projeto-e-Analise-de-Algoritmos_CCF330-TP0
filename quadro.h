#ifndef QUADRO_H
#define QUADRO_H

#define LINHASQUADRO 20
#define COLUNASQUADRO 80

#include "figuras.h"
#include <stdbool.h>

typedef struct{
    char quadro[LINHASQUADRO][COLUNASQUADRO];
}Tela;

typedef struct{
    int linhaInicio;
    int linhaFim;
    int colunaInicio;
    int colunaFim;
}coordenadasQuadro;

void criaQuadro(Tela *tela);
void insereFigura(Tela *tela,char **figura,coordenadasQuadro *coordenadas);
coordenadasQuadro criaCoordenada(Tela *tela,int linhas,int colunas);
void imprimeQuadro(Tela *tela);

#endif