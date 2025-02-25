#include "interface.h"
#include <stdio.h>

void exibirTabuleiro(Tabuleiro *tab) {
    printf("  ");
    for (int j = 0; j < tab->colunas; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < tab->linhas; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < tab->colunas; j++) {
            if (tab->matriz[i][j] == -1)
                printf(" * ");
            else
                printf(" %d ", tab->matriz[i][j]);
        }
        printf("\n");
    }
}
