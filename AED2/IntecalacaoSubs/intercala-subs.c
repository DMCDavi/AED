/*
As funcoes swap, bubbleSort, abreFitas e fechaFitas foram aproveitadas do codigo anterior
Davi fez as funcoes main e gerBloco
Grhamm tentou fazer a funcao intercalaFitas
Davi e João fizeram a funcao intercalaFitas
João fez a funcao rewindFitas
*/

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
		if (heap[posChHeap] != 126 && heap[posChHeap] != '\0')
		{
			bloco[posChBloco] = heap[posChHeap];
			if (*posChStr < strlen(str))
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
				(*posChStr)++;
			}
			else
				posChHeap++;
		}
		else
			break;
	}
	lastHeap[qntdMarcados] = '\0';
	bloco[posChBloco] = '\0';
	if (strlen(lastHeap) == 0)
		(*posChStr)++;

	return bloco;
}

//struct que armazena o primeiro char de um arquivo e o index desse arquivo
typedef struct chFita
{
	char ch;
	int numFita;
} CHARFITA;

void intercalaFitas(FILE *fitas[])
{
	int posFita, posFitaVazia, posCh;
	char chLido, nomeFita[30];
	CHARFITA chFita[2];
	chFita[0].ch = 32;
	chFita[0].numFita = 0;
	chFita[1].ch = 32;
	chFita[1].numFita = 0;
	rewindFitas(fitas);

	//loop que realiza todas as intercalacoes ate nao ter mais blocos para intercalar
	while (1)
	{
		posCh = 0;
		//percorre todos os arquivos, armazena o primeiro caracter do bloco de cada arquivo e salva o index do arquivo que esta vazio
		for (posFita = 0; posFita < 3; posFita++)
		{
			chLido = fgetc(fitas[posFita]);
			//caso o char lido seja o final do arquivo o index dele sera salvo pois esse eh o arquivo vazio em que os novos blocos ficarao armazenados
			if (chLido == EOF || chLido == 0)
				posFitaVazia = posFita;
			//caso o char lido nao seja um espaco, seu valor eh armazenado
			else if (chLido != 32)
			{
				chFita[posCh].ch = chLido;
				chFita[posCh].numFita = posFita;
				posCh++;
			}
		}
		//caso o valor de posCh nao mude, quer dizer que nenhum novo caracter foi encontrado, entao o resultado ja foi encontrado
		if (posCh == 0)
			break;
		//loop que preenche novos blocos no arquivo vazio
		//esse loop percorre o arquivo ate o EOF
		while (chFita[0].ch != EOF && chFita[0].ch != 0 && chFita[1].ch != EOF && chFita[0].ch != 0)
		{
			//loop que faz as comparacoes entre os caracteres e armazena o de menor valor no arquivo vazio
			//esse loop percorre apenas os blocos ate o espaço
			while ((chFita[0].ch != 32 && chFita[0].ch != EOF && chFita[0].ch != 0) || (chFita[1].ch != 32 && chFita[1].ch != EOF && chFita[1].ch != 0))
			{
				if (chFita[0].ch != 32 && chFita[0].ch != EOF && chFita[0].ch != 0 && chFita[1].ch != 32 && chFita[1].ch != EOF && chFita[1].ch != 0)
				{
					if (chFita[0].ch <= chFita[1].ch)
					{
						fputc(chFita[0].ch, fitas[posFitaVazia]);
						chFita[0].ch = fgetc(fitas[chFita[0].numFita]);
					}
					else
					{
						fputc(chFita[1].ch, fitas[posFitaVazia]);
						chFita[1].ch = fgetc(fitas[chFita[1].numFita]);
					}
				}
				else
				{
					//caso nao tenha mais caracteres num bloco, o algoritmo preenche o arquivo vazio com os caracteres restantes no outro bloco
					if ((chFita[0].ch == 32 || chFita[0].ch == EOF || chFita[0].ch == 0) && chFita[1].ch != 32 && chFita[1].ch != EOF && chFita[1].ch != 0)
					{
						fputc(chFita[1].ch, fitas[posFitaVazia]);
						chFita[1].ch = fgetc(fitas[chFita[1].numFita]);
					}
					else if ((chFita[1].ch == 32 || chFita[1].ch == EOF || chFita[1].ch == 0) && chFita[0].ch != 32 && chFita[0].ch != EOF && chFita[0].ch != 0)
					{
						fputc(chFita[0].ch, fitas[posFitaVazia]);
						chFita[0].ch = fgetc(fitas[chFita[0].numFita]);
					}
				}
			}
			//caso nenhum dos dois arquivos tenha chegado no final, preenche o arquivo vazio com um espaco para separar os blocos e parte para a execucao de outro bloco
			if (chFita[0].ch != EOF && chFita[0].ch != 0 && chFita[1].ch != EOF && chFita[1].ch != 0)
			{
				fputc(' ', fitas[posFitaVazia]);
				chFita[0].ch = fgetc(fitas[chFita[0].numFita]);
				chFita[1].ch = fgetc(fitas[chFita[1].numFita]);
			}
			//se pelo menos um arquivo chegar ao final, o algoritmo limpa esse arquivo
			else
			{
				for (posCh = 0; posCh < 2; posCh++)

					if (chFita[posCh].ch == EOF || chFita[posCh].ch == 0)
					{
						fclose(fitas[chFita[posCh].numFita]);
						sprintf(nomeFita, "fita%d.txt", chFita[posCh].numFita + 1);
						fopen(nomeFita, "w+");
					}
			}
		}
		rewind(fitas[posFitaVazia]);
	}
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
void rewindFitas(FILE *fitas[])
{
	int numFita;
	for (numFita = 0; numFita < 3; numFita++)
	{
		rewind(fitas[numFita]);
	}
}

int main()
{
	FILE *fita[3];
	char chLido, frase[28], bloco[10][28], lastHeap[4] = "";
	unsigned int posChFrase = 0, numFita = 0, numBloco, qntdBlocos = 0, i;
	abreFitas(fita, "w+");
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	while (1)
	{
		//kbhit eh uma funcao da biblioteca conio.h que retorna true toda vez que o usuario pressiona uma tecla no teclado
		if (kbhit)
		{
			chLido = getch();
			//caso o usuario pressione a tecla ENTER ele sai do loop
			if (chLido == 13)
				break;
			//enquanto a quantidade de caracteres que o usuario digita eh menor que 27, o sistema printa na tela a tecla e armazena na variavel frase
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
	{
		strcpy(bloco[qntdBlocos], geraBloco(frase, lastHeap, &posChFrase));
	}
	printf("PRIMEIROS BLOCOS: \n");
	//insere metade dos blocos no primeiro arquivo e a outra metade no segundo
	for (numBloco = 0; numBloco < qntdBlocos; numBloco++)
	{
		printf("%s\n", bloco[numBloco]);
		if (numBloco == (qntdBlocos / 2) + 1)
			numFita++;
		fputs(bloco[numBloco], fita[numFita]);
		if (numBloco + 1 < qntdBlocos && numBloco + 1 != (qntdBlocos / 2) + 1)
			fputc(' ', fita[numFita]);
	}
	if (qntdBlocos > 1)
		intercalaFitas(fita);

	fechaFitas(fita);
	return 0;
}

//frase de teste: INTERCALACAOBALANCEADA