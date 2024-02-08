#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"
#include "pilhaEstatica.h"

void imprimeMenu()
{
    printf("Digite o numero da opcao desejada:\n");
    printf("1- Fazer pedido\n");
    printf("2- Acompanhar pedidos\n");
    printf("3- Liberar pedido\n");
}

void imprimeCardapio()
{
    int i;
    char cardapio[6][30] = {"1 - ratatouille", "2 - coq au vin", "3 - cassoulet", "4 - omelette du fromage", "5 - creme brulee", "6 - crepe suzette"};

    printf("Cardapio do dia:");
    for (i = 0; i < 6; i++)
    {
        printf("\n------------------------\n");
        printf("%s", cardapio[i]);
        printf("\n------------------------");
    }
}

void preenchePedido(struct pedido *dados, struct item *items, Pilha *pilha)
{
    int opcao = 1;
    char cardapio[6][30] = {"ratatouille", "coq au vin", "cassoulet", "omelette du fromage", "creme brulee", "crepe suzette"};

    imprimeCardapio();

    printf("\n\nDigite seu nome:\n");
    fflush(stdin);
    scanf("%s", dados->nome);

    int item, qtd, count = 0;
    do
    {
        printf("Qual item do cardapio deseja pedir: ");
        scanf("%d", &item);
        strcpy(items->nome, cardapio[item - 1]);

        printf("Quantidade de %s:\n", cardapio[item - 1]);
        scanf("%d", &qtd);
        items->qtd = qtd;

        inserirPilha(pilha, *items);

        printf("Deseja pedir mais?:\n1 - Sim\n0 - Nao\n");
        scanf("%d", &opcao);
        count++;
    } while (opcao && cheiaPilha(pilha) != 1);
    dados->qtd = count;
}

int main()
{
    Pilha *pilha;
    pilha = NULL;
    pilha = criarPilha();

    Fila *fila;
    fila = NULL;
    fila = criarFila();
    int opcao, res;
    opcao = -1;

    struct pedido dados;
    struct item items;

    while (opcao != 5)
    {
        imprimeMenu();
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            preenchePedido(&dados, &items, pilha);
            inserirFila(fila, dados, items);
            printf("\n\nObrigado por comprar na TOMPERO, seu pedido e o %d da fila\n\n", tamanhoFila(fila));
        }
        else if (opcao == 2)
        {
            printf("\n\nOs primeiros 5 pedidos:\n");
            acompanharPedidosFila(fila);
        }
        else if (opcao == 3)
        {
            res = acessarFila(fila, &dados);
            printf("\n\nPedido pronto!!!\n");
            if (res == 1)
            {
                printf("--------------------------------\n");
                printf("Nome do cliente: %s\nQuantidade: %d\n", dados.nome, dados.qtd);
                printf("--------------------------------\n");
            }
            removerFila(fila);
        }
        else if (opcao == 4)
        {
            imprimeFila(fila);
        }
        else if (opcao == 5)
        {
            destruirFila(fila);
            printf("Encerrando o programa\n");
        }
        else
        {
            printf("Opcao invalida, tente novamente\n");
        }
    }
    return 0;
}
