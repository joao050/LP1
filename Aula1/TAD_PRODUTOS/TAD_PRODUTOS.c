#include<stdio.h>
#include<stdlib.h>
#include"TAD_PRODUTOS.h"

Lista* cria_list(void)
{
    return NULL;
}
Lista* novo_iten_list(void)
{
    Lista* novo_iten = (Lista*)malloc(sizeof(Lista));
    if (!novo_iten)
    {
        printf("Não tem memória para criar novo iten.");
        exit(1);
    }

    novo_iten->prox = NULL;
    printf("___Atributos do iten___\n");
    printf("Id: ");
    scanf("%d%*c", &novo_iten->id);
    printf("Estoque: ");
    scanf("%f%*c", &novo_iten->estoque);
    printf("Preco: ");
    scanf("%f%*c", &novo_iten->preco);
    printf("Descrição: ");
    scanf("%80[^\n]%*c", novo_iten->descricao);

    return novo_iten; 
}
Lista* adiciona_iten_list(Lista* cabeca_da_lista)
{
    Lista* novo_cabeca = novo_iten_list();
    novo_cabeca->prox  = cabeca_da_lista;

    return novo_cabeca;
    
}
Lista* remove_iten_list(Lista* cabeca_da_lista, int id_produto)
{
    Lista* ant = NULL;
    Lista* p = cabeca_da_lista;

    while (p != NULL && p->id != id_produto)
    {
        ant = p;
        p = p->prox;
    }

    if (p != NULL)
    {
        if (ant == NULL)
        {
            cabeca_da_lista = p->prox;
            free(p);
        }
        else
        {
            ant->prox = p->prox;
            free(p);
        } 
    }

    return cabeca_da_lista;

}
Lista* encontra_iten(Lista* cabeca_da_lista, int id_produto)
{
   Lista* p;

   for ( p = cabeca_da_lista; p != NULL && p->id != id_produto; p=p->prox);

   return p; // se p == null então não encontrou
   
}

void imprime_list(Lista *cabec_da_lista)
{
    Lista* p;
    for ( p = cabec_da_lista; p != NULL; p = p->prox)
    {
        printf("Descricao: %s\n", p->descricao);
        printf("ID: %d\n", p->id);
        printf("Estoque: %.2f\n", p->estoque);
        printf("Preco: %.2f\n", p->preco);
    }
}

void libera_list(Lista* cabeca_da_lista)
{
    Lista* p = cabeca_da_lista;
    Lista* aux;
    while (p != NULL)
    {
        aux = p;
        p = p->prox;
        free(aux);
    }
    

    
}