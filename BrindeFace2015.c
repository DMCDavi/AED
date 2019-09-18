#include "pilhadinamica_brinde.h"

PILHA *pi;

int main(){
	BLOCO b;
	pi = cria_pilha();
    int N, cont, res = 0;
    scanf("%d", &N);
    if(N > 0 && N <= 100){
        for(cont = 0; cont < N; cont++){
        	strcpy(b.letra, "F A C E");
        	if(pilha_vazia(pi)) empilha(pi, b);
			fflush(stdin);
			scanf("%[^\n]s", &b.letra);
			fflush(stdin);
            if(b.letra[0] == pi->topo->dados.letra[6] && b.letra[2] == pi->topo->dados.letra[4]
			&& b.letra[4] == pi->topo->dados.letra[2] && b.letra[6] == pi->topo->dados.letra[0]){
				res++;
				desempilha(pi, &b);
			}else empilha(pi, b);
        }printf("%d\n", res);
    }
    return 0;
}