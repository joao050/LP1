#include<stdio.h>
#include"TAD_PRODUTOS/TAD_PRODUTOS.h"
int main()
{
    printf("Criando lista...\n");
    Lista* minha_lista = cria_list();

    printf("Inserindo itens...\n");
    for (int i = 0; i < 3; i++)
    {
        minha_lista = adiciona_iten_list(minha_lista);
    }

    printf("Minha lista\n");
    imprime_list(minha_lista);

    printf("Busca item e remove(id): ");
    int id_busca;
    scanf("%d", &id_busca);

    if (encontra_iten(minha_lista, id_busca) != NULL)
    {
        printf("Item encontrado.\n");
        minha_lista = remove_iten_list(minha_lista, id_busca);
        printf("Item removido.\n");
    }
    else
    {
        printf("Item não encontrado.\n");
    }
    
    printf("Lista atualizada\n");
    imprime_list(minha_lista);
    

    libera_list(minha_lista);

    return 0;
}