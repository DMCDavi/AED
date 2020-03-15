#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

char *geraBloco(char *str, char *lastHeap, unsigned int *posChStr)
{
	//por medidas de seguranca, se o numero passado por parametro for maior que o tamanho da string a funcao retorna NULL
	if (*posChStr > strlen(str))
		return NULL;
	char heap[4], bloco[28];
	int posChHeap, posChBloco, qntdMarcados = 0;
	//caso essa funcao seja chamada pela primeira vez, o heap vai ser as tres primeiras letras da frase
	if (*posChStr == 0)
	{
		for (posChHeap = 0; strlen(str) > *posChStr && posChHeap < 3; (*posChStr)++)
			heap[posChHeap++] = str[*posChStr];
		heap[posChHeap] = '\0';
	}
	//caso essa funcao nao seja chamada pela primeira vez, o heap vai ser uma string composta pelos caracteres marcados na ultima ordenacao
	else
		strcpy(heap, lastHeap);
	posChHeap = 0;
	//essa funcao preenche o bloco de forma ordenada
	for (posChBloco = 0; qntdMarcados < 3 && posChHeap < 3; posChBloco++)
	{
		bubbleSort(heap, strlen(heap));
		bloco[posChBloco] = heap[posChHeap];
		if (strlen(str) > *posChStr)
		{
			//caso a proxima letra da frase seja maior que a ultima letra do bloco ele troca a primeira letra do heap pela letra da frase
			if (str[*posChStr] >= bloco[posChBloco])
				heap[0] = str[*posChStr];
			//caso a proxima letra da frase seja menor que a ultima letra do bloco ele armazena a letra na variavel lastHeap e aumenta o numero de letras marcadas
			else
			{
				lastHeap[qntdMarcados] = str[*posChStr];
				heap[0] = 126;
				qntdMarcados++;
			}
		}
		else
			posChHeap++;
		(*posChStr)++;
	}
	lastHeap[qntdMarcados] = '\0';
	bloco[posChBloco] = '\0';
	return bloco;
}

void abreFitas(FILE *fitas[], char *modo)
{
	int numFita = 1;
	char str[20];
	for (numFita = 1; numFita < 4; numFita++)
	{
		sprintf(str, "fita%d.txt", numFita);
		fitas[numFita - 1] = fopen(str, modo);
		if (fitas[numFita - 1] == NULL)
		{
			printf("Error: the file could not be opened\n");
			printf("Closing the system...\n");
			exit(1);
		}
	}
}

void fechaFitas(FILE *fitas[])
{
	int numFita;
	for (numFita = 0; numFita < 3; numFita++)
	{
		fclose(fitas[numFita]);
	}
}

int main()
{
	FILE *fita[3];
	char chLido, frase[28], bloco[10][28], lastHeap[4] = "";
	unsigned int posChFrase = 0, numFita = 0, numBloco, qntdBlocos = 0;
	abreFitas(fita, "w+");
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	while (1)
	{
		//kbhit é uma funcao da biblioteca conio.h que retorna true toda vez que o usuario pressiona uma tecla no teclado
		if (kbhit)
		{
			chLido = getch();
			//caso o usuario pressione a tecla ENTER ele sai do loop
			if (chLido == 13)
				break;
			//enquanto a quantidade de caracteres que o usuario digita é menor que 27, o sistema printa na tela a tecla e armazena na variavel frase
			if (posChFrase < 27)
			{
				printf("%c", chLido);
				frase[posChFrase] = chLido;
				posChFrase++;
			}
		}
	}
	frase[posChFrase] = '\0';
	printf("\n");
	posChFrase = 0;
	//gera os blocos e armazena cada um na variavel bloco
	for (qntdBlocos = 0; posChFrase <= strlen(frase); qntdBlocos++)
		strcpy(bloco[qntdBlocos], geraBloco(frase, lastHeap, &posChFrase));
	//insere metade dos blocos no primeiro arquivo e a outra metade no segundo
	for (numBloco = 0; numBloco < qntdBlocos; numBloco++)
	{
		if (numBloco == (qntdBlocos / 2) + (qntdBlocos % 2))
			numFita++;
		fputs(bloco[numBloco], fita[numFita]);
		fputc(' ', fita[numFita]);
	}
	fechaFitas(fita);
	return 0;
}

//frase de teste: INTERCALACAOBALANCEADA
