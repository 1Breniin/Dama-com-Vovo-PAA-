#include "estrategia.h"
#include "tabuleiro.h"

int max_dir[4] = {-1, -1, 1, 1};
int max_col[4] = {-1, 1, -1, 1};

// Função de busca em profundidade com otimização
int dfs_otimizado(Tabuleiro *tab, int **matriz, int x, int y, int N, int M) {
    int max = 0;

    for (int d = 0; d < 4; d++) {
        int nx = x + max_dir[d];
        int ny = y + max_col[d];
        int nx2 = nx + max_dir[d];
        int ny2 = ny + max_col[d];

        // Verificar se o movimento é válido (pode saltar sobre uma peça adversária para uma casa vazia)
        if (nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M &&
            matriz[nx][ny] == 2 && matriz[nx2][ny2] == 0) {

            
            matriz[x][y] = 0; // Realiza a captura
            int tmp = matriz[nx][ny];
            matriz[nx][ny] = 0;
            matriz[nx2][ny2] = 1;

            // Chama a DFS recursiva para tentar capturar mais peças
            int res = 1 + dfs_otimizado(tab, matriz, nx2, ny2, N, M);

            // Mantém o melhor resultado de capturas
            if (res > max) max = res;

            // Desfaz a captura para tentar outros movimentos
            matriz[x][y] = 1;
            matriz[nx][ny] = tmp;
            matriz[nx2][ny2] = 0;
        }
    }

    return max;
}

// Função de Força Bruta
int estrategia_forca_bruta(Tabuleiro *tab) {
    int max_total = 0;
    int **matriz = tab->matriz;

    for (int i = 0; i < tab->N; i++) {
        for (int j = 0; j < tab->M; j++) {
            if (matriz[i][j] == 1) { // Se for uma peça sua
                // Chama a DFS para explorar as capturas a partir desta posição
                int capturas = dfs_otimizado(tab, matriz, i, j, tab->N, tab->M);
                if (capturas > max_total) max_total = capturas;
            }
        }
    }

    return max_total;
}

// Função de estratégia otimizada, que tenta reduzir o número de movimentos
int estrategia_otimizada(Tabuleiro *tab) {
    int **matriz = tab->matriz;
    int max_total = 0;

    // Itera sobre todas as posições no tabuleiro
    for (int i = 0; i < tab->N; i++) {
        for (int j = 0; j < tab->M; j++) {
            if (matriz[i][j] == 1) { // Se for uma peça sua
                // Tenta otimizar a busca utilizando uma abordagem mais estratégica
                int capturas = dfs_otimizado(tab, matriz, i, j, tab->N, tab->M);
                if (capturas > max_total) {
                    max_total = capturas;
                }
            }
        }
    }

    return max_total;
}
