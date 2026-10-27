#include <stdio.h>
#include <stdlib.h>

#include "historico.h"

void limpahist(Historico *H){
    H -> ini = 0;
    H -> tam = 0;
}

void empilhahist(Historico *H, entrada E){
    if(H -> tam == MAX){
        H -> vethist[H -> ini] = E;
        H -> ini = (H -> ini + 1) % MAX;
    }

    else{
        H -> vethist[(H -> ini + H -> tam) % MAX] = E;
        H -> tam++;   
    }
}

int desempilhahist(Historico *H, entrada *E){
    if(H -> tam == 0){
        return 0;
    }

    H -> tam--;
    *E = H -> vethist[(H -> ini + H -> tam) % MAX];
    return 1;
    
}