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
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}