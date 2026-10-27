#include <stdio.h>
#include <string.h>

#include "cartasbaralho.h"

int main(void){
    Baralho *B = NULL;
    char Comando[64];

    while(scanf("%63s", Comando) == 1){
        
        if(strcmp(Comando, "FIM") == 0){
            break;
        }

        else if(strcmp(Comando, "BARALHO") == 0){
            int Ncartas;
            if(scanf("%d", &Ncartas) != 1){
                break;
            }
            Destroi(B);
            B =  CriaBaralho(Ncartas);
        }

        else if(strcmp(Comando, "CORTA") == 0){
            int x;
            if(scanf("%d", &x) != 1){
                break;
            }

            Corta_Real(B, x);
        }

        else if(strcmp(Comando, "SOBE") == 0){
            int x;
            if(scanf("%d", &x) != 1){
                break;
            }

            Sobe_Real(B, x);
        }

        else if(strcmp(Comando, "VIRA") == 0){
            Vira_Real(B);
        }

        else if(strcmp(Comando, "VIRATOPO") == 0){
            int k;
            if(scanf("%d", &k) != 1){
                break;
            }

            ViraTopo_Real(B, k);
        }

        else if(strcmp(Comando, "DESFAZ") == 0){
            Desfaz(B);
        }

        else if(strcmp(Comando, "MOSTRA") == 0){
            Mostra(B);
        }

        else if(strcmp(Comando, "CARTA") == 0){
            int p;
            if(scanf("%d", &p) != 1){
                break;
            }

            printf("%d\n", Bcartas(B, p));
        }

        else if(strcmp(Comando, "POSICAO") == 0){
            int x;
            if(scanf("%d", &x) != 1){
                break;
            }
            
            printf("%d\n", Bposicao(B, x));
        }

    }

    Destroi(B);
    return 0;

}