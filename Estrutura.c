#include <stdbool.h>
#include "pilhafiladin_estrutura.h"

PILHA *pilha;
FILA *fila;
FILA_PRI *fila_pri;

int main(){
	NUMERO elem;
	int qntd_elem, cont, push_pop;
	while(scanf("%d", &qntd_elem) != EOF){
		if(qntd_elem > 0 && qntd_elem <= 1000){
			bool eh_pilha = true, eh_fila = true, eh_fila_pri = true;
			pilha = cria_pilha();
			fila = cria_fila();
			fila_pri = cria_fila_pri();
			for(cont = 0; cont < qntd_elem; cont++){
				scanf("%d %d", &push_pop, &elem.valor);
				if(push_pop == 1){
					empilha(pilha, elem);
					enfileira(fila, elem);
					enfileira_pri(fila_pri, elem);
				}else if(push_pop == 2){
					if(elem.valor == pilha->topo->dados.valor) desempilha(pilha, &elem);
					else eh_pilha = false;
					if(elem.valor == fila->ini->dados.valor) desenfileira(fila, &elem);
					else eh_fila = false;
					if(elem.valor == fila_pri->ini->dados.valor) desenfileira_pri(fila_pri, &elem);
					else eh_fila_pri = false;
				}
			}
			if(eh_pilha && !eh_fila && !eh_fila_pri)printf("stack\n");
			else if(!eh_pilha && eh_fila && !eh_fila_pri)printf("queue\n");
			else if(!eh_pilha && !eh_fila && eh_fila_pri)printf("priority queue\n");
			else if(!eh_pilha && !eh_fila && !eh_fila_pri)printf("impossible\n");
			else printf("not sure\n");
			destroi_pilha(pilha);
			destroi_fila(fila);
			destroi_fila_pri(fila_pri);
		}
	}
	return 0;
}