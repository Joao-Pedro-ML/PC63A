#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
  char cod[4];
  int rrn;
  char nome[26];
  char endereco[26];
  char cidade[21];
  char estado[4];
}cadastro;

void formataString(char *string, int size){
  for(int i = 0; i < size-1; i++){
    if(string[i] ==' ' && string[i+1] == ' '){
      string[i] = '\0';
      return;
    }
  }
  if(string[size-2]==' ' || string[size-2]=='\n')
    string[size-2]='\0';
}// Funcao para formatar as strings do arquivo original

int comparaIndice(const void * a, const void * b){
  const char* x = (const char*)a;
  const char* y = (const char*)b;
  return strcmp(x, y);
}//Funcao auxiliar do qsort() para comparar os indices

int comparaNome(const void *a, const void *b){ 
    return strcmp (((cadastro *)a)->nome,((cadastro *)b)->nome);
}//funcao auxiliar do qsort() pata comparar os nomes

int comparaCidade(const void *a, const void *b){ 
    return strcmp (((cadastro *)a)->cidade,((cadastro *)b)->cidade);
}//funcao auxiliar do qsort() pata comparar as cidades

void ler(){
  FILE * arq = fopen("cadastro.txt", "r");
  if(arq == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  cadastro cad[500];
  for(int i = 0; i<500; i++){
    fgets(cad[i].cod, 4, arq);
    fgets(cad[i].nome, 26, arq);
    fgets(cad[i].endereco, 26, arq);
    fgets(cad[i].cidade, 21, arq);
    fgets(cad[i].estado, 4, arq);
  }
  fclose(arq);
}

void op1(){
  FILE * arq = fopen("cadastro.txt", "r");
  FILE * arq2 = fopen("op1.txt", "w");
  if(arq == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  if(arq2 == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  
  cadastro cad[500];

  for(int i = 0; i<500; i++){
    fgets(cad[i].cod, 4, arq);
    fgets(cad[i].nome, 26, arq);
    fgets(cad[i].endereco, 26, arq);
    fgets(cad[i].cidade, 21, arq);
    fgets(cad[i].estado, 4, arq);
  }

  qsort(cad, 500, sizeof(cadastro), comparaNome);
  char aux[80];
  for(int i = 0; i<500; i++){
    sprintf(aux, "%s %s %s %s %s", cad[i].cod,  cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    sprintf(aux, "%s %s %s %s %s", cad[i].cod, cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);

    fprintf(arq2, "%s", aux);
  }

  fclose(arq);
  fclose(arq2);
}


void op2(){
  FILE * arq = fopen("cadastro.txt", "r");
  FILE * arq3 = fopen("op2.txt", "w");
  if(arq == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  if(arq3 == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  
  cadastro cad[500];

  for(int i = 0; i<500; i++){
    fgets(cad[i].cod, 4, arq);
    fgets(cad[i].nome, 26, arq);
    formataString(cad[i].nome, 26);
    fgets(cad[i].endereco, 26, arq);
    formataString(cad[i].endereco, 26);
    fgets(cad[i].cidade, 21, arq);
    formataString(cad[i].cidade, 21);
    fgets(cad[i].estado, 4, arq);
    formataString(cad[i].estado, 4);
  }

  qsort(cad, 500, sizeof(cadastro), comparaNome);

  char aux[80];

  for(int i = 0; i<500; i++){
    sprintf(aux, "%s|%s|%s|%s|%s|", cad[i].cod,  cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    sprintf(aux, "%s|%s|%s|%s|", cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);

    fprintf(arq3, "%s \n", aux);
  }

  fclose(arq);
  fclose(arq3);
}

void indicePrimario(){
  
  FILE * arq = fopen("cadastro.txt", "r");
  FILE * arq4 = fopen("indicep.txt", "w");
  if(arq == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  if(arq4 == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  
  cadastro cad[500];

  for(int i = 0; i<500; i++){
    fgets(cad[i].cod, 4, arq);
    fgets(cad[i].nome, 26, arq);
    formataString(cad[i].nome, 26);
    fgets(cad[i].endereco, 26, arq);
    formataString(cad[i].endereco, 26);
    fgets(cad[i].cidade, 21, arq);
    formataString(cad[i].cidade, 21);
    fgets(cad[i].estado, 4, arq);
    formataString(cad[i].estado, 4);
  }

  char aux[80];

  qsort(cad, 500, sizeof(cadastro), comparaIndice);
  int a = 0;
  for(int i = 0; i<500; i++){
    sprintf(aux, "%s|%s|%s|%s|%s|", cad[i].cod,  cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    cad[0].rrn = 0;
    cad[i].rrn = strlen(aux);
    fprintf(arq4, "%s   %i\n", cad[i].cod, cad[i].rrn);
  }

  fclose(arq);
  fclose(arq4);
}

void indicesSecundarios(){

  FILE * arq = fopen("cadastro.txt", "r");
  FILE * arq5 = fopen("indSecNome.txt", "w");
  FILE * arq6 = fopen("indSecCid.txt", "w");
  if(arq == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  if(arq5 == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  if(arq6 == NULL){
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  
  cadastro cad[500];

  for(int i = 0; i<500; i++){
    fgets(cad[i].cod, 4, arq);
    fgets(cad[i].nome, 26, arq);
    formataString(cad[i].nome, 26);
    fgets(cad[i].endereco, 26, arq);
    formataString(cad[i].endereco, 26);
    fgets(cad[i].cidade, 21, arq);
    formataString(cad[i].cidade, 21);
    fgets(cad[i].estado, 4, arq);
    formataString(cad[i].estado, 4);
  }

  char aux[80];

  qsort(cad, 500, sizeof(cadastro), comparaNome);
  int a=0;

  for(int i = 1; i<501; i++){
    sprintf(aux, "%s|%s|%s|%s|%s|", cad[i].cod,  cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    sprintf(aux, "%s|%s|%s|%s|", cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    a = strlen(aux);
    cad[i].rrn = cad[i-1].rrn+a;
    fprintf(arq5, "%s   %i\n", cad[i].nome, cad[i].rrn);
  }

  char aux2[80];

  qsort(cad, 500, sizeof(cadastro), comparaCidade);
  
  for(int i = 1; i<500; i++){
    sprintf(aux2, "%s|%s|%s|%s|%s|", cad[i].cod,  cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    sprintf(aux2, "%s|%s|%s|%s|", cad[i].nome,  cad[i].endereco,  cad[i].cidade, cad[i].estado);
    a = strlen(aux2);
    cad[i].rrn = cad[i-1].rrn+a;
    fprintf(arq6, "%s  %s  %i\n", cad[i].cidade, cad[i].cod, cad[i].rrn);
  }

  fclose(arq);
  fclose(arq5);
  fclose(arq6);
}

void busca(int inicio, int fim, char *chave){
  int meio;
  cadastro cad[500];
  while(inicio<=fim){
    meio = floor((inicio+fim)/2);
    
  }
}

 int main(void) {

  int opcao = 0;
  char nome;
  for(int i=0;i<500;i++){
    if(i<i+1){
      printf("O arquivo de indice primario ja existe\n");
    }else{
      indicePrimario();
      printf("O arquivo de indice primario foi criado\n");
    }//else
  }//for
  do{
    indicesSecundarios();
    printf("=========Amigos do Apolônio==========\n");
    printf("1 - Listar todos os dados dos amigos:\n");
    printf("2 - Pesquisar por nome:\n");
    printf("3 - Pesquisar por cidade:\n");
    printf("4 - Sair do programa:\n");
    scanf("%i", &opcao);
    switch (opcao){
    case 1:
      printf("Listando os nomes:\n");
      op1();
      break;
    case 2:
      printf("Digite o nome a ser procurado:\n");
      scanf("%s", &nome);
      break;
    case 3:
      printf("Pesquisa por cidade:\n");
      break;
    case 4:
      printf("Fim do programa!\n");
      break;
    default:
      printf("Opção inválida!\n");
      break;
    }//switch
  }while(opcao != 4);


  return 0;
}
