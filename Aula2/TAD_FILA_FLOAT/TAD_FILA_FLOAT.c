#include <stdio.h>
#include <stdlib.h>
#include "TAD_FILA_FLOAT.h"

// Cria uma fila vazia
Fila *cria_fila(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    f->fim = f->ini = NULL;

    return f;
}

// Insere um elemento no final da fila
void insere_fila(Fila *f, float v)
{
    Lista *l = (Lista *)malloc(sizeof(Fila));
    if (!l)
    {
        printf("Não tem memoria para a lista!\n");
        exit(1);
    }
    l->info = v;
    l->prox = NULL;

    if (f->fim != NULL)
    {
        f->fim->prox = l;
    }
    else
    {
        f->ini = l;
    }

    f->fim = l;
}

// Imprime a fila
void imprime_fila(Fila *f)
{
    Lista *p = f->ini;
    int cont = 1;
    while (p != NULL)
    {
        printf("Posicao %d->> %.2f\n", cont, p->info);
        cont++;
        p = p->prox;
    }
}

// Veerifica se a fila está vazia
int vazia_fila(Fila *f)
{
    return f->ini == NULL && f->fim == NULL;
}

// Retira o elemento que está no início da fila
float retira_fila(Fila *f)
{
    // Verifica se tem elementos na fila
    if (vazia_fila(f))
    {
        printf("A fila ja esta vazia...");
        exit(1);
    }

    // auxiliar pera receber o primeiro elmento a ser retirado
    Lista *prim_elemento = f->ini;
    float v_elemento = prim_elemento->info;

    f->ini = f->ini->prox;
    free(prim_elemento);

    // Se o elmento a ser retirado for o último
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }

    return v_elemento;
}

// Libera toda a fila
void libera_fila(Fila *f)
{
    Lista *p = f->ini;
    while (p != NULL)
    {
        Lista *aux = p->prox;
        free(p);
        p = aux->prox;
    }

    free(f);
}