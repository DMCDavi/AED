#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//PILHA

typedef struct{
	int valor;
}NUMERO;

typedef struct no{
	NUMERO dados;
	struct no *prox;
} NO;

typedef struct{
	NO *topo;
}PILHA;

PILHA* cria_pilha(){ // ela irá alocar um espaço na memória;
	PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
	if(pi != NULL) // Deu certo a alocação
		pi->topo = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a pilha está vazia
	return pi;
}	

int pilha_vazia(PILHA *p){
	if(p==NULL || p->topo==NULL) return 1;
	return 0;
}

// Função que insere no topo da pilha
int empilha(PILHA *p, NUMERO c){ 
	if(p == NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados= c;
	// Faz o novo nó apontar para o nó do topo da pilha
	novo_no->prox=p->topo;
	// Desloca o topo fazendo-o apontar para o novo nó
	p->topo = novo_no;
	return 1;
}


int desempilha(PILHA *p, NUMERO *c){ 	
	if(pilha_vazia(p)) return 0;
	NO *aux = p->topo;
	
	c->valor = aux->dados.valor;
	
	// Desloca o topo fazendo-o apontar para o próximo nó
	p->topo = aux->prox;
	
	// Libera o nó desempilhado
	free(aux);

	return 1;
}


void imprime_pilha(PILHA *p){
	printf("\n==============TOPO==============\n");	
	if(pilha_vazia(p)){
		printf("Pilha Vazia!\n");	
		return;
	} 
	NO *aux = p->topo;
	while (aux!=NULL){
		printf("Valor: %d\n", aux->dados.valor);
		aux=aux->prox;
	}
	printf("==============BASE==============\n");	
}

int tamanho_pilha(PILHA *p){
    int cont=0;
    if(!pilha_vazia(p)) {
	    NO *atu = p->topo;
	    while(atu!=NULL){
	        cont++;
	        atu=atu->prox;
	    }
	}
    return cont;
}

void destroi_pilha(PILHA *p){
	if(!pilha_vazia(p)){
		NO *atu = p->topo;
		while (atu!=NULL){
			*p->topo = *atu->prox;
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

FILA* cria_fila(){ // ela irá alocar um espaço na memória;
	FILA *fi = (FILA*) malloc(sizeof(FILA));
	if(fi != NULL){ // Deu certo a alocação
		fi->fim = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a fila está vazia
		fi->ini = NULL;
	}
	return fi;
}	

int fila_vazia(FILA *f){
	if(f==NULL || f->ini==NULL) return 1;
	return 0;
}

// Função que insere ao final da fila
int enfileira(FILA *f, NUMERO p){ // Esse *f é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
	if(f==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados=p;
	novo_no->prox=NULL;
	if(f->ini==NULL){// Fila está vazia, vamos inserir no início
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
	
	// Desloca o inicio fazendo-o apontar para o próximo nó
	f->ini = aux->prox;
	
	// Libera o nó desempilhado
	free(aux);

	return 1;
}


void imprime_fila(FILA *f){
	if(fila_vazia(f)) printf("FILA VAZIA! ");
	NO *aux = f->ini;
	printf("INI <=|");
	while (aux!=NULL){
		printf("Valor: %d\n", aux->dados.valor);
		aux=aux->prox;
	}
	printf("<= FIM\n");
}

/*
NO *busca_listase(LISTA *l, CARRO c){
	NO *atu = *l;
	while((atu!=NULL)&&(strcmp(atu->dados.placa, c.placa)!= 0)){
		atu=atu->prox;
	}
	if (atu==NULL) return NULL;
	return atu;
}

int tamanho_listase(LISTA *l){
    int cont=0;
    NO *atu = *l;
    while(atu!=NULL){
        cont++;
        atu=atu->prox;
    }
    return cont;
}
*/

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

FILA_PRI* cria_fila_pri(){ // ela irá alocar um espaço na memória;
	FILA_PRI *fi = (FILA_PRI*) malloc(sizeof(FILA_PRI));
	if(fi != NULL){ // Deu certo a alocação
		fi->fim = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a fila está vazia
		fi->ini = NULL;
	}
	return fi;
}	

int fila_pri_vazia(FILA_PRI *f){
	if(f==NULL || f->ini==NULL) return 1;
	return 0;
}

// Função que insere ao final da fila
int enfileira_pri(FILA_PRI *f, NUMERO p){ // Esse *f é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
	if(f==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados=p;
	novo_no->prox=NULL;
	if(f->ini==NULL){// Fila está vazia, vamos inserir no início
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

int desenfileira_pri(FILA_PRI *f, NUMERO *p){ 
	if(f==NULL) return 0;
	NO *aux = f->ini;

	p->valor = aux->dados.valor;
	
	// Desloca o inicio fazendo-o apontar para o próximo nó
	f->ini = aux->prox;
	
	// Libera o nó desempilhado
	free(aux);

	return 1;
}


void imprime_fila_pri(FILA_PRI *f){
	if(fila_pri_vazia(f)) printf("FILA VAZIA! ");
	NO *aux = f->ini;
	printf("INI <=|");
	while (aux!=NULL){
		printf("Valor: %d\n", aux->dados.valor);
		aux=aux->prox;
	}
	printf("<= FIM\n");
}

/*
NO *busca_listase(LISTA *l, CARRO c){
	NO *atu = *l;
	while((atu!=NULL)&&(strcmp(atu->dados.placa, c.placa)!= 0)){
		atu=atu->prox;
	}
	if (atu==NULL) return NULL;
	return atu;
}

int tamanho_listase(LISTA *l){
    int cont=0;
    NO *atu = *l;
    while(atu!=NULL){
        cont++;
        atu=atu->prox;
    }
    return cont;
}
*/

void destroi_fila_pri(FILA_PRI *f){
	NO *atu = f->ini;
	while (atu!=NULL){
		f->ini=atu->prox;
		free(atu);
		atu=f->ini;
	}
	f=NULL;
}

