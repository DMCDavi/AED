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

void changeFile(FILE *file, char name[20])
{
    file = fopen(name, "w");
    if (file == NULL)
    {
        printf("Error: the file could not be opened\n");
        printf("Closing the system...\n");
        exit(1);
    }
    else
    {
//        char grade[6][4], new_grade[4];
//        int i, num_grade;
//        for (i = 0; i < 6; i++)
//        {
//            fgets(grade[i], 4, file);
//            fseek(file, 1, SEEK_CUR);
//            printf("Grade %d: %s\n", i + 1, grade[i]);
//        }
//        printf("\nPlease, write the number of the grade you want to change: ");
//        scanf("%d", &num_grade);
//        num_grade == 1 ? rewind(file) : fseek(file, (num_grade - 1) * 4, SEEK_SET);
//        printf("Please, write the new grade: ");
//        scanf("%s", new_grade);
//        fputs(new_grade, file);
        fclose(file);
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
	printf("%s", bloco);
	return 0;
}
