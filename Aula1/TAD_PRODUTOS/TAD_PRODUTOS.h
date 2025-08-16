#ifndef _TAD_PRODUTOS_
#define _TAD_PRODUTOS_

struct produtos
{
    int id;
    char descricao[81];
    float estoque;
    float preco;
    struct produtos *prox;
};

typedef struct produtos Lista;

Lista* cria_list(void);
Lista* novo_iten_list(void);
Lista* adiciona_iten_list(Lista* cabeca_da_lista);
Lista* remove_iten_list(Lista* cabeca_da_lista, int id_produto);
Lista* encontra_iten(Lista* cabeca_da_lista, int id_produto);
void imprime_list(Lista *cabec_da_lista);
void libera_list(Lista* cabeca_da_lista);


#include "TAD_PRODUTOS.c"
#endif
