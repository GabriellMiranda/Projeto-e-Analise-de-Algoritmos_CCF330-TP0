//
// Created by pedro on 01/12/2021.
//

#ifndef AJUDA_OBRA_DE_ARTE_H
#define AJUDA_OBRA_DE_ARTE_H

#include "figuras.h"

#define linhasObraFinal 18
#define colunasObraFinal 34


#define LINHASRETANGULOBOCA 4
#define COLUNASRETANGULOBOCA 20
#define TAMQUADRADOBARRIGA 15
#define TAMTESTAOLHOS 12
#define TAMOBRA 70
#define TAMORELHAESQUERDA 10
#define TAMORELHADIREITA 12

typedef struct{
    char arte[TAMOBRA][TAMOBRA];
}obraDeArte;

typedef struct{
    char barrigaEpatinha[TAMQUADRADOBARRIGA][TAMQUADRADOBARRIGA];
    char boca[LINHASRETANGULOBOCA][COLUNASRETANGULOBOCA];
    char testaOlhos[TAMTESTAOLHOS][TAMTESTAOLHOS];
    char orelhaEsquerda[TAMORELHAESQUERDA][TAMORELHAESQUERDA];
    char orelhaDireita[TAMORELHADIREITA][TAMORELHADIREITA];
}partesObra;

typedef struct {
    int linhaInicio;
    int linhaFim;
    int colunaInicio;
    int colunaFim;
}coordenadasObra;

void criaBarrigaEpatinhaDog(partesObra *partes);
void criaBocaDog(partesObra *partes);
void criaTestaEolhos(partesObra *partes);
void constroiObra(partesObra *partes,obraDeArte *obra);
void insereFiguraNaObra(obraDeArte *obra,partesObra *partes,coordenadasObra *coordenadas,int tipo);
coordenadasObra *criaCoordenadas();
void imprimeObra(obraDeArte *obra);
partesObra criaPartes();
void criaOrelhaEsquerda(partesObra *partes);
void criaOrelhaDireita(partesObra *partes);
char** organizaObra(obraDeArte *obra);

#endif //AJUDA_OBRA_DE_ARTE_H
