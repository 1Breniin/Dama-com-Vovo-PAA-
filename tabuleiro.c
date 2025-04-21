#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

int ler_entrada(FILE *fp, Tabuleiro *tab) {
    int casas, valor;
    
    if (fscanf(fp, "%d %d", &tab->N, &tab->M) != 2 || (tab->N == 0 && tab->M == 0)) // Lê as dimensões do tabuleiro (N x M) e verifica se são válidas
        return 0; // Se não conseguir ler as dimensões, retorna 0 (erro)

    casas = (tab->N * tab->M) / 2;
    tab->matriz = malloc(tab->N * sizeof(int *)); // Aloca memória para a matriz que representa o tabuleiro
    for (int i = 0; i < tab->N; i++) {
        tab->matriz[i] = calloc(tab->M, sizeof(int)); // Inicializa as casas com 0
    }

    for (int i = 0, k = 0; i < tab->N; i++) {
        for (int j = 0; j < tab->M; j++) {
            if ((i + j) % 2 == 0) {
                fscanf(fp, "%d", &valor);
                tab->matriz[i][j] = valor;
                k++;
            }
        }
    }
    return 1; //Leitura bem sucedida
}

void liberar_tabuleiro(Tabuleiro *tab) {
    for (int i = 0; i < tab->N; i++) { // Libera a memória alocada para o tabuleiro
        free(tab->matriz[i]);
    }
    free(tab->matriz);
}
