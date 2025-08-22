#ifndef _TAD_FILA_FLOAT_
#define _TAD_FILA_FLOAT_

typedef struct lista
{
    float info;
    struct lista *prox;
} Lista;

typedef struct fila
{
    Lista* ini;
    Lista* fim;
} Fila;

Fila* cria_fila(void);
void insere_fila(Fila* f, float v);
void imprime_fila(Fila* f);
int vazia_fila(Fila* f);
float retira_fila(Fila* f);
void libera_fila(Fila* f);




#include"TAD_FILA_FLOAT.c"
#endif