#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char tp_item;

typedef struct tp_no
{
    tp_item info;
    struct tp_no *esq;
    struct tp_no *dir;
} tp_no;

typedef tp_no *tp_arvore;

tp_no *inicializa_arvore()
{
    return NULL;
}

tp_no *aloca_no()
{
    tp_no *no;
    no = (tp_no *)malloc(sizeof(tp_no));
    return no;
}

tp_no *insere_no(tp_arvore *pai, tp_item e, int direcao)
{
    tp_no *novo, *p = *pai;
    novo = aloca_no();

    novo->info = e;
    novo->esq = NULL;
    novo->dir = NULL;

    if (p != NULL)
    {
        if (direcao == 1)
            p->esq = novo;
        else if (direcao == 2)
            p->dir = novo;
    }
    else
        *pai = novo;

    return novo;
}

void pos_ordem(tp_no *p)
{
    if (p != NULL)
    {
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        printf("%c", p->info);
    }
}

int recupera_arvore(char *prefixo, char infixo[], tp_no **pai, int direcao)
{
    tp_no *novo_pai;
    int pos_cha = 0, i;
    char sub_esq[1000], sub_dir[1000];
    sub_esq[0] = '\0';
    sub_dir[0] = '\0';
    while (infixo[pos_cha] != prefixo[0] && pos_cha < strlen(infixo))
    {
        pos_cha++;
    }
    if (pos_cha > strlen(infixo))
        return 0;
    if (infixo[pos_cha] == prefixo[0])
    {
        novo_pai = insere_no(pai, prefixo[0], direcao);
        for (i = 1; i < strlen(prefixo); i++)
        {
            prefixo[i - 1] = prefixo[i];
        }
        prefixo[i - 1] = '\0';
    }
    for (i = 0; infixo[i + pos_cha + 1] != '\0'; i++)
    {
        sub_dir[i] = infixo[i + pos_cha + 1];
    }
    sub_dir[i] = '\0';
    infixo[pos_cha] = '\0';
    strcpy(sub_esq, infixo);
    if (prefixo[0] != '\0')
    {
        if (sub_esq != '\0' && strlen(sub_esq) > 0)
            recupera_arvore(prefixo, sub_esq, &novo_pai, 1);
        if (sub_esq != '\0' && strlen(sub_dir) > 0)
            recupera_arvore(prefixo, sub_dir, &novo_pai, 2);
    }
    return 1;
}

int main()
{
    tp_arvore raiz;
    char prefixo[1000], infixo[1000];
    while (scanf("%s %s", prefixo, infixo) != EOF)
    {
        raiz = inicializa_arvore();
        recupera_arvore(prefixo, infixo, &raiz, 0);
        pos_ordem(raiz);
        printf("\n");
        fflush(stdin);
    }

    return 0;
}