#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

FILE *fita[7];

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
	for (i = 1; i < 8; i++)
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
	for (i = 0; i < 7; i++)
	{
		fclose(fita[i]);
	}
}

/*char ordenarEmFitas(FILE *fita)
{
}
*/
/*void rewindFitas(FILE *fita)
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		rewind(fita[i]);
	}
}
*/
int main()
{

	char ch, frase[28], aux[3];
	int i, j;
	abreArqs("w");
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	for (i = 0; i < 27; i++)
	{
		if (kbhit)
		{
			ch = getch();
			printf("%c", ch);
			frase[i] = ch;
		}
	}
	frase[i] = '\0';
	printf("\n");
	printf("%s", frase);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fputs(geraBloco(frase, i == 0 ? j : j + 3), fita[j]);
		}
	}
	//rewind(fita[0]);
	//printf("%c", fita[0]);
	fechaArqs();
	abreArqs("r");
	
	for(i = 0; i < 3; i++){
		fseek(fita[i], 0, SEEK_SET);
   		aux[i] = fgetc(fita[i]);
		printf("\n%c",aux[i]);
			
	}
	
	fechaArqs();
	abreArqs("w");
		
	for(i = 0; i<3;i++){
		fputs(aux, fita[i]);
	}
	

	
	
	return 0;
}
