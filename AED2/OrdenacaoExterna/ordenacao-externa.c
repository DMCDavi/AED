#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *xp, char *yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(char arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void preencheFita(FILE *fita, char *frase, int initial)
{
	int contBloco = 0, contFrase = initial;
	char bloco[4];
	for (contFrase; contFrase < initial + 3; contFrase++)
	{
		bloco[contFrase] = frase[contFrase];
		contBloco++;
	}
	bubbleSort(bloco, 3);
	fputs(bloco, fita);
}

void criarArqs(FILE *fita[])
{
	int i = 1;
	char str[20];
	for (i = 1; i < 7; i++)
	{
		sprintf(str, "file%d.txt", i);
		fita[i - 1] = fopen(str, "w");
		if (fita[i - 1] == NULL)
		{
			printf("Error: the file could not be opened\n");
			printf("Closing the system...\n");
			exit(1);
		}
	}
}

int main()
{
	FILE *pArq[6];
	char frase[28];
	criarArqs(pArq);
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	scanf("%s", frase);
	preencheFita(pArq[0], frase, 0);
	return 0;
}
