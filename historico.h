#include <stdio.h>

#ifndef HISTORICO_H
#define HISTORICO_H

#define MAX 100

typedef enum {SOBE, CORTA, VIRA, VIRATOPO} qualOP;

typedef struct{
    qualOP OPE;
    int a; // guarda os topicos especiais das funcoes
    int b;
}entrada;

typedef struct{
    entrada vethist[MAX];
    int ini;
    int tam;
}Historico;

void limpahist(Historico *H);
void empilhahist(Historico *H, entrada E);
int desempilhahist(Historico *H, entrada *E);

#endif


