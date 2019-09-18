#include <stdbool.h>
#include "pilhafiladin_estrutura.h"

PILHA *pilha;
FILA *fila;

int main(){
	NUMERO elem;
	pilha = cria_pilha();
	fila = cria_fila();
	int qntd_entradas, qntd_elem, cont, push_pop;
	bool eh_pilha = true, eh_fila = true, eh_fila_pri = true;
	for(qntd_entradas = 0; qntd_entradas < 5; qntd_entradas++){
		scanf("%d", &qntd_elem);
		if(qntd_elem > 0 && qntd_elem <= 1000){
			for(cont = 0; cont < qntd_elem; cont++){
				scanf("%d %d", &push_pop, &elem.valor);
				if(push_pop == 1){
					empilha(pilha, elem);
					enfileira(fila, elem);
				}else if(push_pop == 2){
					if(elem.valor == pilha->topo->dados.valor) desempilha(pilha, &elem);
					else eh_pilha = false;
					if(elem.valor == fila->ini->dados.valor) desenfileira(fila, &elem);
					else eh_fila = false;
				}
			}
		}
	}
	return 0;
}