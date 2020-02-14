#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUTURAS

typedef struct{
	int valor;
}NUMERO;

typedef struct no{
	NUMERO dados;
	struct no *prox;
} NO;

//PILHA

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
int empilha(PILHA *p, NUMERO c){ 
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


int desempilha(PILHA *p, NUMERO *c){ 	
	if(pilha_vazia(p)) return 0;
	NO *aux = p->topo;
	
	c->valor = aux->dados.valor;
	
	// Desloca o topo fazendo-o apontar para o pr�ximo n�
	p->topo = aux->prox;
	
	// Libera o n� desempilhado
	free(aux);

	return 1;
}

void destroi_pilha(PILHA *p){
	if(!pilha_vazia(p)){
		NO *atu = p->topo;
		while (atu!=NULL){
			p->topo = atu->prox;
			free(atu);
			atu = p->topo;
		}		
	}
	p=NULL;
}

//FILA

typedef struct{
	NO *ini;
	NO *fim;
}FILA; 

FILA* cria_fila(){ // ela ir� alocar um espa�o na mem�ria;
	FILA *fi = (FILA*) malloc(sizeof(FILA));
	if(fi != NULL){ // Deu certo a aloca��o
		fi->fim = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a fila est� vazia
		fi->ini = NULL;
	}
	return fi;
}	

int fila_vazia(FILA *f){
	if(f==NULL || f->ini==NULL) return 1;
	return 0;
}

// Fun��o que insere ao final da fila
int enfileira(FILA *f, NUMERO p){ // Esse *f � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da LISTA*, o que est� apontando para o NULL
	if(f==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	novo_no->dados=p;
	novo_no->prox=NULL;
	if(f->ini==NULL){// Fila est� vazia, vamos inserir no in�cio
		f->ini = novo_no;
		f->fim = novo_no;
	}else{
		NO *aux = f->ini;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}

int desenfileira(FILA *f, NUMERO *p){ 
	if(f==NULL) return 0;
	NO *aux = f->ini;

	p->valor = aux->dados.valor;
	
	// Desloca o inicio fazendo-o apontar para o pr�ximo n�
	f->ini = aux->prox;
	
	// Libera o n� desempilhado
	free(aux);

	return 1;
}

void destroi_fila(FILA *f){
	NO *atu = f->ini;
	while (atu!=NULL){
		f->ini=atu->prox;
		free(atu);
		atu=f->ini;
	}
	f=NULL;
}

//FILA DE PRIORIDADE

typedef struct{
	NO *ini;
	NO *fim;
}FILA_PRI; 

FILA_PRI* cria_fila_pri(){ // ela ir� alocar um espa�o na mem�ria;
	FILA_PRI *fi = (FILA_PRI*) malloc(sizeof(FILA_PRI));
	if(fi != NULL){ // Deu certo a aloca��o
		fi->fim = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a fila est� vazia
		fi->ini = NULL;
	}
	return fi;
}	

int fila_pri_vazia(FILA_PRI *f){
	if(f==NULL || f->ini==NULL) return 1;
	return 0;
}

// Fun��o que insere ao final da fila
int enfileira_pri(FILA_PRI *f, NUMERO p){ // Esse *f � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da LISTA*, o que est� apontando para o NULL
	if(f==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	novo_no->dados=p;
	novo_no->prox=NULL;
	if(f->ini==NULL){// Fila est� vazia, vamos inserir no in�cio
		f->ini = novo_no;
		f->fim = novo_no;
	}else{
		//inserir no inicio da fila
		if(p.valor > f->ini->dados.valor){
			novo_no->prox = f->ini;
			f->ini = novo_no;
		}
		else{
			NO *aux = f->ini;
			while(aux->prox != NULL){
				if(p.valor > aux->prox->dados.valor) break;
				aux = aux->prox;
			}
			//inserir no final da fila
			if(aux->prox == NULL)aux->prox = novo_no;
			//inserir no meio da fila	
			else{
				novo_no->prox = aux->prox;
				aux->prox = novo_no;
			}
		}
	}
	return 1;
}

int desenfileira_pri(FILA_PRI *f, NUMERO *p){ 
	if(f==NULL) return 0;
	NO *aux = f->ini;

	p->valor = aux->dados.valor;
	
	// Desloca o inicio fazendo-o apontar para o pr�ximo n�
	f->ini = aux->prox;
	
	// Libera o n� desempilhado
	free(aux);

	return 1;
}

void destroi_fila_pri(FILA_PRI *f){
	NO *atu = f->ini;
	while (atu!=NULL){
		f->ini=atu->prox;
		free(atu);
		atu=f->ini;
	}
	f=NULL;
}