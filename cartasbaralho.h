#include <stdio.h>

#ifndef CARTASBARALHO_H
#define CARTASBARALHO_H 

typedef struct{
    int *rotulo;
    int *pos; //"cadeira" em que a carta se senta na mesa
    int Ncartas;
    int topo;
    int direcao;
}Baralho;

Baralho *CriaBaralho(int Ncartas);
void detroi(Baralho *B);
int Bcartas(const Baralho *B, int a);
int Bposicao(const Baralho *B, int x);
void Corta(Baralho *B, int x);
void Vira(Baralho *B);
void sobe(Baralho *B, int x);
void ViraTopo(Baralho *B, int k);
void Mostra(const Baralho *B);

#endif

