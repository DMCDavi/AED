#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char placa[7];
	int ano;
	char modelo[50];
	char marca[50];
} CARRO;

typedef struct no
{
	CARRO dados;
	struct no *prox;
} NO;

typedef NO *LISTA; // Ponteiro para um Ponteiro

LISTA *cria_lista()
{ // ela ir� alocar um espa�o na mem�ria;
	LISTA *li = (LISTA *)malloc(sizeof(LISTA));
	if (li != NULL) // Deu certo a aloca��o
		*li = NULL; // Faz o ponteiro apontar para NULL, ou seja, a lista est� vazia
	return li;
}

int listase_vazia(LISTA *l)
{
	if (l == NULL)
		return 1;
	return 0;
}

// Fun��o que insere ao final da lista
int insere_listase(LISTA *l, CARRO c)
{ // Esse *l � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da LISTA*, o que est� apontando para o NULL
	if (l == NULL)
		return 0;
	NO *novo_no = (NO *)malloc(sizeof(NO));
	if (novo_no == NULL)
		return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	novo_no->dados = c;
	novo_no->prox = NULL;
	if ((*l) == NULL) // Lista est� vazia, vamos inserir no in�cio
		*l = novo_no;
	else
	{
		NO *aux = *l;
		while (aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}

void imprime_listase(LISTA *l)
{
	NO *aux = *l;
	while (aux != NULL)
	{
		printf("Carro: %s; Ano: %d; Marca: %s; Placa: %s\n", aux->dados.modelo, aux->dados.ano, aux->dados.marca, aux->dados.placa);
		aux = aux->prox;
	}
}

NO *busca_listase(LISTA *l, CARRO c)
{
	NO *atu = *l;
	while ((atu != NULL) && (strcmp(atu->dados.placa, c.placa) != 0))
	{
		atu = atu->prox;
	}
	if (atu == NULL)
		return NULL;
	return atu;
}

int tamanho_listase(LISTA *l)
{
	int cont = 0;
	NO *atu = *l;
	while (atu != NULL)
	{
		cont++;
		atu = atu->prox;
	}
	return cont;
}

void destroi_listase(LISTA *l)
{
	NO *atu = *l;
	while (atu != NULL)
	{
		*l = atu->prox;
		free(atu);
		atu = *l;
	}
	*l = NULL;
}
