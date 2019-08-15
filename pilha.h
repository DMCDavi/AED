#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
	char nome[100];
	char naipe[11];
	int valor;
} Carta;

Carta criarCarta(char* n, char* np, int v){
	Carta c;
	strcpy(c.nome, n);
	strcpy(c.naipe, np);
	c.valor = v;
	return c;
}

typedef struct{
	int topo;
	Carta dados[MAX];
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

int empilhar(Pilha* p, Carta c){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = c;
	p->topo++;
	return 1;
}

Carta desempilhar(Pilha *p) { 
	Carta temp;
	if(p != NULL && !estahVaziaPilha(p)){	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

void imprimirCarta(Carta c){
	printf("\n=======================================\n");
	printf("Carta: \n");
	printf("\tNome: %s\n", c.nome);
	printf("\tNaipe: %s\n", c.naipe);
	printf("\tValor: %d\n", c.valor);
	printf("\n=======================================\n");
}

void imprimirDadosPilha(Pilha* p){
	int i;
	if(p != NULL){
		if(!estahVaziaPilha(p)){
			printf("TOPO:\n");
			for(i=p->topo-1; i>=0; i--){
				imprimirCarta(p->dados[i]);
			}
			printf("BASE:\n");
		}else{
			printf("Pilha esta vazia!\n");
		}
	}else{
		printf("Pilha nao foi criada!\n");
	}
}