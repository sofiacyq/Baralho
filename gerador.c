#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int sorteia(int n) {
    long r = (long)rand() * ((long)RAND_MAX + 1) + rand();
    return (int)(r % n) + 1;
}//junta-se duas chamadas de rand para que ultrapasse a constante RAND_MAX

int main(int argc, char **argv) { //os parâmetros são, respectivamente, rajada e n 
    if (argc < 3) {
        fprintf(stderr, "uso: %s <SOBE|CARTA|POSICAO|CORTA|DESFAZ> <n> [semente]\n", argv[0]);
        return 1;
    }
    const char *rajada = argv[1];
    int n = atoi(argv[2]);
    if (n < 1){
        return (1);
    } // se n<1, o programa encerra sem gerar nada
    srand(argc > 3 ? (unsigned)atoi(argv[3]) : 12345u); //sem semente, usa sempre 12345, então a mesma chamada gera sempre o mesmo arquivo
    //as medições de rajadas e de versões diferentes do programa ficam comparáveis
    long m = 2L * n;
    if (strcmp(rajada, "SOBE") != 0 &&
        strcmp(rajada, "CARTA") != 0 &&
        strcmp(rajada, "POSICAO") != 0 &&
        strcmp(rajada, "CORTA") != 0 &&
        strcmp(rajada, "DESFAZ") != 0) {
        fprintf(stderr, "rajada desconhecida: %s\n", rajada);
        return (1);
    }
    //as rajadas abaixo imprimem BARALHO n e depois m comandos, por fim, FIM.
    printf("BARALHO %d\n", n);
    if (strcmp(rajada, "SOBE") == 0) {
        for (long i = 0; i < m; i++) printf("SOBE %d\n", sorteia(n));
    } else if (strcmp(rajada, "CARTA") == 0) {
        for (long i = 0; i < m; i++) printf("CARTA %d\n", sorteia(n));
    } else if (strcmp(rajada, "POSICAO") == 0) {
        for (long i = 0; i < m; i++) printf("POSICAO %d\n", sorteia(n));
    } else if (strcmp(rajada, "CORTA") == 0) {
        for (long i = 0; i < m; i++) {
            if (rand() % 2) printf("CORTA %d\n", sorteia(n));
            else            printf("VIRA\n");
        }
    } else if (strcmp(rajada, "DESFAZ") == 0) {
        for (long i = 0; i < m; i++) {
            if (i % 3 == 2) { printf("DESFAZ\n"); continue; }
            switch (rand() % 3) {
                case 0:  printf("CORTA %d\n", sorteia(n)); break;
                case 1:  printf("VIRA\n"); break;
                default: printf("SOBE %d\n", sorteia(n)); break;
            }
        }
    } else {
        fprintf(stderr, "rajada desconhecida: %s\n", rajada);
        return 1;
    }
    printf("FIM\n");
    return 0;
}
