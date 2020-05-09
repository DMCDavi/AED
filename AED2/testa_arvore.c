#include "arvore.h"

int main()
{
    tp_arvore raiz;
    raiz = inicializa_arvore();
    tp_no *no;
    if (arvore_vazia(raiz))
        printf("Vazia\n");
    else
        printf("Nao Vazia\n");
    insere_no(&raiz, 15);
    insere_no(&raiz, 10);
    insere_no(&raiz, 17);
    insere_no(&raiz, 20);
    insere_no(&raiz, 22);
    printf("Pre-ordem:\n");
    pre_ordem(raiz);
    printf("Em-ordem:\n");
    em_ordem(raiz);
    printf("Pos-ordem:\n");
    pos_ordem(raiz);
    no = busca_no_rec(raiz, 17);
    if (no)
        printf("Valor 17 encontrado no endereco %x\n", no);
    else
        printf("Valor 17 nao encontrado\n");
    printf("Quantidade de nos da arvore: %d\n", qtde_nos(raiz));
    printf("Altura da arvore: %d\n", altura_arvore(raiz));
    remove_no(&raiz, 22);
    printf("Quantidade de nos da arvore: %d\n", qtde_nos(raiz));
    printf("Altura da arvore: %d\n", altura_arvore(raiz));
    destroi_arvore(&raiz);
    return 0;
}
