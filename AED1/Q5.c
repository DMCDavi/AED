#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[10][10], i, j, soma = 0, soma_ant = 0, magico = 1;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < 10 && magico == 1; i++)
    {
        for (j = 0; j < 10; j++)
        {
            soma += matriz[i][j];
        }
        if (soma_ant != 0 && soma != soma_ant)
        {
            magico = 0;
            printf("Nao eh um quadrado magico\n");
            break;
        }
        else
        {
            soma_ant = soma;
            soma = 0;
        }
    }
    for (i = 0; i < 10 && magico == 1; i++)
    {
        for (j = 0; j < 10; j++)
        {
            soma += matriz[j][i];
        }
        if (soma_ant != 0 && soma != soma_ant)
        {
            magico = 0;
            printf("Nao eh um quadrado magico\n");
            break;
        }
        else
        {
            soma_ant = soma;
            soma = 0;
        }
    }
    for (j = 0; j < 10 && magico == 1; j++)
    {
        soma += matriz[j][j];
    }
    if (soma_ant != 0 && soma != soma_ant && magico == 1)
    {
        magico = 0;
        printf("Nao eh um quadrado magico\n");
    }
    else
    {
        soma_ant = soma;
        soma = 0;
    }
    for (j = 9; j >= 0 && magico == 1; j--)
    {
        soma += matriz[j][j];
    }
    if (soma_ant != 0 && soma != soma_ant && magico == 1)
    {
        magico = 0;
        printf("Nao eh um quadrado magico\n");
    }

    if (magico == 1)
        printf("Eh um quadrado magico\n");
    return 0;
}