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

