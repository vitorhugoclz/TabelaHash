#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"tabela_hash.h"
#include"funcoes_hashing.h"

int inserir(estudante ** inicio, estudante * e) {
    if(*inicio == NULL)
    {
        *inicio = e;
        return 1;
    }
    
    estudante * p;
    p = (*inicio);
    while(p->prox != NULL) {
        p = p->prox;
    }
    p->prox = e;
    return 1;
}

char * buscar(estudante ** inicio, int matricula) {
    if(*inicio == NULL)
        return NULL;
    estudante * p;
    p = (*inicio);
    while(p != NULL && p->matricula != matricula)
        p = p->prox;
    if(p == NULL)
        return NULL;
    return &(p->nome[0]);
}

estudante * remover(estudante ** inicio, int matricula) {
    if(*inicio == NULL)
        return NULL;
    estudante *p, *q;
    p = (*inicio);
    q = NULL;
    while(p != NULL && p->matricula != matricula)
    {
        q = p;
        p = p->prox;
    }
    if(p == NULL)
        return NULL;
    if(q == NULL)
        (*inicio) = p->prox;
    else
        q->prox = p->prox;
    return p;
}

void libera_lista(estudante ** inicio) {
    if(*inicio == NULL)
        return;
    estudante *p, *q;
    for(p = (*inicio)->prox, q = *inicio;p != NULL;q = p, p =  p->prox)
        free(q);
    free(q);
}