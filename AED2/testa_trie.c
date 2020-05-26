#include "ArvTrie.h"

int main()
{
    tp_no *raiz;
    //a arvore eh iniciada como nulo porque numa arvore trie o no raiz sempre devera ser nulo
    raiz = cria_no(NULL);
    insere_no_trie(raiz, "asa");
    insere_no_trie(raiz, "axe");
    insere_no_trie(raiz, "banana");
    printf("Arvore com as palavras: asa, axe e banana\n");
    imprime_arv_trie(raiz);
    remove_no_trie(&raiz, "asa");
    printf("\nArvore sem a palavra asa:\n");
    imprime_arv_trie(raiz);
    printf("\n");
    return 0;
}