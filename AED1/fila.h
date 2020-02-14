#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
	char nome[100];
	char cpf[11];
	char plano[50];
	char sexo; 
	int idade;
	int prioridade;		
} Paciente;

Paciente criarPaciente(char* n, char* c, char* pl, char s, int i, int pri){
	Paciente p;
	strcpy(p.nome, n);
	strcpy(p.cpf, c);
	strcpy(p.plano, pl);
	p.sexo = s;
	p.idade = i;
	p.prioridade = pri;
	return p;
}

typedef struct{
	int ini, fim, cont;
	Paciente dados[MAX];
} Fila;

Fila* criarFila(){
	Fila *f;
	f = (Fila*)malloc(sizeof(Fila));
	if(f != NULL){
		f->cont = 0;
		f->ini = 0;
		f->fim = 0;
	}
	return f;
}

void destruirFila(Fila* f){
	free(f);
}

int tamanhoFila(Fila* f){
	if(f == NULL) return -1;
	else return f->cont;		
}

int estahVaziaFila(Fila* f){
	if(f == NULL) return -1;
	else return f->cont == 0;
}

int estaCheiaFila(Fila* f){
	if(f == NULL) return -1;
	else return f->cont == MAX;
}

int inserirNaFila(Fila* f, Paciente p){
	if(f==NULL) return 0;
	if(estaCheiaFila(f)) return 0;
	f->dados[f->fim] = p;
	f->fim = (f->fim+1) % MAX; 
	f->cont++;
	return 1;
}

Paciente removerDaFila(Fila *f) { 
	Paciente temp;
	if(f != NULL && !estahVaziaFila(f)){	
		temp = f->dados[f->ini]; // pega o valor e incrementa o primeiro da fila
		f->ini = (f->ini+1) % MAX;
		f->cont--;  // um item retirado
		return temp;
	}else{
		return temp;
	}
}

Paciente buscarPrimElem(Fila *f) { 
	Paciente temp;
	if(!estahVaziaFila(f)) temp = f->dados[f->ini];
	return temp;
}

void imprimirPaciente(Paciente p){
	printf("\n=======================================\n");
	printf("Paciente: \n");
	printf("\tNome: %s, %d anos\n", p.nome, p.idade);
	printf("\tCPF: %s\n", p.cpf);
	printf("\tPlano de Saude: %s\n", p.plano);
	printf("\tTipo: %s\n", p.prioridade == 1 ? "PRIORIDADE" : "NAO PRIORIDADE");
	printf("\tSexo: %c\n", p.sexo);
	printf("=======================================\n");
}

void imprimirDadosFila(Fila* f){
	int i;
	if(f != NULL){
		if(!estahVaziaFila(f)){
			for(i=f->ini; i!=(f->fim % MAX); i = ((i + 1) % MAX)){
				imprimirPaciente(f->dados[i]);
			}
		}else{
			printf("Lista esta vazia!\n");
		}
	}else{
		printf("Lista nao foi criada!\n");
	}
}