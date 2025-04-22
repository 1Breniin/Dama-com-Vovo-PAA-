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
    
    Tabuleiro tab;
    
    while (ler_entrada(fp, &tab)) {
        struct timeval start_fb, end_fb, start_opt, end_opt;
        struct rusage usage_start_fb, usage_end_fb, usage_start_opt, usage_end_opt;
    
        // Força Bruta
        gettimeofday(&start_fb, NULL);
        getrusage(RUSAGE_SELF, &usage_start_fb);
        int resultado_fb = estrategia_forca_bruta(&tab);
        gettimeofday(&end_fb, NULL);
        getrusage(RUSAGE_SELF, &usage_end_fb);
    
        // Otimizada
        gettimeofday(&start_opt, NULL);
        getrusage(RUSAGE_SELF, &usage_start_opt);
        int resultado_opt = estrategia_otimizada(&tab);
        gettimeofday(&end_opt, NULL);
        getrusage(RUSAGE_SELF, &usage_end_opt);
    
        // Impressão dos resultados no arquivo de saída
        fprintf(saida, "%d\n", resultado_fb);

        // Impressão dos tempos no terminal
        printf("---------------------------\n");
        printf("Força Bruta:\n");
        imprimir_tempos(start_fb, end_fb, usage_start_fb, usage_end_fb);
        printf("\nOtimizada:\n");
        imprimir_tempos(start_opt, end_opt, usage_start_opt, usage_end_opt);
        printf("---------------------------\n");
    
        liberar_tabuleiro(&tab);
    }
    

    // Fecha os arquivos
    fclose(saida);
    fclose(fp);

    return 0;
}