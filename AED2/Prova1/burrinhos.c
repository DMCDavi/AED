#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *file;
    changeFile(file);
    return 0;
}

void changeFile(FILE *file)
{
    file = fopen("Poema.txt", "r");
    if (file == NULL)
    {
        printf("Error: the file could not be opened\n");
        printf("Closing the system...\n");
        exit(1);
    }
    else
    {
        char str[30];
        int burrinhos = 0;
        do
        {
            fscanf(file, "%s", str);
            if (strcmp(str, "burrinho") == 0)
                burrinhos += 1;
        } while (strcmp(str, "ler.)") != 0);
        printf("Burrinhos: %d\n", burrinhos);
        fclose(file);
    }
}