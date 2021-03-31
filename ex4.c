#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    char esporte[30];
    int idade;
    float altura;
}atleta;

int comparaNome(const void * a, const void * b){
    if((*(atleta*)a).nome == (*(atleta*)b).nome){
        return 0; //iguais
    }else{
        if((*(atleta*)a).nome < (*(atleta*)b).nome){
            return -1; //menor
        }else{
            return 1; //maior
        }
    }
}

int main(){
    
    FILE *arq = NULL;
    arq = fopen("arquivo.txt", "rb");
    if(arq == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    
    atleta *at = (atleta*)malloc(5*sizeof(atleta));
    
    if (at == NULL){
        printf("Houve um erro");
        exit(1);
      }
    
  fread(at, sizeof(atleta), 5, arq);
  qsort(at, 5, sizeof(atleta), comparaNome);
  for(int i = 0; i < 5; i++)
    printf("%s, %s, %i, %.2f\n", at[i].nome,  at[i].esporte,  at[i].idade,  at[i].altura);

  fclose(arq);

  


    
  return 0;
}
