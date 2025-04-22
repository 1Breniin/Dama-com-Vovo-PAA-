#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <stdio.h>

// Estrutura para armazenar o tabuleiro
typedef struct {
    int N;         // Número de linhas do tabuleiro
    int M;         // Número de colunas do tabuleiro
    int **matriz;  // Matriz que representa o tabuleiro
} Tabuleiro;

int ler_entrada(FILE *fp, Tabuleiro *tab);

Tabuleiro copiar_tabuleiro(Tabuleiro *orig);

void liberar_tabuleiro(Tabuleiro *tab);


#endif