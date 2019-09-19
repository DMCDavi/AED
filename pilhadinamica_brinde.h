#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char letra[8];
}BLOCO;

typedef struct no{
	BLOCO dados;
	struct no *prox;
} NO;

typedef struct{
	NO *topo;
}PILHA;

PILHA* cria_pilha(){ // ela ir� alocar um espa�o na mem�ria;
	PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
	if(pi != NULL) // Deu certo a aloca��o
		pi->topo = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a pilha est� vazia
	return pi;
}	

int pilha_vazia(PILHA *p){
	if(p==NULL || p->topo==NULL) return 1;
	return 0;
}

// Fun��o que insere no topo da pilha
int empilha(PILHA *p, BLOCO c){ 
	if(p == NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	novo_no->dados= c;
	// Faz o novo n� apontar para o n� do topo da pilha
	novo_no->prox=p->topo;
	// Desloca o topo fazendo-o apontar para o novo n�
	p->topo = novo_no;
	return 1;
}


int desempilha(PILHA *p, BLOCO *c){ 	
	if(pilha_vazia(p)) return 0;
	NO *aux = p->topo;
	
	strcpy(c->letra, aux->dados.letra);
	
	// Desloca o topo fazendo-o apontar para o pr�ximo n�
	p->topo = aux->prox;
	
	// Libera o n� desempilhado
	free(aux);

	return 1;
}
