/*
 * Trabalho Final - Minesweeper (Campo Minado)
 * Disciplina: Programação (CK0226)
 * Universidade Federal do Ceará
 * Aluno: [Seu Nome] - Matrícula: [Sua Matrícula]
 * 
 * Descrição: Implementação do jogo Minesweeper em C, seguindo os requisitos do projeto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LINHAS 5
#define MAX_LINHAS 26
#define MIN_COLUNAS 5
#define MAX_COLUNAS 40
#define MIN_MINAS 7

typedef struct Celula {
    int mina;
    int vizinhos;
    int revelado;
    int marcado;
    struct Celula *cima, *baixo, *esquerda, *direita;
} Celula;

typedef struct Tabuleiro {
    int linhas, colunas, num_minas;
    Celula **grid;
} Tabuleiro;

void inicializarTabuleiro(Tabuleiro *tabuleiro, int linhas, int colunas, int minas);
void exibirTabuleiro(Tabuleiro *tabuleiro);
void jogar(Tabuleiro *tabuleiro);
void liberarTabuleiro(Tabuleiro *tabuleiro);
void posicionarMinas(Tabuleiro *tabuleiro);
void calcularVizinhos(Tabuleiro *tabuleiro);
int processarEntrada(char *entrada, int *linha, int *coluna);
void abrirCelula(Tabuleiro *tabuleiro, int linha, int coluna);

void inicializarTabuleiro(Tabuleiro *tabuleiro, int linhas, int colunas, int minas) {
    tabuleiro->linhas = linhas;
    tabuleiro->colunas = colunas;
    tabuleiro->num_minas = minas;
    tabuleiro->grid = (Celula **)malloc(linhas * sizeof(Celula *));
    
    for (int i = 0; i < linhas; i++) {
        tabuleiro->grid[i] = (Celula *)malloc(colunas * sizeof(Celula));
        for (int j = 0; j < colunas; j++) {
            tabuleiro->grid[i][j].mina = 0;
            tabuleiro->grid[i][j].vizinhos = 0;
            tabuleiro->grid[i][j].revelado = 0;
            tabuleiro->grid[i][j].marcado = 0;
        }
    }
    posicionarMinas(tabuleiro);
    calcularVizinhos(tabuleiro);
}

void posicionarMinas(Tabuleiro *tabuleiro) {
    int minas_colocadas = 0;
    while (minas_colocadas < tabuleiro->num_minas) {
        int linha = rand() % tabuleiro->linhas;
        int coluna = rand() % tabuleiro->colunas;
        if (tabuleiro->grid[linha][coluna].mina == 0) {
            tabuleiro->grid[linha][coluna].mina = 1;
            minas_colocadas++;
        }
    }
}

void calcularVizinhos(Tabuleiro *tabuleiro) {
    for (int i = 0; i < tabuleiro->linhas; i++) {
        for (int j = 0; j < tabuleiro->colunas; j++) {
            if (tabuleiro->grid[i][j].mina) continue;
            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < tabuleiro->linhas && nj >= 0 && nj < tabuleiro->colunas)
                        count += tabuleiro->grid[ni][nj].mina;
                }
            }
            tabuleiro->grid[i][j].vizinhos = count;
        }
    }
}

void exibirTabuleiro(Tabuleiro *tabuleiro) {
    printf("  ");
    for (int j = 0; j < tabuleiro->colunas; j++) printf("%2d", j + 1);
    printf("\n");
    
    for (int i = 0; i < tabuleiro->linhas; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < tabuleiro->colunas; j++) {
            if (tabuleiro->grid[i][j].revelado) {
                if (tabuleiro->grid[i][j].mina) printf(" *");
                else printf(" %d", tabuleiro->grid[i][j].vizinhos);
            } else if (tabuleiro->grid[i][j].marcado) {
                printf(" #");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

void liberarTabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < tabuleiro->linhas; i++) free(tabuleiro->grid[i]);
    free(tabuleiro->grid);
}

int main() {
    int linhas, colunas, minas;
    Tabuleiro tabuleiro;
    
    srand(time(NULL));
    printf("Bem-vindo ao Minesweeper!\n");
    printf("Informe o número de linhas (5-26): ");
    scanf("%d", &linhas);
    printf("Informe o número de colunas (5-40): ");
    scanf("%d", &colunas);
    printf("Informe a quantidade de minas: ");
    scanf("%d", &minas);
    
    inicializarTabuleiro(&tabuleiro, linhas, colunas, minas);
    exibirTabuleiro(&tabuleiro);
    liberarTabuleiro(&tabuleiro);
    
    return 0;
}
/*
 * Trabalho Final - Minesweeper (Campo Minado)
 * Disciplina: Programação (CK0226)
 * Universidade Federal do Ceará
 * Aluno: [Seu Nome] - Matrícula: [Sua Matrícula]
 * 
 * Descrição: Implementação do jogo Minesweeper em C, modularizado para melhor organização.
 */

#include "tabuleiro.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int linhas, colunas, minas;
    Tabuleiro tabuleiro;
    
    srand(time(NULL));
    printf("Bem-vindo ao Minesweeper!\n");
    printf("Informe o número de linhas (5-26): ");
    scanf("%d", &linhas);
    printf("Informe o número de colunas (5-40): ");
    scanf("%d", &colunas);
    printf("Informe a quantidade de minas: ");
    scanf("%d", &minas);
    
    inicializarTabuleiro(&tabuleiro, linhas, colunas, minas);
    exibirTabuleiro(&tabuleiro);
    liberarTabuleiro(&tabuleiro);
    
    return 0;
}