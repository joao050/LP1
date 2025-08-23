#ifndef _TAD_PILHA_LINKS_
#define _TAD_PILHA_LINKS_

typedef struct lista
{
    char* link;
    struct lista *prox;
} Lista;

typedef struct pilha
{
    Lista *prim;
} Pilha;

Pilha *cria_pilha(void);
void push_pilha(Pilha *p, char *link_push);
void pop_pilha(Pilha *p, char *link_pop);
void imprime_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
void libera_pilha(Pilha *p);

#include "TAD_PILHA_LINKS.c"
#endif