#include <stdlib.h>
#include <stdio.h>
#include "b_tree.h"

int main()
{
    TipoRegistro x;
    TipoPagina *D;

    Inicializa(&D);
    printf("Chave: ");
    scanf("%ld%*[^\n]", &x.Chave);
    Insere(x, &D);
    
    return 0;
}