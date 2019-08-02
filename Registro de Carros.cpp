#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	
	struct{
		
		char *placa;
		char *modelo;
		int ano;
		char *cor;
		char *marca;
		
		
	}carro;
	
	char sim_nao;
	carro.placa = (char*)malloc(7*sizeof(char));
	carro.modelo = (char*)malloc(20*sizeof(char));
	carro.cor = (char*)malloc(20*sizeof(char));
	carro.marca = (char*)malloc(20*sizeof(char));
	
	while(true){
		printf("Querido usuario. Gostaria de adicionar um novo carro? (S/N)\n");
		scanf("%c", &sim_nao);
		if(sim_nao == 'S'){
			
			printf("Digite a placa:\n");
			scanf("%s", &carro.placa);
			printf("Digite o modelo:\n");
			scanf("%s", &carro.modelo);
			printf("Digite o ano:\n");
			scanf("%d", &carro.ano);
			printf("Digite a cor:\n");
			scanf("%s", &carro.cor);
			printf("Digite a marca:\n");
			scanf("%s", &carro.marca);
			printf("%s\n", carro.placa);
			printf("%s\n", carro.modelo);
			printf("%d\n", carro.ano);
			printf("%s\n", carro.cor);
			printf("%s\n", carro.marca);
			
			
		}else if(sim_nao == 'N')break;
		else{
			
			printf("Por favor, digite 'S' para sim ou 'N' para nao\n");
			
		}
	}
	
	   return 0;	
}