#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

FILE *fita[6];

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

void abreArqs(char *modo)
{
	int i = 1;
	char str[20];
	for (i = 1; i < 7; i++)
	{
		sprintf(str, "file%d.txt", i);
		fita[i - 1] = fopen(str, modo);
		if (fita[i - 1] == NULL)
		{
			printf("Error: the file could not be opened\n");
			printf("Closing the system...\n");
			exit(1);
		}
	}
}

void fechaArqs()
{
	int i;
	for (i = 0; i < 6; i++)
	{
		fclose(fita[i]);
	}
}

void ordenaFinal()
{
	int j, i, k, l, pointer[3] = {0, 0, 0}, fitaMenorCh = 5;
	char menorCh = 'z', ch;
	rewind(fita[0]);
	for (j = 0; j < 27; j++)
	{
		menorCh = 'z';
		for (i = 3; i < 6; i++)
		{
			if (pointer[i - 3] < 9)
			{
				fseek(fita[i], pointer[i - 3], SEEK_SET);
				ch = fgetc(fita[i]);
				if (ch <= menorCh)
				{
					menorCh = ch;
					fitaMenorCh = i;
				}
			}
		}
		pointer[fitaMenorCh - 3]++;
		if ((menorCh >= 'a' && menorCh <= 'z') || (menorCh >= 'A' && menorCh <= 'Z'))

			fputc(menorCh, fita[0]);
	}
}

void intercalaFitas()
{
	int j, i, k, l, pointer[3] = {0, 0, 0}, fitaMenorCh = 5, initialPointer = 0;
	char menorCh = 'z', ch;
	for (k = 3; k < 6; k++)
	{
		for (j = 0; j < 9; j++)
		{
			menorCh = 'z';
			for (i = 0; i < 3; i++)
			{
				if (pointer[i] < initialPointer + 3)
				{
					fseek(fita[i], pointer[i], SEEK_SET);
					ch = fgetc(fita[i]);
					if (ch <= menorCh)
					{
						menorCh = ch;
						fitaMenorCh = i;
					}
				}
			}
			pointer[fitaMenorCh]++;
			if ((menorCh >= 'a' && menorCh <= 'z') || (menorCh >= 'A' && menorCh <= 'Z'))
				fputc(menorCh, fita[k]);
		}
		initialPointer = initialPointer + 3;
		for (l = 0; l < 3; l++)
		{
			pointer[l] = initialPointer;
		}
	}
}

int main()
{
	char chLido, frase[28];
	int i = 0, j = 0;
	abreArqs("w+");
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	while (1)
	{
		if (kbhit)
		{
			chLido = getch();
			if (chLido == 13)
				break;
			if (i <= 27)
			{
				printf("%c", chLido);
				frase[i] = chLido;
			}
		}
		i++;
	}
	frase[i] = '\0';
	printf("\n");
	for (i = 0; i < ((strlen(frase) / 3) + (strlen(frase) % 3)); i++)
	{
		if (i % 3 == 0)
			j = 0;
		fputs(geraBloco(frase, i), fita[j]);
		j++;
	}
	intercalaFitas();
	ordenaFinal();
	fechaArqs();
	return 0;
}

// ORDENANDOINFODOARQUIVOGRHAM