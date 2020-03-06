#include <stdio.h>
#include <string.h>

void criarArqs(FILE* fita[]);
void preencheFita(FILE* fita[], char* vet, int fitaMin);

int main(){
	FILE* pArq[6];
	int isOrdered = 0;
	char input[28];
	
	scanf("%s", input);
	
	criarArqs(pArq);
	preencheFita(pArq, input, 0);
	return 0;
}

void preencheFita(FILE* fita[], char* vet, int fitaMin){
	
	char auxvet[4] = {0,0,0};
	int j = fitaMin;
	for(int i = 0; vet[i]!='\0'; i++){
		if((i%3)){
			fputs(auxvet, fita[j++]);
			memset(auxvet,0,3);
		}
		printf("%d\n", i%3);
		auxvet[i%3] = vet[i];
		printf("%s\n", auxvet); 
		if(j==fitaMin+2){
			j=fitaMin;
		}
	}
}

void criarArqs(FILE* fita[]){
	char str[20];
	for(int i = 1; i<7;i++){
		sprintf(str, "file%d.txt", i);
		fita[i-1] = fopen(str, "w");
	}
}