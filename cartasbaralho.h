#ifndef CARTASBARALHO_H
#define CARTASBARALHO_H 

typedef struct baralho Baralho;

Baralho *CriaBaralho(int Ncartas);
void destroi(Baralho *B);
int Bcartas(const Baralho *B, int a);
int Bposicao(const Baralho *B, int x);
void Corta(Baralho *B, int x);
void Vira(Baralho *B);
void sobe(Baralho *B, int x);
void ViraTopo(Baralho *B, int k);
void Mostra(Baralho *B);

#endif

