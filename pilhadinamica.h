#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem
{
    int data;
    struct elem *prox;
} elem;


typedef struct pilha
{
    struct elem *topo;
} pilha;


pilha *PILHA_construtor()
{
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if(p==NULL)
        exit(1);
    else
        p->topo = NULL;
    return p;
}

bool PILHA_vazia(pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

int PILHA_tamanho(pilha *p)
{
    elem *aux = p->topo;
    int tam = 0;
    while(aux!= NULL)
    {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void PILHA_exibir(pilha *p)
{
    elem *aux = p->topo;
    printf("Pilha: \"");
    while(aux!= NULL)
    {
        printf("%d ",aux->data);
        aux = aux->prox;
    }
    printf("\"\n");
}


bool PILHA_push(pilha *p, elem *dado)
{
    elem *novo = (elem*)malloc(sizeof(elem));
    novo->data = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool PILHA_pop(pilha *p, elem *dado)
{
    elem *aux;

    if (PILHA_vazia(p))
        return false;
    else
    {
        aux = p->topo;
        p->topo = aux->prox;
        dado = aux->prox->data;
        free(aux);
    }
}

int main()
{
    pilha *p = PILHA_construtor();
    int op;
    int num;
    do{
    printf("1 - POP, 2 - PUSH , 3 - SAIR: ");
    scanf("%d",&op);
    if (op == 1){
        printf("Digite um numero: ");
        scanf("%d",&num);
        PILHA_push(p,num);
        PILHA_exibir(p);
    }
    else if(op == 2){
        PILHA_pop(p,num);
        PILHA_exibir(p);
    }
    else{
        free(p);
    }
    }while(op!= 0 && op!= 3);
    return 0;
}