#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	int dados;
	struct no *prox;
} NO;

typedef NO* LISTA; // Ponteiro para um Ponteiro

/*LISTA* cria_lista(){ // ela irá alocar um espaço na memória;
	LISTA *li = (LISTA*) malloc(sizeof(LISTA));
	if(li != NULL) // Deu certo a alocação
		*li = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a lista está vazia
	return li;
}	

int listase_vazia(LISTA *l){
	if(l==NULL) return 1;
	return 0;
}

// Função que insere ao final da lista
int insere_listase(LISTA *l, int d){ // Esse *l é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
	if(l==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados= d;
	novo_no->prox=NULL;
	if((*l)==NULL)// Lista está vazia, vamos inserir no início
		*l = novo_no;
	else{
		NO *aux = *l;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}

void imprime_listase(LISTA *l){
	NO *aux = *l;
	while (aux!=NULL){
		printf("Dado: %d", aux->dados);
		aux=aux->prox;
	}
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

void destroi_listase(LISTA *l){
	NO *atu = *l;
	while (atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	*l=NULL;
}*/

void destroi_impares(LISTA *l){
	NO *atual = *l;
	NO *aux = *l;
	NO *ant = *l;
	int cont;
	while(aux != NULL){
		if(aux->dados % 2 == 1){
			while(ant->prox != atual){
				ant = ant->prox;
			}
			ant->prox = aux->prox;
			aux = atual;
			free(atual);
		}
		aux = aux->prox;
		atual = atual->prox;
		
	}
}
/*
LISTA *lista_num;

int main(){
	lista_num = cria_lista();
	int num;
	num = 2;
	insere_listase(lista_num, num);
	num = 3;
	insere_listase(lista_num, num);
	num = 4;
	insere_listase(lista_num, num);
	num = 7;
	insere_listase(lista_num, num);
	num = 10;
	insere_listase(lista_num, num);
	num = 15;
	insere_listase(lista_num, num);
	num = 11;
	insere_listase(lista_num, num);
	destroi_impares(lista_num);
	imprime_listase(lista_num);
	return 0;
}*/
