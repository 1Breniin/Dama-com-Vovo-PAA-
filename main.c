#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "tabuleiro.h"
#include "estrategia.h"
#include "tempo.h"

int main(int argc, char *argv[]) {
    
    if (argc != 3 || strcmp(argv[1], "-i") != 0) { // Verifica se a linha de comando está correta
        fprintf(stderr, "Erro no uso: ./tp1 -i entrada.txt\n");
        return 1;
    }

    
    FILE *fp = fopen(argv[2], "r"); // Tenta abrir o arquivo de entrada
    if (!fp) {
        perror("Falha ao abrir o arquivo");
        return 1;
    }

    FILE *saida = fopen("saida.txt", "w");
    if (saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(fp);
        return 1;
    }
    
    freopen("saida.txt", "w", stdout);  

    Tabuleiro tab;
    
  
    while (ler_entrada(fp, &tab)) { // Lê a entrada e processa cada caso de teste
        struct timeval start, end;
        struct rusage usage_start, usage_end;

        gettimeofday(&start, NULL);
        getrusage(RUSAGE_SELF, &usage_start);

        int resultado1 = estrategia_forca_bruta(&tab);
        int resultado2 = estrategia_otimizada(&tab);

        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &usage_end);

        printf("%d\n", resultado1 > resultado2 ? resultado1 : resultado2);
        imprimir_tempos(start, end, usage_start, usage_end);

        liberar_tabuleiro(&tab);
    }

    // Fecha os arquivos
    fclose(saida);
    fclose(fp);

    return 0;
}
