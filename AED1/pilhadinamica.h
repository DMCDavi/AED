#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[15];
	int valor;
	char naipe[10];
}CARTA;

typedef struct no{
	CARTA dados;
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
int empilha(PILHA *p, CARTA c){ 
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


int desempilha(PILHA *p, CARTA *c){ 	
	if(pilha_vazia(p)) return 0;
	NO *aux = p->topo;
	
	strcpy(c->nome, aux->dados.nome);
	strcpy(c->naipe, aux->dados.naipe);
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
		printf("Carta: %s; Valor: %d; Naipe: %s\n", aux->dados.nome, aux->dados.valor, aux->dados.naipe);
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
