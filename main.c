#include "quadro.h"

int main(){
    printf("\n\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|        Programacao e Analise de Algoritmos - CCF 330               |\n");
    printf("|                       Trabalho Pratico                             |\n");
    printf("|                  Gabriel Miranda - EFO3857                         |\n");
    printf("|                    Pedro Maia - EF08983                            |\n");
    printf("|--------------------------------------------------------------------|\n\n");
    int opcao1;
    Tela tela;
    bool op1 = true;
    criaQuadro(&tela);
    imprimeQuadro(&tela);
//    while(op1 == true){
//        printf("|--------------------------------------------------------------------|\n");
//        printf("|PROGRAMA GERADOR DE ARTE:                                           |\n");
//        printf("|=========================                                           |\n");
//        printf("|Escolha o tipo de figura basica a ser usada para criar a obra:      |\n");
//        printf("|   1 - asterisco simples.                                           |\n");
//        printf("|   2 - simbolo de soma com asteriscos.                              |\n");
//        printf("|   3 - letra x com asteriscos.                                      |\n");
//        printf("|   4 - figuras aleatorias.                                          |\n");
//        printf("|   5 - opcao de obra de arte criada pelo aluno:                     |\n");
//        printf("|   6 - sair.                                                        |\n");
//        printf("|--------------------------------------------------------------------|\n");
//        printf("Digite o tipo de figura basica desejada: ");
//        scanf("%d", &opcao1);
//        printf("Digite a quantidade de figura(menor ou igual a zero para aleatorio: )");
//        if(opcao1 == 6){
//            op1 = false;
//        }else{
//            printf("Opcao Invalida!!\n");
//        }
//    }
    return 0;
}