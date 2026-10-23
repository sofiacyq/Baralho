#include <stdio.h>
#include <stdlib.h>

#include "cartasbaralho.h"

//indice real das "cadeiras"
static int indice(int topo, int direcao, int Ncartas, int a){
    int x = topo + direcao * (p - 1);
    return (x % Ncartas + Ncartas) % Ncartas;
}

Baralho *Cria_Baralho(int Ncartas){
    Baralho *B = malloc(sizeof(Baralho));

    B -> Ncartas = Ncartas;
    B -> rotulo  =  malloc( n * sizeof(int));
    B -> pos = malloc((n+1)sizeof(int));
    B -> topo = 0;
    B -> direcao = +1;

    for(int i = 0; i < n; i++){
        B -> rotulo[i] = i + 1;
        B -> pos[i+ 1] = i;
    }
    
    return B;
}

void destroi(Baralho *B){
    if(B == NULL){
        return;
    }
    free(B -> rotulo);
    free(B -> pos);
    free(B);
}

//baralho com os lugares onde as cartas de sentam
int Baralho_cartas(Baralho *B, int a){
    return b -> rotulo[indice(B -> topo, B -> direcao, B -> Ncartas, a)];
}

int Baralho_posicao(Const Baralho *B, int x){
    int lugar = b -> pos[x];
    int passos = ((lugar - B -> topo)* B -> direcao % B -> Ncartas + B -> Ncartas) % B -> Ncartas;
    return passos + 1;

}

void Corta(Baralho *B, int x){
    b -> topo = B -> pos[x];
}

void Vira(Baralho *B){
    int fundo = indice(B -> topo, B -> direcao. B -> Ncartas, B -> Ncartas);
    B -> topo = fundo;
    B -> direcao = -B -> direcao;
}

static  void Lugarcerto(Baralho *B, int cadeira, int carta){
    B -> rotulo[cadeira] = carta;
    B -> pos[cartas] = cadeira;
}




