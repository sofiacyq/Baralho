#include <stdio.h>

#ifndef CARTASBARALHO_H
#define CARTASBARALHO_H 

typedef struct Baralho Baralho;

Baralho *CriaBaralho(int Ncartas);
void Destroi(Baralho *B);
int Bcartas(const Baralho *B, int p);
int Bposicao(const Baralho *B, int x);

void Corta_Real(Baralho *B, int x);
void Vira_Real(Baralho *B);
void Sobe_Real(Baralho *B, int x);
void ViraTopo_Real(Baralho *B, int k);
void Mostra(const Baralho *B);
void Desfaz(Baralho *B);

#endif

