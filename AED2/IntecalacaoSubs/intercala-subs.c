#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

FILE *fita[3];

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

char *geraBloco(char *str, char *lastHeap, int *numHeap)
{
	//por medidas de seguranca, se o numero passado por parametro for maior que o tamanho da string a funcao retorna NULL
	if (*numHeap > strlen(str))
		return NULL;
	char heap[4], bloco[28];
	int i, j, k = 0, qntdMarcados = 0;
	//caso essa funcao seja chamada pela primeira vez, o heap vai ser as tres primeiras letras da frase
	if (*numHeap == 0)
	{
		for (i = 0; strlen(str) > *numHeap && i < 3; (*numHeap)++)
			heap[i++] = str[*numHeap];
		heap[i] = '\0';
	}
	//caso essa funcao nao seja chamada pela primeira vez, o heap vai ser uma string composta pelos caracteres marcados na ultima ordenacao
	else
		strcpy(heap, lastHeap);
	//essa funcao preenche o bloco de forma ordenada
	for (j = 0; qntdMarcados < 3 && k < 3; j++)
	{
		bubbleSort(heap, strlen(heap));
		bloco[j] = heap[k];
		if (strlen(str) > *numHeap)
		{
			//caso a proxima letra da frase seja maior que a ultima letra do bloco ele troca a primeira letra do heap pela letra da frase
			if (str[*numHeap] >= bloco[j])
				heap[0] = str[*numHeap];
			//caso a proxima letra da frase seja menor que a ultima letra do bloco ele armazena a letra na variavel lastHeap e aumenta o numero de letras marcadas
			else
			{
				lastHeap[qntdMarcados] = str[*numHeap];
				heap[0] = 126;
				qntdMarcados++;
			}
		}
		else
			k++;
		(*numHeap)++;
	}
	lastHeap[qntdMarcados] = '\0';
	bloco[j] = '\0';
	return bloco;
}

void abreArqs(char *modo)
{
	int i = 1;
	char str[20];
	for (i = 1; i < 4; i++)
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
	for (i = 0; i < 3; i++)
	{
		fclose(fita[i]);
	}
}

void ordenaFinal()
{
	int j, i, k, l, pointer[3] = {0, 0, 0}, fitaMenorCh = 2;
	char menorCh = 'z', ch;
	rewind(fita[0]);
	for (j = 0; j < 27; j++)
	{
		menorCh = 'z';
		for (i = 0; i < 3; i++)
		{
			if (pointer[i] < 9)
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

			fputc(menorCh, fita[0]);
	}
}

void intercalaFitas()
{
	int j, i, k, l, pointer[3] = {0, 0, 0}, fitaMenorCh = 2, initialPointer = 0;
	char menorCh = 'z', ch;
	for (k = 0; k < 3; k++)
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
	char chLido, frase[28], bloco[28], lastHeap[4] = "";
	int i = 0;
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
	i = 0;
	while (i <= strlen(frase))
	{
		strcpy(bloco, geraBloco(frase, lastHeap, &i));
		fputs(bloco, fita[0]);
		fputc(' ', fita[0]);
	}
	// intercalaFitas();
	// ordenaFinal();
	fechaArqs();
	return 0;
}

// INTERCALACAOBALANCEADA
