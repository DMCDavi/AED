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

char *geraBloco(char *str, int numBloco)
{
	numBloco *= 3;
	if (numBloco >= strlen(str))
		return NULL;
	int max = numBloco + 3;
	char *bloco;
	bloco = (char *)malloc(sizeof(char *) * 4);
	int i;
	for (i = 0; numBloco < max && str[numBloco] != '\0'; numBloco++)
	{
		bloco[i++] = str[numBloco];
	}
	bloco[i] = '\0';
	bubbleSort(bloco, strlen(bloco));
	return bloco;
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
	int i, j;
	criarArqs(pArq);
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	scanf("%s", frase);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fputs(geraBloco(frase, i == 0 ? j : j + 3), pArq[j]);
		}
	}

	return 0;
}
