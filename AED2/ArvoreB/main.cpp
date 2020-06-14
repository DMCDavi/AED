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
  ////CODIGO DE SOUSSA PARA TESTAR A BIBLIOTECA DA ARVORE B
  // TipoRegistro x;
  // TipoPagina *D;
  // Inicializa(&D);
  // printf("Chave: ");
  // scanf("%ld%*[^\n]", &x.Chave);
  // printf("Descricao: ");
  // scanf("%s%*[^\n]", x.descricao);
  // printf("Custo: ");
  // scanf("%f%*[^\n]", &x.custo);
  // Insere(x, &D);
  // Imprime(D);

  setlocale(LC_ALL, "Portuguese");
  char linha[500], *tag;

  FILE *arq_xml;
  arq_xml = fopen("project_data.xml", "r");
  if (arq_xml == NULL)
  {
    printf("Error: the file could not be opened\n");
    printf("Closing the system...\n");
    exit(1);
  }

  //Le todas as linhas do arquivo xml
  while (fgets(linha, sizeof(linha), arq_xml) != NULL)
  {
    if (remove_tags(linha, "Cod"))
      printf("%s", &linha);
    if (remove_tags(linha, "Descr"))
      printf("%s", &linha);
    if (remove_tags(linha, "Custo"))
      printf("%s", &linha);
  }

  fclose(arq_xml);

  return 0;
}