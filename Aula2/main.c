#include<stdio.h>
#include<stdlib.h>
#include"TAD_FILA_FLOAT/TAD_FILA_FLOAT.h"

int main()
{
    Fila* minha_fila = cria_fila();

    for (int i = 0; i < 3; i++)
    {
        insere_fila(minha_fila, i+3);
    }

    printf("->>Minha fila<<-\n");
    imprime_fila(minha_fila);
    
    printf("Remove elementos\n");
    printf("Valor %.2f foi retirado da lista\n", retira_fila(minha_fila));

    imprime_fila(minha_fila);
    
    libera_fila(minha_fila);
    
    return 0;
}