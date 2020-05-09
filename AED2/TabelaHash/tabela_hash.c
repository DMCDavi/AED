#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaenc.h"

//funcao hash de resto de divisão para string
int mod_hash(char key[])
{
    int index, pos_key, soma = 0;
    //percorre a string e soma os valores da tabela ASCII de cada char
    for (pos_key = 0; pos_key < strlen(key); pos_key++)
        soma += key[pos_key];
    //o index sera um numero entre 0 e 99
    index = soma % 100;
    return index;
}

int main()
{
    LISTA *tupla_hash[100];
    USUARIO funcionario;
    int num_funcionario, index;
    char cpf_aux[12], nome_aux[100];

    //cria as 100 listas que irao compor cada linha da tabela hash
    for (index = 0; index < 100; index++)
        tupla_hash[index] = cria_lista();
    printf("CADASTRE SEUS FUNCIONARIOS!!\n");

    //escaneia 100 CPF's ou ate que o usuario digite o numero 0
    for (num_funcionario = 0; num_funcionario < 100; num_funcionario++)
    {
        printf("Digite o CPF do funcionario %d: ", num_funcionario + 1);
        scanf("%s", cpf_aux);
        if (strcmp(cpf_aux, "0") == 0)
            break;
        printf("Digite o nome do funcionario %d: ", num_funcionario + 1);
        scanf("%s", nome_aux);
        if (strcmp(nome_aux, "0") == 0)
            break;
        //acha o index da tabela de acordo com a funcao hash
        index = mod_hash(cpf_aux);
        strcpy(funcionario.cpf, cpf_aux);
        strcpy(funcionario.nome, nome_aux);
        //insere na lista referente a posicao encotrada pela funcao hash
        insere_listase(tupla_hash[index], funcionario);
    }

    //loop para encontrar qualquer funcionario a partir do CPF
    while (1)
    {
        printf("Digite o CPF de um usuario cadastrado que voce deseja encontrar: ");
        scanf("%s", cpf_aux);
        if (strcmp(cpf_aux, "0") == 0)
            break;
        index = mod_hash(cpf_aux);
        //busca na lista especificada pelo index se existe algum funcionario com O CPF digitado
        busca_listase(tupla_hash[index], cpf_aux);
    }

    return 0;
}