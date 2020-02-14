#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[150];
	int idade;
	char sexo;
	short gravida;
} PACIENTE;

typedef struct no{
	PACIENTE dados;
	struct no *prox;
} NO;

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
int enfileira(FILA *f, PACIENTE p){ // Esse *f é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
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

int desenfileira(FILA *f, PACIENTE *p){ 
	if(f==NULL) return 0;
	NO *aux = f->ini;
	
	strcpy(p->nome, aux->dados.nome);
	p->idade = aux->dados.idade;
	p->sexo = aux->dados.sexo;
	p->gravida = aux->dados.gravida;
	
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
		printf("%s, %d anos, %s, %s|", aux->dados.nome, aux->dados.idade, (aux->dados.sexo=='F'?"Fem.":"Masc."), (aux->dados.gravida?"GEST":"NAO GEST"));
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
