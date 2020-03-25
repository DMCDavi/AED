#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10

void quick_sort(int *a, int left, int right) 
{
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int buscaBinaria(int *vet[], int alvo, int esquerda, int direita)
{
	int meio = (esquerda + direita) / 2;
	if( vet[meio] == alvo )
		return meio;
	else if( vet[meio] > alvo )
	{
		direita = meio;
		buscaBinaria( vet, alvo, esquerda, direita );
	}
	else if( vet[meio] < alvo )
	{
		esquerda = meio;
		buscaBinaria( vet, alvo, esquerda, direita );
	} else
		return -1;
}

int main(int argc, char** argv)
{
	int i, vet[MAX], alvo;
	printf("Digite 10 numeros inteiros: ");
	for(i = 0; i < MAX; i++)
		scanf("%d", &vet[i]);
	quick_sort(vet, 0, MAX - 1);
	printf("Agora digite um numero desse vetor que voce queira encontrar: ");
	scanf("%d", &alvo);
	printf("O index desse numero eh: %d\n", buscaBinaria( vet, alvo, 0, MAX - 1));
	return 0;
}