#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

typedef struct {
    int **matriz;
    int N, M;
} Tabuleiro;

int ler_entrada(FILE *fp, Tabuleiro *tab);
void liberar_tabuleiro(Tabuleiro *tab);

#endif