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
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void criarArqs(FILE* fita[])
{
	int cont;
    fita[0] = fopen("fita1.txt", "w");
	fita[1] = fopen("fita2.txt", "w");
	fita[2] = fopen("fita3.txt", "w");
	fita[3] = fopen("fita4.txt", "w");
	fita[4] = fopen("fita5.txt", "w");
	fita[5] = fopen("fita6.txt", "w");
	for(cont=0;cont<6;cont++){
		if (fita[cont] == NULL)
	    {
	        printf("Error: the file could not be opened\n");
	        printf("Closing the system...\n");
	        exit(1);
	    }
	}
    
    
}

int main()
{
	char frase[28];
	char bloco[4];
	int cont;
	printf("Querido usuario, por favor digite um conjunto de 27 caracteres: \n");
	scanf("%s", frase);
	for(cont=0;cont<3;cont++){
		bloco[cont] = frase[cont];
	}
	bubbleSort(bloco, 3);
	FILE* pArq[6];
	criarArqs(pArq);
	return 0;
}
