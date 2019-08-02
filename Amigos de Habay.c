#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
	
	char nome[100];
	char sim_nao[4];
	char vencedor[100];
	char amigos_sim[100];
	char amigos_nao[100];
	
}Lista;

int main(){
	
	int cont_nome = 0, cont_sim = 0, cont_nao = 0;
	Lista amigos[10000];
	while(true){
		
		scanf("%s", &amigos[cont_nome].nome);
		if(strcmp(amigos[cont_nome].nome, "FIM") == 0) break;
		scanf("%s", &amigos[cont_nome].sim_nao);
		if(strcmp(amigos[cont_nome].sim_nao, "YES")){
			
			amigos[cont_sim].amigos_sim = amigos[cont_nome].nome;
			cont_sim++;
			
		}else if(strcmp(amigos[cont_nome].sim_nao, "NO")){
			
			amigos[cont_nao].amigos_nao = amigos[cont_nome].nome;
			cont_nao++;
			
		}cont_nome++;
		
	}
	
	
	
	return 0;
	
}
