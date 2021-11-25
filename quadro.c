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

coordenadasQuadro criaCoordenada(Tela *tela,int linhas,int colunas){// As coordenadas devem ter o tamanho de linhas
    // e o tamanho de colunas da figura

}// Ela deve retornar uma coordenada que seja possivel dentro do quadro e que não esteja ocupada

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

void CriaSoma(Tela *tela, int quantidade){
    srand(time(NULL));
    int coluna, linha;
    for(int i = 0; i < quantidade; i++){
        while (true){
            linha = 1 + (rand() % LINHASQUADRO-2);
            coluna = 1 + (rand() % COLUNASQUADRO-2);
            if(tela->quadro[linha][coluna] == ' ' && tela->quadro[linha+1][coluna] == ' ' && tela->quadro[linha-1][coluna] == ' ' && tela->quadro[linha][coluna-1] == ' ' && tela->quadro[linha][coluna+1] == ' '){
                break;
            }
        }
        tela->quadro[linha][coluna] = '*';
        tela->quadro[linha+1][coluna] = '*';
        tela->quadro[linha-1][coluna] = '*';
        tela->quadro[linha][coluna+1] = '*';
        tela->quadro[linha][coluna-1] = '*';
        
    }
}

void imprimeQuadro(Tela *tela){
    for(int i = 0; i < LINHASQUADRO; i++){
        for(int j = 0; j < COLUNASQUADRO; j++){
            printf("%c",tela->quadro[i][j]);
        }
        printf("\n");
    }
}