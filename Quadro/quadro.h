#ifndef QUADRO_H
#define QUADRO_H

#define LINHASQUADRO 20
#define COLUNASQUADRO 80

#include "../CasaDog/CasinhaDog.h"
#include <stdbool.h>
#include <time.h>

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
Tela allocaFiguras(char  **figura,int linhas,int colunas,int quantidade);
Tela allocaFigurasAleatorias(int quantidade);
Tela allocaObra(int quantidade,int *casas,int *dogs);
int geradorAleatorio(int numero, int *tipofigura);
void imprimeQuadro(Tela *tela);

#endif