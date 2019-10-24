#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 50

/*typedef struct{
	char tipo_carga;	
} VAGAO;

typedef struct{
	int ini, fim, cont;
	VAGAO dados[MAX];
} FILA;

FILA* criarFila(){
	FILA *f;
	f = (FILA*)malloc(sizeof(FILA));
	if(f != NULL){
		f->cont = 0;
		f->ini = 0;
		f->fim = 0;
	}
	return f;
}

void destruirFila(FILA* f){
	free(f);
}

int tamanhoFila(FILA* f){
	if(f == NULL) return -1;
	else return f->cont;		
}

int estahVaziaFila(FILA* f){
	if(f == NULL) return -1;
	else return f->cont == 0;
}

int estaCheiaFila(FILA* f){
	if(f == NULL) return -1;
	else return f->cont == MAX;
}

int inserirNaFila(FILA* f, VAGAO p){
	if(f==NULL) return 0;
	if(estaCheiaFila(f)) return 0;
	f->dados[f->fim] = p;
	f->fim = (f->fim+1) % MAX; 
	f->cont++;
	return 1;
}

VAGAO removerDaFila(FILA *f) { 
	VAGAO temp;
	if(f != NULL && !estahVaziaFila(f)){	
		temp = f->dados[f->ini]; // pega o valor e incrementa o primeiro da fila
		f->ini = (f->ini+1) % MAX;
		f->cont--;  // um item retirado
		return temp;
	}else{
		return temp;
	}
}

VAGAO buscarPrimElem(FILA *f) { 
	VAGAO temp;
	if(!estahVaziaFila(f)) temp = f->dados[f->ini];
	return temp;
}

void imprimirVagao(VAGAO v){
	printf("\n=======================================\n");
	printf("\tLetra: %c\n", v.tipo_carga);
	printf("=======================================\n");
}

void imprimirDadosFila(FILA* f){
	int i;
	if(f != NULL){
		if(!estahVaziaFila(f)){
			for(i=f->ini; i!=(f->fim % MAX); i = ((i + 1) % MAX)){
				imprimirVagao(f->dados[i]);
			}
		}else{
			printf("Lista esta vazia!\n");
		}
	}else{
		printf("Lista nao foi criada!\n");
	}
}*/

//funcao que ordena a fila
FILA* ordena_fila(FILA *f){
	int cont;
	FILA *fila_ordenada;
	fila_ordenada = criarFila();
	for(cont = 0; cont < tamanhoFila(f); cont++){
		if(f->dados[cont].tipo_carga == 'A'){
			inserirNaFila(fila_ordenada, f->dados[cont]);
			f->dados[cont].tipo_carga = 'D';
		}
	}
	for(cont = 0; cont < tamanhoFila(f); cont++){
		if(f->dados[cont].tipo_carga == 'B'){
			inserirNaFila(fila_ordenada, f->dados[cont]);
			f->dados[cont].tipo_carga = 'D';
		}
	}
	for(cont = 0; cont < tamanhoFila(f); cont++){
		if(f->dados[cont].tipo_carga == 'C'){
			inserirNaFila(fila_ordenada, f->dados[cont]);
			f->dados[cont].tipo_carga = 'D';
		}
	}
	return fila_ordenada;
}

/*
FILA *fila_desord;

int main(){
	VAGAO v_desord;
	fila_desord = criarFila();
	v_desord.tipo_carga = 'A';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'C';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'A';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'B';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'B';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'C';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'A';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'C';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'B';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'A';
	inserirNaFila(fila_desord, v_desord);
	v_desord.tipo_carga = 'A';
	inserirNaFila(fila_desord, v_desord);
	imprimirDadosFila(ordena_fila(fila_desord));
	return 0;
}*/
