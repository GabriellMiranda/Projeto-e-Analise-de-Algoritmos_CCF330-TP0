//
// Created by pedro on 10/12/2021.
//

#ifndef AJUDA_CASINHADOG_H
#define AJUDA_CASINHADOG_H

#include "Figura_dog.h"

#define TAMCORPOCASA 8
#define TAMPORTACASA 4

#define TAMLINHACASA 9
#define TAMCOLUNACASA 10

typedef struct{
    char **figura;
}figuraCasa;

typedef struct {
    int linhaInicio;
    int linhaFim;
    int colunaInicio;
    int colunaFim;
}coordenadasCasa;


char** criaCorpoCasa(int colunas);
char** criaTelhado();
char** criaCasaDog();
coordenadasCasa *criaCoordenadasCasa();
void insereFigurasNaCasa(char **casa,char **figura,coordenadasCasa *coordenadas);


#endif //AJUDA_CASINHADOG_H
