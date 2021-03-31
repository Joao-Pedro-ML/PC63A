#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    char esporte[30];
    int idade;
    float altura;
}atleta;

int comparaAltura(const void * a, const void * b){
    if((*(atleta*)a).altura == (*(atleta*)b).altura){
        return 0; //iguais
    }else{
        if((*(atleta*)a).altura < (*(atleta*)b).altura){
            return 1; //vem depois
        }else{
            return -1; //vem antes
        }
    }
}

int comparaIdade(const void * a, const void * b){
    if((*(atleta*)a).idade == (*(atleta*)b).idade){
        return 0; //iguais
    }else{
        if((*(atleta*)a).idade < (*(atleta*)b).idade){
            return 1; //vem depois
        }else{
            return -1; //vem antes
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
  
  for(int i = 0; i < 5; i++){
    printf("%s, %s, %i, %.2f\n", at[i].nome,  at[i].esporte,  at[i].idade,  at[i].altura);
  }
  
  qsort(at, 5, sizeof(atleta), comparaIdade);
  printf("\n-------------\n");
  printf("O mais velho é: %s\n", at->nome);
  printf("\n-------------\n");
  qsort(at, 5, sizeof(atleta), comparaAltura);
  printf("O mais alto é: %s\n", at->nome);
  fclose(arq);

  return 0;
}
