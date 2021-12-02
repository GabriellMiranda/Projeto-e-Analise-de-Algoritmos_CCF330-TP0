//
// Created by pedro on 01/12/2021.
//

#include "Obra_de_arte.h"
void criaOrelhaEsquerda(partesObra *partes){
    int colunaBarraSimples;
    int colunaBarraInvertida;
    int qtdQuebra = 2;
    int fechamento = 0;
    for(int i = 0;i<TAMORELHAESQUERDA;i++){
        if(i == 0){
            colunaBarraSimples = TAMORELHAESQUERDA / 2;
            colunaBarraInvertida = TAMORELHAESQUERDA / 2 + 1;
        }
        for(int j = 0;j<TAMORELHAESQUERDA;j++){
            if(j == colunaBarraSimples || (j == colunaBarraInvertida-1 && i>=qtdQuebra && i< TAMORELHAESQUERDA - qtdQuebra)){
                partes->orelhaEsquerda[i][j] = '/';
            }
            else if((j == colunaBarraInvertida && i<qtdQuebra) || (j == fechamento && i >= TAMORELHAESQUERDA - qtdQuebra - 2 && i < TAMORELHAESQUERDA - qtdQuebra)){
                partes->orelhaEsquerda[i][j] = '\\';
            }
            else{
                partes->orelhaEsquerda[i][j] = ' ';
            }
        }
        if(i >= TAMORELHAESQUERDA - qtdQuebra - 2 && fechamento < qtdQuebra){
            fechamento++;
        }
        if(colunaBarraSimples >= 0){
            colunaBarraSimples--;
        }
        if(i<qtdQuebra){
            colunaBarraInvertida++;
        }
        else if(i>=qtdQuebra){
            colunaBarraInvertida--;
        }
    }
}
void criaOrelhaDireita(partesObra *partes){
    int colunaBarraSimples;
    int colunaBarraInvertida;
    int qtdQuebra = 2;
    int fechamento = TAMORELHADIREITA - 1;
    for(int i = 0;i<TAMORELHADIREITA;i++){
        if(i == 0){
            colunaBarraSimples = TAMORELHADIREITA / 2 - 1;
            colunaBarraInvertida = TAMORELHADIREITA / 2;
        }
        for(int j = 0;j<TAMORELHADIREITA;j++){
            if(j == colunaBarraInvertida || (j == colunaBarraSimples+1 && i>=qtdQuebra && i< TAMORELHADIREITA - qtdQuebra - 2)){
                partes->orelhaDireita[i][j] = '\\';
            }
            else if(j == colunaBarraSimples && i<qtdQuebra || (i >= TAMORELHADIREITA - qtdQuebra - 5 && j == fechamento && i < TAMORELHADIREITA - qtdQuebra - 2)){
                partes->orelhaDireita[i][j] = '/';
            }
            else{
                partes->orelhaDireita[i][j] = ' ';
            }
        }
        if(i < qtdQuebra){
            colunaBarraSimples--;
        }
        if(i>=qtdQuebra){
            colunaBarraSimples++;
        }
        if(i >= TAMORELHADIREITA - qtdQuebra - 4){
            fechamento--;
        }
        colunaBarraInvertida++;
    }
}
void insereFiguraNaObra(obraDeArte *obra,partesObra *partes,coordenadasObra *coordenadas,int tipo){
    int posicaoLinha = 0;
    int posicaoColuna = 0;
    if(tipo == 1) {
        for (int i = coordenadas->linhaInicio; i < coordenadas->linhaFim; i++) {
            for (int j = coordenadas->colunaInicio; j < coordenadas->colunaFim; j++) {
                obra->arte[i][j] = partes->testaOlhos[posicaoLinha][posicaoColuna];
                posicaoColuna++;
            }
            posicaoColuna = 0;
            posicaoLinha++;
        }
    }
    else if(tipo == 2){
        for (int i = coordenadas->linhaInicio; i < coordenadas->linhaFim; i++) {
            for (int j = coordenadas->colunaInicio; j < coordenadas->colunaFim; j++) {
                obra->arte[i][j] = partes->boca[posicaoLinha][posicaoColuna];
                posicaoColuna++;
            }
            posicaoColuna = 0;
            posicaoLinha++;
        }
    }
    else if(tipo == 3){
        for (int i = coordenadas->linhaInicio; i < coordenadas->linhaFim; i++) {
            for (int j = coordenadas->colunaInicio; j < coordenadas->colunaFim; j++) {
                obra->arte[i][j] = partes->barrigaEpatinha[posicaoLinha][posicaoColuna];
                posicaoColuna++;
            }
            posicaoColuna = 0;
            posicaoLinha++;
        }
    }
    else if(tipo == 4){
        for (int i = coordenadas->linhaInicio; i < coordenadas->linhaFim; i++) {
            for (int j = coordenadas->colunaInicio; j < coordenadas->colunaFim; j++) {
                obra->arte[i][j] = partes->orelhaEsquerda[posicaoLinha][posicaoColuna];
                posicaoColuna++;
            }
            posicaoColuna = 0;
            posicaoLinha++;
        }
    }
    else if(tipo == 5){
        for (int i = coordenadas->linhaInicio; i < coordenadas->linhaFim; i++) {
            for (int j = coordenadas->colunaInicio; j < coordenadas->colunaFim; j++) {
                obra->arte[i][j] = partes->orelhaDireita[posicaoLinha][posicaoColuna];
                posicaoColuna++;
            }
            posicaoColuna = 0;
            posicaoLinha++;
        }
    }
}
void constroiObra(partesObra *partes,obraDeArte *obra){
    for(int i = 0;i<TAMOBRA;i++){
        for(int j = 0;j<TAMOBRA;j++){
            obra->arte[i][j] = ' ';
        }
    }
    coordenadasObra *coordenadas = criaCoordenadas();
    insereFiguraNaObra(obra,partes,&coordenadas[4],5);
    insereFiguraNaObra(obra,partes,&coordenadas[0],1);
    insereFiguraNaObra(obra,partes,&coordenadas[3],4);
    insereFiguraNaObra(obra,partes,&coordenadas[1],2);
    insereFiguraNaObra(obra,partes,&coordenadas[2],3);
}

coordenadasObra *criaCoordenadas(){
    coordenadasObra *coordenadas = (coordenadasObra*) malloc(5 * sizeof (coordenadasObra));
    coordenadasObra testa,boca,corpo,orelhaEsquerda,orelhaDireita;
    testa.linhaInicio = 1;testa.linhaFim = TAMTESTAOLHOS;
    testa.colunaInicio = TAMOBRA/2 - TAMTESTAOLHOS/2;testa.colunaFim = TAMOBRA/2 + TAMTESTAOLHOS/2;
    coordenadas[0] = testa;

    boca.linhaInicio = TAMTESTAOLHOS-7;boca.linhaFim = TAMTESTAOLHOS - 7 + LINHASRETANGULOBOCA;
    boca.colunaInicio = TAMOBRA/2 - COLUNASRETANGULOBOCA/2;boca.colunaFim = TAMOBRA/2 + COLUNASRETANGULOBOCA/2;
    coordenadas[1] = boca;

    corpo.linhaInicio = LINHASRETANGULOBOCA+5;corpo.linhaFim = LINHASRETANGULOBOCA + TAMQUADRADOBARRIGA;
    corpo.colunaInicio = TAMOBRA/2 - TAMQUADRADOBARRIGA/2;corpo.colunaFim = TAMOBRA/2 + TAMQUADRADOBARRIGA/2;
    coordenadas[2] = corpo;

    orelhaEsquerda.linhaInicio = 1;orelhaEsquerda.linhaFim = TAMORELHAESQUERDA + 1;
    orelhaEsquerda.colunaInicio = TAMOBRA/2 - TAMORELHAESQUERDA/2 - 12;orelhaEsquerda.colunaFim = TAMOBRA/2 + TAMORELHAESQUERDA/2 - 12;
    coordenadas[3] = orelhaEsquerda;

    orelhaDireita.linhaInicio = 1;orelhaDireita.linhaFim = TAMORELHADIREITA+1;
    orelhaDireita.colunaInicio = TAMOBRA/2 + TAMORELHAESQUERDA/2 ;orelhaDireita.colunaFim = TAMOBRA - TAMORELHADIREITA - 5;
    coordenadas[4] = orelhaDireita;
    return coordenadas;
}
partesObra criaPartes(){
    partesObra partes;
    criaTestaEolhos(&partes);
    criaBocaDog(&partes);
    criaBarrigaEpatinhaDog(&partes);
    criaOrelhaEsquerda(&partes);
    criaOrelhaDireita(&partes);
    return partes;
}
void imprimeObra(obraDeArte *obra){
    for(int i = 0;i<18;i++){
        for(int j = 18;j<52;j++){
            printf("%c",obra->arte[i][j]);
        }
        printf("\n");
    }
}
void criaTestaEolhos(partesObra *partes){
    for(int i = 0;i<TAMTESTAOLHOS;i++){
        for(int j = 0;j<TAMTESTAOLHOS;j++){
            if(i == 0){
                partes->testaOlhos[i][j] = '-';
            }
            else if((j == 0 || j == TAMTESTAOLHOS - 1) && i < TAMTESTAOLHOS/2 - 2){
                partes->testaOlhos[i][j] = '|';
            }
            else if((i == TAMTESTAOLHOS/2 - 3) && (j == TAMTESTAOLHOS/4 || j == TAMTESTAOLHOS - TAMTESTAOLHOS/4 - 1)){
                partes->testaOlhos[i][j] = '*';
            }
            else{
                partes->testaOlhos[i][j] = ' ';
            }
        }
    }
}
void criaBocaDog(partesObra *partes){
    for(int i = 0;i<LINHASRETANGULOBOCA;i++){
        for(int j = 0;j<COLUNASRETANGULOBOCA;j++){
            if(i == 0 || i == LINHASRETANGULOBOCA - 1){
                partes->boca[i][j] = '-';
            }
            else if(j == 0 || j == COLUNASRETANGULOBOCA - 1 || j == (COLUNASRETANGULOBOCA/2 - 1)){
                partes->boca[i][j] = '|';
            }
            else{
                partes->boca[i][j] = ' ';
            }
        }
    }
}
void criaBarrigaEpatinhaDog(partesObra *partes){
    int colunaBarraSimples,colunaPatinha1,colunaPatinha2;
    int colunaBarraInvertida;
    for(int i = 0; i < TAMQUADRADOBARRIGA; i++){
        if(i == 0){
            colunaBarraSimples = TAMQUADRADOBARRIGA / 2 - 1;
            colunaBarraInvertida = TAMQUADRADOBARRIGA / 2;
        }
        for(int j = 0; j < TAMQUADRADOBARRIGA; j++){
            if(j == colunaBarraSimples){
                partes->barrigaEpatinha[i][j] = '/';
            }
            else if(j == colunaBarraInvertida){
                partes->barrigaEpatinha[i][j] = '\\';
            }
            else if(i == TAMQUADRADOBARRIGA / 2 - 1 && (j > colunaBarraSimples && j < colunaBarraInvertida)){
                partes->barrigaEpatinha[i][j] = '-';
                colunaPatinha1 = colunaBarraSimples;
                colunaPatinha2 = colunaBarraInvertida;
            }
            else if((i == TAMQUADRADOBARRIGA/2 || i == TAMQUADRADOBARRIGA/2 +1) &&
            (j == colunaPatinha1  || j == colunaPatinha2 || j == colunaPatinha1 + TAMQUADRADOBARRIGA/5 + 1 ||
            j == colunaPatinha2 - TAMQUADRADOBARRIGA/5 - 1)){
                partes->barrigaEpatinha[i][j] = '|';
            }
            else if((i == TAMQUADRADOBARRIGA/2 + 1) && (j>colunaPatinha1 && j<colunaPatinha1 + TAMQUADRADOBARRIGA/5 + 1)){
                partes->barrigaEpatinha[i][j] = '-';
            }
            else if((i == TAMQUADRADOBARRIGA/2 + 1) && (j>colunaPatinha2 - TAMQUADRADOBARRIGA/5 - 1 && j<colunaPatinha2)){
                partes->barrigaEpatinha[i][j] = '-';
            }
            else{
                partes->barrigaEpatinha[i][j] = ' ';
            }
        }
        colunaBarraSimples--;
        colunaBarraInvertida++;
    }
}
char** organizaObra(obraDeArte *obra){
    char **figura = allocaEspaco(50,50);
    int coluna = 0;
    for(int i = 0;i<18;i++){
        for(int j = 18;j<52;j++){
            figura[i][coluna] = obra->arte[i][j];
            coluna++;
        }
        coluna = 0;
    }
    return figura;
}