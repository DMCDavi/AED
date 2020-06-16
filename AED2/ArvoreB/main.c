#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include "b_tree.h"

//Remove as tags da linha do arquivo
bool remove_tags(char *line, char *tag_name)
{
  char *match;
  int tag_len;
  char open_tag[10] = "<", close_tag[10] = "</";
  //Coloca os marcadores < > no nome da tag de abertura
  strcat(open_tag, tag_name);
  strcat(open_tag, ">");
  tag_len = strlen(open_tag);
  //Procura a tag na string e armazerna a substring que se encontra a partir da primeira ocorrencia da tag
  if ((match = strstr(line, open_tag)))
  {
    strcpy(line, match);
    //Apaga o tag de abertura da linha
    if ((match = strstr(line, open_tag)))
    {
      *match = '\0';
      strcat(line, match + tag_len);
    }
    //Coloca os marcadores </ > no nome da tag de fechamento
    strcat(close_tag, tag_name);
    strcat(close_tag, ">");
    tag_len = strlen(close_tag);
    //Apaga o tag de fechamento da linha
    if ((match = strstr(line, close_tag)))
    {
      *match = '\0';
      strcat(line, match + tag_len);
    }
    return true;
  }
  return false;
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  char linha[500], opt;
  FILE *arq_xml;
  float total_cost = 0;
  TipoRegistro item;
  TipoPagina *D;

  printf("Lendo arquivo xml...\n");
  //Abrindo o arquivo xml
  arq_xml = fopen("project_data.xml", "r");
  if (arq_xml == NULL)
  {
    printf("Erro: houve uma falha ao tentar abrir o arquivo\n");
    printf("Fechando o sistema...\n");
    exit(1);
  }
  Inicializa(&D);
  printf("Inserindo valores do arquivo na árvore B...\n");
  //Le todas as linhas do arquivo xml e escreve seus valores na Ã¡rvore B
  while (fgets(linha, sizeof(linha), arq_xml) != NULL)
  {
    if (remove_tags(linha, "Cod"))
    {
      int cod = atoi(linha);
      item.Chave = cod;
    }
    if (remove_tags(linha, "Descr"))
    {
      strcpy(item.descricao, "\0");
      strcpy(item.descricao, linha);
    }
    if (remove_tags(linha, "Custo"))
    {
      float cost = atof(linha);
      item.custo = cost;
      total_cost += cost;
      Insere(item, &D);
    }
  }
  printf("Itens inseridos com sucesso\n");
  printf("Deseja buscar por alguma etapa? [s/n]\n");
  scanf("%c", &opt);
  if (opt == 's')
  {
    TipoRegistro item_busca;
    printf("Digite uma chave para fazer a busca: \n");
    scanf("%d", &item_busca.Chave);
    Pesquisa(&item_busca, D);
  }
  system("PAUSE");
  printf("\nBusca terminada! Imprimindo dados da árvore...\n");
  Imprime(D);
  printf("\n - PREÇO TOTAL: %.2f - \n", total_cost);
  fclose(arq_xml);

  return 0;
}
