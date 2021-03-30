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

int comparaIdade(const void * a, const void * b){
    if((*(t_atleta*)a).idade == (*(t_atleta*)b).idade){
        return 0; //iguais
    }else{
        if((*(t_atleta*)a).idade < (*(t_atleta*)b).idade){
            return -1; //menor
        }else{
            return 1; //maior
        }
    }
}

void escrever(t_atleta atleta[]){

    int i;
    //int tam_vet = sizeof(atleta) - 1; // tamanho do vetor
    FILE * arq;
    // abre o arquivo para escrita no modo append (adiciona ao final)
    arq = fopen("dados.txt", "ab");
    if(arq != NULL){
        for(i = 0; i < 4; i++){
            // escreve cada elemento do vetor no arquivo
            fwrite(&atleta[i], sizeof(t_atleta), 1, arq);
        }
        fclose(arq); // aborta o programa
    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1); // aborta o programa
    }
}

void limpar_buffer() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int main(){
    
    t_atleta atleta;
    FILE * arq = fopen("dados.txt", "wb");
    if(arq == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    
    
    
    for(int i = 0; i<4; i++){
        printf("Escreva o nome do atleta: ");
        scanf("%s", &*atleta.nome);
        limpar_buffer();
        fprintf(arq, "%s", atleta.nome[i]);
        printf("Escreva o esporte do atleta: ");
        scanf("%c", &*atleta.esporte);
        limpar_buffer();
        fprintf(arq, "%s", atleta.esporte[i]);
        printf("Escreva a idade do atleta: ");
        scanf("%i", &atleta.idade);
        limpar_buffer();
        fprintf(arq, "%i", atleta.idade[i]);
        printf("Escreva a altura do atleta: ");
        scanf("%f", &atleta.altura);
        limpar_buffer();
        //fwrite(&atleta.altura[i], sizeof(t_atleta), i, arq);
    }
    
    
  return 0;
}
