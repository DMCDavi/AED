#include "pilhaenc.h"

PILHA *pi; // Ponteiro para Ponteira (nó cabeça)

int main(){	
	CARTA c;
	pi = cria_pilha();
	
	CARTA c1;
	c1.valor = 10;
	strcpy(c1.nome, "DEZ");
	strcpy(c1.naipe, "OUROS");
	
	CARTA c2;
	c2.valor = 1;
	strcpy(c2.nome, "AZ");
	strcpy(c2.naipe, "COPAS");
	
	CARTA c3;
	c3.valor = 13;
	strcpy(c3.nome, "REI");
	strcpy(c3.naipe, "ESPADA");

	empilha(pi, c1);
	empilha(pi, c2);
	empilha(pi, c3);
	
	imprime_pilha(pi);
	
	if(desempilha(pi, &c)){
		printf("\n####### Desempilhando a carta: %s de %s\n", c.nome, c.naipe);
	}
	
	imprime_pilha(pi);
		
	CARTA c4;
	c4.valor = 2;
	strcpy(c4.nome, "DUQUE");
	strcpy(c4.naipe, "PAUS");
	empilha(pi, c4);
		
	imprime_pilha(pi);
	
	return 0;
}