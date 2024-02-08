#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#include "filaDinamica.h"



typedef struct pilha Pilha;

// retorna ponteiro para a Pilha ou NULL se alocacao nao for bem sucedida
Pilha *criarPilha();
void destruirPilha(Pilha *);
int tamanhoPilha(Pilha *);
int cheiaPilha(Pilha *);
int vaziaPilha(Pilha *);
int inserirPilha(Pilha *, struct item);
int removerPilha(Pilha *);
int acessarPilha(Pilha *, struct item *);
int imprimePilha(Pilha *);

#endif // PILHAESTATICA_H_INCLUDED
