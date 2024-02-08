#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

struct elemento
{
    struct pedido dados;
    struct item items[10];
    struct elemento *proximo;
};

typedef struct elemento Elemento;

struct fila
{
    Elemento *inicio;
    Elemento *fim;
};

Fila *criarFila()
{
    Fila *fd;
    fd = (Fila *)malloc(sizeof(Fila));
    if (fd != NULL)
    {
        fd->inicio = NULL;
        fd->fim = NULL;
    }
    return fd;
}

int vaziaFila(Fila *fd)
{
    if (fd == NULL)
    {
        return -1;
    }
    else if (fd->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheiaFila(Fila *fd)
{
    return 0;
}

int tamanhoFila(Fila *fd)
{
    if (vaziaFila(fd))
    {
        return 0;
    }
    int cont = 0;
    Elemento *aux = fd->inicio;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

void destruirFila(Fila *fd)
{
    if (fd != NULL)
    {
        Elemento *aux;
        while (fd->inicio != NULL)
        {
            aux = fd->inicio;
            fd->inicio = fd->inicio->proximo;
            free(aux);
        }
        fd->fim = NULL;
        free(fd);
    }
}

int inserirFila(Fila *fd, struct pedido dados, struct item items)
{
    if (fd == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
        {
            return 0;
        }
        else
        {
            int i;
            novo->dados = dados;
            for (i = 0; i < dados.qtd; i++)
            {
                novo->items[i] = items;
            }
            novo->proximo = NULL;
            if (fd->fim == NULL)
            {
                fd->inicio = novo;
            }
            else
            {
                fd->fim->proximo = novo;
            }
            fd->fim = novo;
            return 1;
        }
    }
}

int removerFila(Fila *fd)
{
    if (fd == NULL)
    {
        return 0;
    }
    else if (vaziaFila(fd))
    {
        return 0;
    }
    else
    {
        Elemento *aux = fd->inicio;
        fd->inicio = fd->inicio->proximo;
        if (fd->inicio == NULL)
        {
            fd->fim = NULL;
        }
        free(aux);
        return 1;
    }
}

int acessarFila(Fila *fd, struct pedido *a)
{
    if (fd == NULL)
    {
        return 0;
    }
    else if (vaziaFila(fd))
    {
        return 0;
    }
    else
    {
        *a = fd->inicio->dados;
        return 1;
    }
}

int acompanharPedidosFila(Fila *fd)
{
    if (fd == NULL)
    {
        return 0;
    }
    else
    {
        int count = 0;
        Elemento *aux = fd->inicio;
        int i;

        while (aux != NULL && count < 5)
        {
            printf("--------------------------------\n");
            printf("Nome do cliente: %s\n", aux->dados.nome);
            printf("Pedidos:\n");
            for (i = 0; i < aux->dados.qtd; i++)
            {
                printf("Item: %s\nQuantidade: %d\n", aux->items[i].nome, aux->items[i].qtd);
                printf("--------------------------------\n");
            }
            aux = aux->proximo;
            count++;
        }
        return 1;
    }
}

int imprimeFila(Fila *fd)
{
    if (fd == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *aux = fd->inicio;
        int i;
        while (aux != NULL)
        {
            printf("--------------------------------\n");
            printf("Nome do cliente: %s\n", aux->dados.nome);
            printf("--------------------------------\n");
            for (i = 0; i < aux->dados.qtd; i++)
            {
                printf("Item: %s\nQuantidade: %d\n", aux->items[i].nome, aux->items[i].qtd);
                printf("--------------------------------\n");
            }
            aux = aux->proximo;
        }
        return 1;
    }
}
