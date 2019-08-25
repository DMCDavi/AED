#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct{
	int num;
} Vagao;

Vagao criarVagao(int num_vagao){
	Vagao v;
	v.num = num_vagao;
	return v;
}

typedef struct{
	int topo;
	Vagao dados[MAX];
} Pilha;

Pilha* criarPilha(){
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	if(p != NULL){
		p->topo = 0;
	}
	return p;
}

void destruirPilha(Pilha* p){
	free(p);
}

int estahVaziaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(Pilha* p, Vagao v){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = v;
	p->topo++;
	return 1;
}

Vagao desempilhar(Pilha *p) { 
	Vagao temp;
	if(p != NULL && !estahVaziaPilha(p)){	
		p->topo--;  
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

Pilha *pilha_de_entrada, *pilha_de_saida;
Vagao vagao_entrada, vagao_saida;

int main(){
	int qntd_vagoes,cont, num_vagao_saida[MAX];
	scanf("%d", &qntd_vagoes);
	while(qntd_vagoes && qntd_vagoes <= MAX && qntd_vagoes > 0){
		while(1){
			pilha_de_entrada = criarPilha();
			pilha_de_saida = criarPilha();
			int num_vagao_entrada = 1, pos = 0;
			for(cont = 0; cont < qntd_vagoes; cont++){
				scanf("%d", &num_vagao_saida[cont]);
				if(!num_vagao_saida[0]){
					printf("\n");
					break;
				} 
				vagao_saida = criarVagao(num_vagao_saida[cont]);
				empilhar(pilha_de_saida, vagao_saida);
			}
			if(!num_vagao_saida[0]) break;
			while(pos < qntd_vagoes && num_vagao_entrada <= qntd_vagoes+1){
				if(estahVaziaPilha(pilha_de_entrada) || pilha_de_entrada->dados[pilha_de_entrada->topo-1].num != pilha_de_saida->dados[pos].num){
					vagao_entrada = criarVagao(num_vagao_entrada);
					num_vagao_entrada++;
					empilhar(pilha_de_entrada, vagao_entrada);
				}
				if(pilha_de_entrada->dados[pilha_de_entrada->topo-1].num == pilha_de_saida->dados[pos].num){
					desempilhar(pilha_de_entrada);
					pos++;
				}	
			}if(estahVaziaPilha(pilha_de_entrada)) printf("Yes\n");
			else printf("No\n");
			destruirPilha(pilha_de_entrada);
			destruirPilha(pilha_de_saida);
		}scanf("%d", &qntd_vagoes);
		
	}
	return 0;
}