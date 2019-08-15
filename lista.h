#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
	char marca[30];
	char placa[9];
	char modelo[50];
	int tipoMarcha; // 1=Auto, 2=Manual
	int qtdPortas;		
} Veiculo;

Veiculo criarVeiculo(char* placa, char* modelo, char* marca, int qportas, int tmarcha){
	Veiculo v;
	strcpy(v.marca, marca);
	strcpy(v.modelo, modelo);
	strcpy(v.placa, placa);
	v.qtdPortas = qportas;
	v.tipoMarcha = tmarcha;
	return v;
}

typedef struct{
	int cont;
	Veiculo dados[MAX];
} Lista;

Lista* criarLista(){
	Lista *l;
	l = (Lista*)malloc(sizeof(Lista));
	if(l != NULL){
		l->cont = 0;
	}
	return l;
}

void destruirLista(Lista* l){
	free(l);
}

int tamanhoLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont;		
}

int estahVaziaLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont == 0;
}

int estaCheiaLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont == MAX;
}

int inserirNoFinalLista(Lista* l, Veiculo v){
	if(l==NULL) return 0;
	if(estaCheiaLista(l)) return 0;
	l->dados[l->cont] = v;
	l->cont++;
	return 1;
}

int inserirNoInicioLista(Lista* l, Veiculo v){
	int i;
	if(l==NULL) return 0;
	if(estaCheiaLista(l)) return 0;
	for(i=l->cont-1; i>=0; i--){
		l->dados[i+1] = l->dados[i];
	}
	l->dados[0] = v;
	l->cont++;
	return 1;
}

int inserirNoMeioLista(Lista* l, Veiculo v, int posicao){
	int i;
	if(l==NULL) return 0;
	if(estaCheiaLista(l)) return 0;
	for(i=l->cont-1; i>=posicao; i--){
		l->dados[i+1] = l->dados[i];
	}
	l->dados[posicao] = v;
	l->cont++;
	return 1;
}

int inserirOrdenado(Lista* l, Veiculo v){
	int i, posicao;
	if(l==NULL) return 0;
	if(estaCheiaLista(l)) return 0;
	if(estahVaziaLista(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(l->dados[i].placa, v.placa) > 0); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = v;
	l->cont++;
	return 1;
}

void imprimirVeiculo(Veiculo v){
	printf("=======================================\n");
	printf("Veiculo: \n");
	printf("\tPlaca: %s\n", v.placa);
	printf("\tMarca: %s\n", v.marca);
	printf("\tModelo: %s\n", v.modelo);
	printf("\tTipo: %s\n", v.tipoMarcha == 1 ? "AUTOMATICO" : "MANUAL");
	printf("\t%d portas\n", v.qtdPortas);
	printf("=======================================\n\n");
}

void imprimirDadosLista(Lista* l){
	int i;
	if(l != NULL){
		if(!estahVaziaLista(l)){
			for(i=0; i<l->cont; i++){
				imprimirVeiculo(l->dados[i]);
			}
		}else{
			printf("Lista esta vazia!\n");
		}
	}else{
		printf("Lista nao foi criada!\n");
	}
}

int buscaBinaria (char* x, Lista* l) {    
    int inf,sup,meio;
	inf=0;
	sup=(l->cont-1);
	while (inf<=sup)
	{
	  	meio=(inf+sup)/2;
	  	if (strcmp(l->dados[meio].placa, x) == 0)
	       return meio;
	  	else if (strcmp(l->dados[meio].placa, x) > 0)
	       sup=meio-1;
	  	else
	       inf=meio+1;
	}
	return -1;   /* não encontrado */
}