#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    char esporte[30];
    int idade;
    float altura;
}atleta;

void limpar_buffer() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int main(){
    
    FILE *arq = NULL;
    arq = fopen("arquivo.txt", "wb");
    if(arq == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    
    atleta *at = (atleta*)malloc(5*sizeof(atleta));
    
    if (at == NULL){
        printf("Houve um erro");
        exit(1);
      }
    
    for(int i = 0; i<5; i++){
        printf("Escreva o nome do atleta: ");
        scanf("%s", at[i].nome);
        limpar_buffer();
        printf("Escreva o esporte do atleta: ");
        scanf("%s", at[i].esporte);
        limpar_buffer();
        printf("Escreva a idade do atleta: ");
        scanf("%i", &at[i].idade);
        limpar_buffer();
        printf("Escreva a altura do atleta: ");
        scanf("%f", &at[i].altura);
        limpar_buffer();
    }
    fwrite(at, sizeof(atleta), 5, arq);

    
  return 0;
}
