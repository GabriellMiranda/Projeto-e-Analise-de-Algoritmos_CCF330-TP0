#include "quadro.h"
#include "Obra_de_arte.h"
int main(){

    printf("\n\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|        Programacao e Analise de Algoritmos - CCF 330               |\n");
    printf("|                       Trabalho Pratico                             |\n");
    printf("|                  Gabriel Miranda - EFO3857                         |\n");
    printf("|                    Pedro Maia - EF03878                            |\n");
    printf("|--------------------------------------------------------------------|\n\n");
    int tipofigura;
    int qtdfiguras;
    Tela tela;
    criaQuadro(&tela);
    while(1){
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
        printf("\nDigite a quantidade de figura(menor ou igual a zero para aleatorio): ");
        scanf("%d", &qtdfiguras);
        qtdfiguras = geradorAleatorio(qtdfiguras, &tipofigura);
        printf("\ntipo de figura:%d, numero de figuras:%d",tipofigura, qtdfiguras);
        if(tipofigura <= 0 || tipofigura >=6){
            break;
        }
        else if(tipofigura == 1){
            tela = allocaFiguras(criaFiguraPonto(),LINHASSIMBOLOPONTO,COLUNASSIMBOLOPONTO,qtdfiguras);
            imprimeQuadro(&tela);
        }
        else if(tipofigura == 2){
            tela = allocaFiguras(criaFiguraSoma(),LINHASIMBOLOSOMA,COLUNASSIMBOLOSOMA,qtdfiguras);
            imprimeQuadro(&tela);
        }
        else if(tipofigura == 3){
            tela = allocaFiguras(criaFiguraX(),LINHASSIMBOLOX,COLUNASSIMBOLOX,qtdfiguras);
            imprimeQuadro(&tela);
        }
        else if(tipofigura == 4){
            tela = allocaFigurasAleatorias(qtdfiguras);
            imprimeQuadro(&tela);
        }
        else if(tipofigura == 5){
            obraDeArte obra;
            partesObra partes = criaPartes();
            constroiObra(&partes,&obra);
            tela = allocaFiguras(organizaObra(&obra),linhasObraFinal,colunasObraFinal,qtdfiguras);
            imprimeQuadro(&tela);
        }
    }
    return 0;
}