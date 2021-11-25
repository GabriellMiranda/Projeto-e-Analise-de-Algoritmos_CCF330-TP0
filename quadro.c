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
void allocaFiguras(Tela *tela,char  **figura,int linhas,int colunas,int quantidade){
    srand(time(NULL));
    for(int i = 0;i<quantidade;i++){
        coordenadasQuadro coordenadas = criaCoordenada(tela,linhas,colunas);
        insereFigura(tela,figura,&coordenadas);
    }
}
void allocaFigurasAleatorias(Tela *tela,int quantidade){
    srand(time(NULL));
    int opcao;
    for(int i = 0;i<quantidade;i++) {
        opcao = rand() % 3;
        if(opcao == 0){
            coordenadasQuadro coordenadas = criaCoordenada(tela,LINHASSIMBOLOPONTO,COLUNASSIMBOLOPONTO);
            insereFigura(tela,criaFiguraPonto(), &coordenadas);
        }
        else if(opcao == 1){
            coordenadasQuadro coordenadas = criaCoordenada(tela,LINHASIMBOLOSOMA,COLUNASSIMBOLOSOMA);
            insereFigura(tela,criaFiguraSoma(),&coordenadas);
        }
        else if(opcao == 2){
            coordenadasQuadro coordenadas = criaCoordenada(tela,LINHASSIMBOLOX,COLUNASSIMBOLOX);
            insereFigura(tela,criaFiguraX(),&coordenadas);
        }
    }
}
coordenadasQuadro criaCoordenada(Tela *tela,int linhas,int colunas) {
    coordenadasQuadro coordenadas;
    int linha, coluna;
    int verify = 0;
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
        verify = 0;
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
    printf("\n");
    for(int i = 0; i < LINHASQUADRO; i++){
        for(int j = 0; j < COLUNASQUADRO; j++){
            printf("%c",tela->quadro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}