#ifndef QUADRO_H
#define QUADRO_H

#define LINHAS 20
#define COLUNAS 80

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char quadro[LINHAS][COLUNAS];
}Tela;

void criaQuadro(Tela *tela);
void imprimeQuadro(Tela *tela);

#endif