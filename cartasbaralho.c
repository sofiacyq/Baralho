#include <stdio.h>
#include <stdlib.h>

#include "cartasbaralho.h"
#include "historico.h"

typedef struct{
    int *rotulo;
    int *pos; //"cadeira" em que a carta se senta na mesa
    int Ncartas;
    int topo;
    int direcao;
    Historico hist;
}Baralho;

//indice real das "cadeiras"
static int indice(int topo, int direcao, int Ncartas, int p){
    int x = topo + direcao * (p - 1);
    return (x % Ncartas + Ncartas) % Ncartas;
}

Baralho *CriaBaralho(int Ncartas){
    Baralho *B = malloc(sizeof(Baralho));

    B -> Ncartas = Ncartas;
    B -> rotulo  =  malloc(Ncartas * sizeof(int));
    B -> pos = malloc((Ncartas+1)*sizeof(int));
    B -> topo = 0;
    B -> direcao = +1;

    for(int i = 0; i < Ncartas; i++){
        B -> rotulo[i] = i + 1;
        B -> pos[i+ 1] = i;
    }

    limpahist(&B -> hist);    
    return B;
}

void Destroi(Baralho *B){
    if(B == NULL){
        return;
    }
    free(B -> rotulo);
    free(B -> pos);
    free(B);
}

//baralho com os lugares onde as cartas de sentam
int Bcartas(const Baralho *B, int p){
    return B -> rotulo[indice(B -> topo, B -> direcao, B -> Ncartas, p)];
}

int Bposicao(const Baralho *B, int x){
    int lugar = B -> pos[x];
    int passos = ((lugar - B -> topo)* B -> direcao % B -> Ncartas + B -> Ncartas) % B -> Ncartas;
    return passos + 1;

}

static void Corta(Baralho *B, int x){
    B -> topo = B -> pos[x];
}

void Corta_Real(Baralho *B, int x){
    entrada E;
    E.OPE = CORTA;
    E.a = B -> topo;

    empilhahist(&B -> hist, E);
    Corta(B, x);
}

static void Vira(Baralho *B){
    int fundo = indice(B -> topo, B -> direcao, B -> Ncartas, B -> Ncartas);
    B -> topo = fundo;
    B -> direcao = -B -> direcao;
}

void Vira_Real(Baralho *B){
    entrada E;
    E.OPE = VIRA;

    empilhahist(&B -> hist, E);
    Vira(B);
}

static  void Lugarcerto(Baralho *B, int cadeira, int carta){
    B -> rotulo[cadeira] = carta;
    B -> pos[carta] = cadeira;
}

 static void Sobe(Baralho *B, int x){
    int c = Bposicao(B, x);
    
    for(int i = c; i >= 2; i--){
        int carta = Bcartas(B, i-1);

        Lugarcerto(B, indice(B -> topo, B -> direcao, B -> Ncartas, i), carta);
    }

    Lugarcerto(B, B -> topo, x);
}

void Sobe_Real(Baralho *B, int x){
    entrada E;
    E.OPE = SOBE;
    E.a = x;
    E.b = Bposicao(B, x);

    empilhahist(&B -> hist, E);
    Sobe(B, x);

}

static void ViraTopo(Baralho *B, int k){
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

void ViraTopo_Real(Baralho *B, int k){
    entrada E;
    E.OPE = VIRATOPO;
    E.a = k;

    empilhahist(&B -> hist, E);
    ViraTopo(B, k);

}

void Mostra(const Baralho *B){
    for(int  i = 1; i <= B -> Ncartas; i++){
        printf("%d", Bcartas(B, i));
        
        if(i < B -> Ncartas){
            printf(" ");
        }
    }

    printf("\n");

}

//desfaz

static void DesfazSobe(Baralho *B, int x, int p){
    for(int i = 2; i <= p; i++){
        int carta = Bcartas(B, i);
        Lugarcerto(B, indice(B -> topo, B -> direcao, B -> Ncartas, i - 1), carta);
    }

    Lugarcerto(B, indice(B -> topo, B -> direcao, B -> Ncartas, p), x);
}

void Desfaz(Baralho *B){
    entrada E;

    if(desempilhahist(&B -> hist, &E) == 0){
        return;
    }
    switch(E.OPE){
        case CORTA:
        B -> topo = E.a;
        break;

        case VIRA:
        Vira(B);
        break;

        case SOBE: 
        DesfazSobe(B, E.a, E.b);
        break;

        case VIRATOPO:
        ViraTopo(B, E.a);
        break;
    }
}



