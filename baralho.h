#include <stdio.h>
#define BARALHO_H
 
typedef struct baralho Baralho;
 
Baralho *baralho_cria(int n);   /* Um baralho novo, com as cartas 1,...,n do topo para o fundo;*/
void baralho_apaga(Baralho *b); /*o baralho anterior e o histórico são descartados */
 
void baralho_corta(Baralho *b, int x);     /*  as cartas que estavam acima de x vão para o fundo, na mesma ordem, e x fica no topo */
void baralho_sobe(Baralho *b, int x);      /* tira x de onde estava e vai ao topo; as outras mantem a ordem */
void baralho_vira(Baralho *b);             /* inverte o baralho inteiro */
void baralho_viratopo(Baralho *b, int k);  /* inverte so as k cartas de cima */
void baralho_desfaz(Baralho *b);           /* desfaz a acao mais recente do historico se vazio nada acontece */
 
int  baralho_carta(const Baralho *b, int p);    /* rotulo da carta na posicao p */ 
/* const: esta função só consulta o baralho, não o modifica. */
int  baralho_posicao(const Baralho *b, int x);  /* posicao da carta x */

void baralho_mostra(const Baralho *b, FILE *out); /* rotulos do topo ao fundo, separados por espaco, + '\n' */
 
#endif
