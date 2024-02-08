#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

struct item
{
    char nome[50];
    int qtd;
};

struct pedido
{
    char nome[50];
    struct item items[10];
    int qtd;
};

typedef struct fila Fila;

Fila *criarFila();
void destruirFila(Fila *);
int tamanhoFila(Fila *);
int cheiaFila(Fila *);
int vaziaFila(Fila *);
int inserirFila(Fila *, struct pedido, struct item);
int removerFila(Fila *);
int acessarFila(Fila *, struct pedido *);
int imprimeFila(Fila *);

#endif // FILADINAMICA_H_INCLUDED
