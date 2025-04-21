#include <stdio.h>
#include "tempo.h"

void imprimir_tempos(struct timeval start, struct timeval end, struct rusage usage_start, struct rusage usage_end) {
    double tempo_usuario = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) + (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;
    double tempo_sistema = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) + (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1e6;

    printf("Tempo de usuário: %.6fs\n", tempo_usuario);
    printf("Tempo de sistema: %.6fs\n", tempo_sistema);
}
