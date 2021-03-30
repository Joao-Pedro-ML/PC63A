#include <stdio.h>
#include <stdlib.h>

typedef struct atleta{
    char nome[30];
    char esporte[30];
    int idade;
    float altura;
}t_atleta;

int comparaNome(const void * a, const void * b){
    if((*(t_atleta*)a).nome == (*(t_atleta*)b).nome){
        return 0; //iguais
    }else{
        if((*(t_atleta*)a).nome < (*(t_atleta*)b).nome){
            return -1; //menor
        }else{
            return 1; //maior
        }
    }
}

void limpar_buffer() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int main(){
    
    t_atleta atleta[4];
    FILE * arq = fopen("arquivo.txt", "a");
    if(arq == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    
    for(int i = 0; i<1; i++){
        printf("Escreva o nome do atleta: ");
        scanf("%s", &*atleta[i].nome);
        limpar_buffer();
        fprintf(arq, "%s", atleta[i].nome);
        printf("Escreva o esporte do atleta: ");
        scanf("%c", &*atleta[i].esporte);
        limpar_buffer();
        fprintf(arq, "%s", atleta[i].esporte);
        printf("Escreva a idade do atleta: ");
        scanf("%i", &atleta[i].idade);
        limpar_buffer();
        fprintf(arq, "%i", atleta[i].idade);
        printf("Escreva a altura do atleta: ");
        scanf("%f", &atleta[i].altura);
        limpar_buffer();
        fwrite(&atleta[i].altura, sizeof(t_atleta), i, arq);
    }
    
    
  return 0;
}
