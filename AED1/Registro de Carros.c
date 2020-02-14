#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
		
	char placa[7];
	char modelo[20];
	int ano;
	char cor[20];
	char marca[20];
		
}lista;
lista *carro;

int limit(){
	
	int pos;
	printf("Por favor sr. usuario, digite o numero que represnta a posicao em que o carro registrado se encontra\n");
	scanf("%d", &pos);
	
	if(pos < 0 || pos > 19){
		
		printf("Usuario... ta no molhos? O numero tem que estar entre 0 e 19 ne... Tente novamente\n");
		return limit();
		
	}else return pos;
	
}

void registro(int x){
	
	printf("Digite a placa:\n");
	scanf("%s", carro[x].placa);
	printf("Digite o modelo:\n");
	scanf("%s", carro[x].modelo);
	printf("Digite o ano:\n");
	scanf("%d", &carro[x].ano);
	printf("Digite a cor:\n");
	scanf("%s", carro[x].cor);
	printf("Digite a marca:\n");
	scanf("%s", carro[x].marca);
	fflush(stdin);
	
}

int main(){
	
	char sim_nao;
	int cont = 0, pos;
	carro = (lista*)malloc(20*sizeof(lista));
	
	while(true){
		
		printf("Querido usuario. Gostaria de adicionar um novo carro? (S/N)\n");
		scanf("%c", &sim_nao);
		fflush(stdin);
		
		if(sim_nao == 'S' && cont == 20){
				
				printf("Poxa usuario... que chato, voce atingiu seu limite maximo de 20 carros.\nDeseja sobrescrever os dados de um carro ja registrado? (S/N)\n");
				scanf("%c", &sim_nao);
				fflush(stdin);
				
				if(sim_nao == 'S'){
					
					pos = limit();
					printf("Carro registrado com o numero: %d\n\n", pos);
					printf("Placa: %s\n", carro[pos].placa);
					printf("Modelo: %s\n", carro[pos].modelo);
					printf("Ano: %d\n", carro[pos].ano);
					printf("Cor: %s\n", carro[pos].cor);
					printf("Marca: %s\n", carro[pos].marca);
					printf("\nDeseja sobrescrever estes dados? (S/N)\n");
					scanf("%s", &sim_nao);
					fflush(stdin);
					cont = 20;
					
					if(sim_nao == 'S') {
						registro(pos);
					}
					
				}else if(sim_nao == 'N')break;
				
			}
		
		if(sim_nao == 'S' && cont != 20){
			registro(cont);	
			cont++;
		} 
		else if(sim_nao == 'N')break;
		else if(sim_nao != 'N' && sim_nao != 'S') printf("Por favor, digite 'S' para sim ou 'N' para nao\n");

	}return 0;	
	
}
