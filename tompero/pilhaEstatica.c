#include <stdlib.h>
#include <stdio.h>
#include "filaDinamica.h"
#include "pilhaEstatica.h"

struct pilha{
    int qtd;
    struct item dados[10];
};

Pilha* criarPilha(){
    Pilha *pe;
    pe = (Pilha*) malloc(sizeof(Pilha));
    if(pe != NULL){
        pe->qtd = 0;
    }
    return pe;
}

void destruirPilha(Pilha *pe){
    free(pe);
}

int tamanhoPilha(Pilha *pe){
    if(pe == NULL){
        return -1;
    }
    return pe->qtd;
}

int cheiaPilha(Pilha *pe){
    if(pe == NULL){
        return -1;
    }else if(pe->qtd == 10){
        return 1;
    }else{
        return 0;
    }
}

int vaziaPilha(Pilha *pe){
    if(pe == NULL){
        return -1;
    }else if(pe->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserirPilha(Pilha *pe, struct item novo){
    if(pe == NULL){
        return 0;
    }else if(cheiaPilha(pe)){
        return 0;
    }else{
        pe->dados[pe->qtd] = novo;
        pe->qtd++;
        return 1;
    }
}

int removerPilha(Pilha *pe){
    if(pe == NULL){
        return 0;
    }else if(vaziaPilha(pe)){
        return 0;
    }else{
        pe->qtd--;
        return 1;
    }
}

int acessarPilha(Pilha *pe, struct item *a){
    if(pe == NULL){
        return 0;
    }else if(vaziaPilha(pe)){
        return 0;
    }else{
        *a = pe->dados[pe->qtd-1];
        return 1;
    }
}

int imprimePilha(Pilha *pe){
    if(pe == NULL){
        return 0;
    }else{
        for(int i = (pe->qtd - 1); i >= 0; i--){
            printf("--------------------------------\n");
            printf("Nome: %s\nQuantidade: %d\n", pe->dados[i].nome, pe->dados[i].qtd);
            printf("--------------------------------\n");
        }
        return 1;
    }
}
