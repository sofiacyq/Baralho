#include <stdio.h>
#include <stdlib.h>

#include "cartasbaralho.h"

typedef struct{
    int *rotulo;
    int *pos; //"cadeira" em que a carta se senta na mesa
    int Ncartas;
    int topo;
    int direcao;
}Baralho;

//indice real das "cadeiras"
static int indice(int topo, int direcao, int Ncartas, int a){
    int x = topo + direcao * (a - 1);
    return (x % Ncartas + Ncartas) % Ncartas;
}

Baralho *CriaBaralho(int Ncartas){
    Baralho *B = malloc(sizeof(Baralho));

    B -> Ncartas = Ncartas;
    B -> rotulo  =  malloc( Ncartas * sizeof(int));
    B -> pos = malloc((Ncartas+1) * sizeof(int));
    B -> topo = 0;
    B -> direcao = +1;

    for(int i = 0; i < Ncartas; i++){
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
int Bcartas(const Baralho *B, int a){
    return B -> rotulo[indice(B -> topo, B -> direcao, B -> Ncartas, a)];
}

int Bposicao(const Baralho *B, int x){
    int lugar = B -> pos[x];
    int passos = ((lugar - B -> topo)* B -> direcao % B -> Ncartas + B -> Ncartas) % B -> Ncartas;
    return passos + 1;

}

void Corta(Baralho *B, int x){
    B -> topo = B -> pos[x];
}

void Vira(Baralho *B){
    int fundo = indice(B -> topo, B -> direcao, B -> Ncartas, B -> Ncartas);
    B -> topo = fundo;
    B -> direcao = -B -> direcao;
}

static  void Lugarcerto(Baralho *B, int cadeira, int carta){
    B -> rotulo[cadeira] = carta;
    B -> pos[carta] = cadeira;
}

void sobe(Baralho *B, int x){
    int c = Bposicao(B, x);
    
    for(int i = c; i >= 2; i--){
        int carta = Bcartas(B, i-1);

        Lugarcerto(B, indice(B -> topo, B -> direcao, B -> Ncartas, i), carta);
    }

    Lugarcerto(B, B -> topo, x);
}

void ViraTopo(Baralho *B, int k){
    for(int i = 1;  i <= k/2; i++){
        int j = k - i + 1;
        
        int indi = indice(B -> topo, B -> direcao, B -> Ncartas, i);
        int indj = indice(B -> topo, B -> direcao, B -> Ncartas, j);
        
        int cartasi = B -> rotulo [indi];
        int cartasj = B -> rotulo [indj];

        Lugarcerto(B, indi, cartasj);
        Lugarcerto(B, indj, cartasi);
    }
}

void Mostra(Baralho *B){
    for(int  i = 1; i <= B -> Ncartas; i++){
        printf("%d", Bcartas(B, i));
        
        if(i < B -> Ncartas){
            printf(" ");
        }
    }

    printf("\n");

}




