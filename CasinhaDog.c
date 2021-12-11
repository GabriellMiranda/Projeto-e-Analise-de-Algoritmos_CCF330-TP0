//
// Created by pedro on 10/12/2021.
//

#include "CasinhaDog.h"

char** criaCorpoCasa(int colunas){
    char** corpo = allocaEspaco(10,10);
    for(int i = 0;i<colunas/2 + 1;i++){
        for(int j = 0;j<colunas;j++){
            if(i == 0 || i == colunas/2){
                corpo[i][j] = '-';
            }
            else if(j == 0 || j == colunas - 1){
                corpo[i][j] = '|';
            }
            else
                corpo[i][j] = ' ';
        }
    }
    return corpo;
}
char** criaTelhado(){
    char** telhado = allocaEspaco(20, 20);
    int positionEsquerda = 5;
    int positionDireita = 5;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<12;j++){
            if(j == positionEsquerda){
                telhado[i][j] = '/';
            }
            else if(j == positionDireita + 1){
                telhado[i][j] = '\\';
            }
            else{
                telhado[i][j] = ' ';
            }
        }
        positionDireita++;
        positionEsquerda--;
    }
    return telhado;
}

coordenadasCasa *criaCoordenadasCasa(){
    coordenadasCasa *coordenadas = (coordenadasCasa *) malloc(3 * sizeof (coordenadasCasa));
    coordenadasCasa telhado,corpo,porta;

    telhado.linhaInicio = 0;telhado.linhaFim = 4;
    telhado.colunaInicio = 0;telhado.colunaFim = 12;
    coordenadas[0] = telhado;

    corpo.linhaInicio = 4;corpo.linhaFim = 9;
    corpo.colunaInicio = 2;corpo.colunaFim = 10;
    coordenadas[1] = corpo;

    porta.linhaInicio = 6;porta.linhaFim = 9;
    porta.colunaInicio = 4;porta.colunaFim = 8;
    coordenadas[2] = porta;

    return coordenadas;
}
char** criaCasaDog(){
    char **casa = allocaEspaco(30,30);
    for(int i = 0;i<9;i++){
        for(int j = 0;j<10;j++){
            casa[i][j] = ' ';
        }
    }
    coordenadasCasa *coordenadas = criaCoordenadasCasa();
    insereFigurasNaCasa(casa,criaTelhado(),&coordenadas[0]);
    insereFigurasNaCasa(casa, criaCorpoCasa(TAMCORPOCASA),&coordenadas[1]);
    insereFigurasNaCasa(casa, criaCorpoCasa(TAMPORTACASA),&coordenadas[2]);

    return casa;
}
void insereFigurasNaCasa(char **casa,char **figura,coordenadasCasa *coordenadas){
    int posicaoLinha = 0;
    int posicaoColuna = 0;
    for (int i = coordenadas->linhaInicio; i < coordenadas->linhaFim; i++) {
        for (int j = coordenadas->colunaInicio; j < coordenadas->colunaFim; j++) {
            casa[i][j] = figura[posicaoLinha][posicaoColuna];
            posicaoColuna++;
        }
        posicaoColuna = 0;
        posicaoLinha++;
    }
}