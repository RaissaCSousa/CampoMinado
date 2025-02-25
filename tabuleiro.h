#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct {
    int linhas;
    int colunas;
    int **matriz;
} Tabuleiro;

void inicializarTabuleiro(Tabuleiro *tab, int linhas, int colunas, int minas);
void posicionarMinas(Tabuleiro *tab, int minas);
void calcularVizinhos(Tabuleiro *tab);
void liberarTabuleiro(Tabuleiro *tab);

#endif // TABULEIRO_H
#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct {
    int linhas;
    int colunas;
    int **matriz;
} Tabuleiro;

void inicializarTabuleiro(Tabuleiro *tab, int linhas, int colunas, int minas);
void posicionarMinas(Tabuleiro *tab, int minas);
void calcularVizinhos(Tabuleiro *tab);
void liberarTabuleiro(Tabuleiro *tab);

#endif // TABULEIRO_H
