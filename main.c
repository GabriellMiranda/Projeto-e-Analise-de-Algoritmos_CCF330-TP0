#include "quadro.h"

int main(){
    printf("\n\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|        Programacao e Analise de Algoritmos - CCF 330               |\n");
    printf("|                       Trabalho Pratico                             |\n");
    printf("|                  Gabriel Miranda - EFO3857                         |\n");
    printf("|                    Pedro Maia - EF08983                            |\n");
    printf("|--------------------------------------------------------------------|\n\n");
    int tipofigura;
    int qtdfiguras;
    int opcao2;
    Tela tela;
    bool op1 = true;
    criaQuadro(&tela);
    CriaSoma(&tela, 20);

    //------------ Teste de inserção de figura ----------
//    simboloSoma teste;
//    criaFiguraSoma(&teste);
//    coordenadasQuadro coordena;
//    coordena.linhaInicio = 9;
//    coordena.linhaFim = 12;
//    coordena.colunaInicio = 9;
//    coordena.colunaFim = 12;
//    insereFigura(&tela,teste.figura,&coordena);
    // ---------------------------------------------------


    imprimeQuadro(&tela);


    while(op1 == true){
        printf("|--------------------------------------------------------------------|\n");
        printf("|PROGRAMA GERADOR DE ARTE:                                           |\n");
        printf("|=========================                                           |\n");
        printf("|Escolha o tipo de figura basica a ser usada para criar a obra:      |\n");
        printf("|   1 - asterisco simples.                                           |\n");
        printf("|   2 - simbolo de soma com asteriscos.                              |\n");
        printf("|   3 - letra x com asteriscos.                                      |\n");
        printf("|   4 - figuras aleatorias.                                          |\n");
        printf("|   5 - opcao de obra de arte criada pelo aluno:                     |\n");
        printf("|--------------------------------------------------------------------|\n");
        printf("Digite o tipo de figura basica desejada: ");
        scanf("%d", &tipofigura);
        printf("Digite a quantidade de figura(menor ou igual a zero para aleatorio: )");
        scanf("%d", &qtdfiguras);
    }
    return 0;
}