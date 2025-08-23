#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_PILHA_LINKS/TAD_PILHA_LINKS.h"

int main()
{
    char link[81];
    Pilha *UNDO = cria_pilha();
    Pilha *REDO = cria_pilha();

    printf("$$$ BROWSER $$$\n");

    for (int i = 1; i <= 3; i++)
    {
        printf("Digite o link %d para navegar: ", i);
        scanf("%80[^\n]%*c", link);

        push_pilha(UNDO, link);
    }

    printf("-- Imprimindo a Pilha UNDO --\n");

    imprime_pilha(UNDO);

    printf("Desfazendo...\n");

    pop_pilha(UNDO, link);
    push_pilha(REDO, link);

    printf("\n-- Imprimindo a Pilha UNDO --\n");

    imprime_pilha(UNDO);

    printf("\n-- Imprimindo a Pilha REDO --\n");

    imprime_pilha(REDO);

    printf("Liberando as pilhas...\n");

    libera_pilha(UNDO);

    libera_pilha(REDO);

    return 0;
}