#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main(){
    int escolha;
    int valor;
    Pilha Pilha;
    Fila Fila;
    ArvoreNo* arvore = NULL;

    do{
        printf("Escolha uma opcao:\n");
        printf("1. Executar Pilha\n");
        printf("2. Executar Fila\n");
        printf("3. Executar Arvore\n");
        printf("0. Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                //Menu da Pilha
                Pilha.cabeca = NULL;
                do{
                    printf("\nEscolha uma opcao:\n");
                    printf("1. Empilhar\n");
                    printf("2. Desempilhar\n");
                    printf("3. Imprimir Pilha\n");
                    printf("4. Limpar Pilha\n");
                    printf("5. Imprimir cabecao da Pilha\n");
                    printf("0. Voltar\n");
                    scanf("%d", &escolha);

                    switch(escolha){
                        case 1:
                            printf("Digite o valor a ser empilhado: ");
                            scanf("%d", &valor);
                            push(&Pilha, valor);
                            break;
                        case 2:
                            valor = pop(&Pilha);
                            if (valor != 1)
                                printf("Valor desempilhado: %d\n", valor);
                            break;
                        case 3:
                            printf("Pilha: ");
                            imprimirPilha(&Pilha);
                            printf("\n");
                            break;
                        case 4:
                            limparPilha(&Pilha);
                            printf("Pilha limpa.\n");
                            break;
                        case 5:
                            imprimirCabeca(&Pilha);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }while(escolha != 0);
                break;
            case 2:
                //Menu da Fila
                Fila.frente = NULL;
                Fila.tras = NULL;
                do{
                    printf("\nEscolha uma opcao:\n");
                    printf("1. Inserir na Fila\n");
                    printf("2. Remover da Fila\n");
                    printf("3. Imprimir Fila\n");
                    printf("4. Limpar Fila\n");
                    printf("5. Maior elemento da Fila\n");
                    printf("6. Menor elemento da Fila\n");
                    printf("0. Voltar\n");
                    scanf("%d", &escolha);

                    switch(escolha){
                        case 1:
                            printf("Digite o valor a ser inserido na fila: ");
                            scanf("%d", &valor);
                            enFila(&Fila, valor);
                            break;
                        case 2:
                            valor = deFila(&Fila);
                            if (valor != 1)
                                printf("Valor removido da fila: %d\n", valor);
                            break;
                        case 3:
                            printf("Fila: ");
                            imprimirFila(&Fila);
                            printf("\n");
                            break;
                        case 4:
                            limparFila(&Fila);
                            printf("Fila limpa.\n");
                            break;
                        case 5:
                            valor = encontrarMaior(&Fila);
                            if (valor != 1)
                                printf("Maior elemento da fila: %d\n", valor);
                            break;
                        case 6:
                            valor = encontrarMenor(&Fila);
                            if (valor != 1)
                                printf("Menor elemento da fila: %d\n", valor);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }while (escolha != 0);
                break;
            case 3:
                //Menu da Árvore
                arvore = NULL;
                do{
                    printf("\nEscolha uma opcao:\n");
                    printf("1. Inserir elemento\n");
                    printf("2. Imprimir em ordem\n");
                    printf("3. Buscar elemento\n");
                    printf("4. Imprimir a direita, raiz, esquerda\n");
                    printf("5. Maior elemento\n");
                    printf("0. Voltar\n");
                    scanf("%d", &escolha);

                    switch(escolha){
                        case 1:
                            printf("Digite o valor a ser inserido na arvore: ");
                            scanf("%d", &valor);
                            arvore = inserir(arvore, valor);
                            break;
                        case 2:
                            printf("Arvore em ordem:\n");
                            imprimirEmOrdem(arvore);
                            printf("\n");
                            break;
                        case 3:
                            printf("Digite o valor a ser buscado: ");
                            scanf("%d", &valor);
                            ArvoreNo* No = busca(arvore, valor);
                            if (No != NULL)
                                printf("Elemento encontrado na arvore.\n");
                            else
                                printf("Elemento nao encontrado na arvore.\n");
                            break;
                        case 4:
                            printf("Arvore a direita, raiz, esquerda:\n");
                            imprimirDireitaEsquerda(arvore);
                            printf("\n");
                            break;
                        case 5:
                            valor = maiorElemento(arvore);
                            if (valor != 1)
                                printf("Maior elemento da arvore: %d\n", valor);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }while (escolha != 0);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (escolha != 0);

    return 0;
}