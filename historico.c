#include <stdio.h>
#include <stdlib.h>

#include "historico.h"

//limpa o historico
void limpahist(Historico *H){
    H -> ini = 0;
    H -> tam = 0;
}

//guarda a operacao no historico
void empilhahist(Historico *H, entrada E){
    //o tamanho maximo seja atingido, devemos fazer como exigida no enunciado, deve-se remover a operacao mais antiga guardada
    if(H -> tam == MAX){ 
        H -> vethist[H -> ini] = E;
        H -> ini = (H -> ini + 1) % MAX;
    }

    //senao e so guardar normalmente
    else{
        H -> vethist[(H -> ini + H -> tam) % MAX] = E;
        H -> tam++;   
    }
}

//desempilha e a funcao que ajuda a execultar o desfaz, aqui desempilhamos a operacao mais recente e conseguimos resolver o desfaz
int desempilhahist(Historico *H, entrada *E){
    if(H -> tam == 0){
        return 0;
    }

    H -> tam--;
    *E = H -> vethist[(H -> ini + H -> tam) % MAX];
    return 1;
    
}