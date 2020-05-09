#include "listaenc.h"

LISTA *li; // Ponteiro para Ponteira (nó cabeça)

int main(){
	
	li = cria_lista();
	
	CARRO c;
	c.ano = 2019;
	strcpy(c.marca, "Renault");
	strcpy(c.modelo, "Sandero");
	strcpy(c.placa, "PLJ8A90");
	
	CARRO c2;
	c2.ano = 2019;
	strcpy(c2.marca, "Chevrolet");
	strcpy(c2.modelo, "COBALT");
	strcpy(c2.placa, "PLJ1B88");
	
	insere_listase(li, c);
	insere_listase(li, c2);
	
	imprime_listase(li);
	
	return 0;
}
