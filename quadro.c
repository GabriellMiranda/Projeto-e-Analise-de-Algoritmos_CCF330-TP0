#include "quadro.h"

void criaQuadro(Tela *tela){
    for(int i = 0; i < LINHASQUADRO; i++){
        for(int j = 0; j < COLUNASQUADRO; j++){
            if(i == 0 || i == (LINHASQUADRO - 1)){
                tela->quadro[i][j] = '-';
            }
            else if(j == 0 || j == (COLUNASQUADRO - 1)){
                tela->quadro[i][j] = '|';
            }
            else{
                tela->quadro[i][j] = ' ';
            }
        }
    }
}
Tela allocaFiguras(char  **figura,int linhas,int colunas,int quantidade){
    srand(time(NULL));
    Tela telaAux;
    coordenadasQuadro coordenadas;
    coordenadas.linhaInicio = -1;
    while (coordenadas.linhaInicio == -1) {
        criaQuadro(&telaAux);
        for (int i = 0; i < quantidade; i++) {
            coordenadas = criaCoordenada(&telaAux, linhas, colunas);
            if(coordenadas.linhaInicio == -1){
                break;
            }
            insereFigura(&telaAux, figura, &coordenadas);
        }
    }
    return telaAux;
}
Tela allocaFigurasAleatorias(int quantidade){
    srand(time(NULL));
    int opcao;
    Tela telaAux;
    coordenadasQuadro coordenadas;
    coordenadas.linhaInicio = -1;
    while (coordenadas.linhaInicio == -1) {
        printf("Pedro\n");
        criaQuadro(&telaAux);
        for (int i = 0; i < quantidade; i++) {
            opcao = rand() % 3;
            if (opcao == 0) {
                coordenadas = criaCoordenada(&telaAux, LINHASSIMBOLOPONTO, COLUNASSIMBOLOPONTO);
                insereFigura(&telaAux, criaFiguraPonto(), &coordenadas);
            } else if (opcao == 1) {
                coordenadas = criaCoordenada(&telaAux, LINHASIMBOLOSOMA, COLUNASSIMBOLOSOMA);
                insereFigura(&telaAux, criaFiguraSoma(), &coordenadas);
            } else if (opcao == 2) {
                coordenadas = criaCoordenada(&telaAux, LINHASSIMBOLOX, COLUNASSIMBOLOX);
                insereFigura(&telaAux, criaFiguraX(), &coordenadas);
            }
            if(coordenadas.linhaInicio == -1){
                break;
            }
        }
    }
    return telaAux;
}
coordenadasQuadro criaCoordenada(Tela *tela,int linhas,int colunas) {
    coordenadasQuadro coordenadas;
    int linha, coluna;
    int verify = 0;
    int tentativas = 0;
    while (1) {
        linha = rand() % LINHASQUADRO + 1;
        coluna = rand() % COLUNASQUADRO + 1;
        for (int i = linha; i < (linhas + linha); i++) {
            for (int j = coluna; j < (colunas + coluna); j++) {
                if (tela->quadro[i][j] == ' ') {
                    verify++;
                }
            }
        }
        if (verify == (linhas * colunas)) {
            coordenadas.linhaInicio = linha;
            coordenadas.linhaFim = linha + linhas;
            coordenadas.colunaInicio = coluna;
            coordenadas.colunaFim = coluna + colunas;
            break;
        }
        else if(tentativas > 50){
            coordenadas.linhaInicio = -1;
            coordenadas.linhaFim = -1;
            coordenadas.colunaInicio = -1;
            coordenadas.colunaFim = -1;
            break;
        }
        verify = 0;
        tentativas++;
    }
    return coordenadas;
}

void insereFigura(Tela *tela,char **figura,coordenadasQuadro *coordenadas){
    int posicaoLinha = 0;
    int posicaoColuna = 0;
    for(int i = coordenadas->linhaInicio; i < coordenadas->linhaFim;i++){
        for(int j = coordenadas->colunaInicio;j < coordenadas->colunaFim;j++){
            tela->quadro[i][j] = figura[posicaoLinha][posicaoColuna];
            posicaoColuna++;
        }
        posicaoColuna = 0;
        posicaoLinha++;
    }
}

int geradorAleatorio(int numero, int *tipofigura){
    if(numero <= 0){
        *tipofigura = 4;
        return 1 + rand() % 100;
    }
    if(numero > 100){
        *tipofigura = 4;
        return 100;
    }
    return numero;
}

void imprimeQuadro(Tela *tela){
    printf("\n");
    for(int i = 0; i < LINHASQUADRO; i++){
        for(int j = 0; j < COLUNASQUADRO; j++){
            printf("%c",tela->quadro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}