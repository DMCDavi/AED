#include <stdio.h>
#include <stdlib.h>

void troca(int *pontx, int *ponty)
{
    int *aux;
    aux = (int *)malloc(sizeof(int));
    *aux = *pontx;
    *pontx = *ponty;
    *ponty = *aux;
    free(aux);
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    troca(&x, &y);
    printf("%d %d", x, y);
    return 0;
}