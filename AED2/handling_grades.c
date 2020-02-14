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
    file = fopen("grades.txt", "r+");
    if (file == NULL)
    {
        printf("Error: the file could not be opened\n");
        printf("Closing the system...\n");
        exit(1);
    }
    else
    {
        char grade[6][4], new_grade[4];
        int i, num_grade;
        for (i = 0; i < 6; i++)
        {
            fgets(grade[i], 4, file);
            fseek(file, 1, SEEK_CUR);
            printf("Grade %d: %s\n", i + 1, grade[i]);
        }
        printf("\nPlease, write the number of the grade you want to change: ");
        scanf("%d", &num_grade);
        num_grade == 1 ? rewind(file) : fseek(file, (num_grade - 1) * 4, SEEK_SET);
        printf("Please, write the new grade: ");
        scanf("%s", new_grade);
        fputs(new_grade, file);
        fclose(file);
    }
}