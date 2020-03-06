#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *V, int tam){

  int bool = 0;
  do{
    bool = 0;
    for(int i = 0;i<tam-1;i++){
      if(V[i] > V[i+1]){
        int a = V[i];
        V[i] = V[i+1];
        V[i+1] = a;
        bool = 1;
      }//if
    }//for
    tam--;
  }while (bool != 0);

}

void exibeVetor(int *V, int tam){

  for(size_t i = 0; i<tam; i++){
    printf("%i\n", V[i]);
  }

}

int main(int argc, char const *argv[]){

  int vetor[15] = {5,1,76,24,-9,80,3,12,-87,8};
  exibeVetor(vetor, 10);
  bubblesort(vetor, 10);
  printf("\n-----------------\n");
  exibeVetor(vetor, 10);

  return 0;
}
