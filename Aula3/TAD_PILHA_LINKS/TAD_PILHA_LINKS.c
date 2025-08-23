#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_PILHA_LINKS.h"

// Cria uma pilha vazia
Pilha *cria_pilha(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (!p)
    {
        printf("Não foi possivel criar pilha...\n");
        exit(1);
    }

    p->prim = NULL;

    return p;
}

// Adiciona um elemento na pilha
void push_pilha(Pilha *p, char *link_push)
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->link = (char *)malloc(sizeof(strlen(link_push) + 1));
    strcpy(l->link, link_push);

    l->prox = p->prim;

    p->prim = l;
}

// Retira um elemento da pilha
// link pop vai receber o link que foi apagado
void pop_pilha(Pilha *p, char *link_pop)
{
    if (!pilha_vazia(p))
    {
        Lista *l = p->prim;
        strcpy(link_pop, l->link);
        free(l->link);
        p->prim = l->prox;
        free(l);
    }
    else
    {
        printf("A pilha ja esta vazia..\n");
    }
}

// Verifica se a pilha está vazia
int pilha_vazia(Pilha *p)
{
    return p->prim == NULL;
}

// Imprime minha pilha
void imprime_pilha(Pilha *p)
{
    Lista *lis = p->prim;
    while (lis != NULL)
    {
        printf("Link: %s\n", lis->link);
        lis = lis->prox;
    }
}

// Libera a memória da pilha
void libera_pilha(Pilha *p)
{
    Lista *list = p->prim;
    Lista *aux;
    while (list != NULL)
    {
        aux = list->prox;
        free(list);
        list = aux;
    }
}