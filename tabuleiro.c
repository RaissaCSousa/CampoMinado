#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarTabuleiro(Tabuleiro *tab, int linhas, int colunas, int minas) {
    tab->linhas = linhas;
    tab->colunas = colunas;

    // Alocar matriz dinamicamente
    tab->matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        tab->matriz[i] = (int *)malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++) {
            tab->matriz[i][j] = 0;
        }
    }

    posicionarMinas(tab, minas);
    calcularVizinhos(tab);
}

void posicionarMinas(Tabuleiro *tab, int minas) {
    int colocadas = 0;
    while (colocadas < minas) {
        int linha = rand() % tab->linhas;
        int coluna = rand() % tab->colunas;

        if (tab->matriz[linha][coluna] == 0) {
            tab->matriz[linha][coluna] = -1; // Mina representada por -1
            colocadas++;
        }
    }
}

void calcularVizinhos(Tabuleiro *tab) {
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas; j++) {
            if (tab->matriz[i][j] == -1) continue;

            int contagem = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < tab->linhas && nj >= 0 && nj < tab->colunas &&
                        tab->matriz[ni][nj] == -1) {
                        contagem++;
                    }
                }
            }
            tab->matriz[i][j] = contagem;
        }
    }
}

void liberarTabuleiro(Tabuleiro *tab) {
    for (int i = 0; i < tab->linhas; i++) {
        free(tab->matriz[i]);
    }
    free(tab->matriz);
}
