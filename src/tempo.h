#ifndef TEMPO_H
#define TEMPO_H

#include <sys/time.h>
#include <sys/resource.h>

void imprimir_tempos(struct timeval start, struct timeval end, struct rusage usage_start, struct rusage usage_end);

#endif