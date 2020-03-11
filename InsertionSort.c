#include <stdio.h>
#include <stdlib.h>

/**
  *\brief
*/
void InsertionSort(int *V, int tam){
  int aux;
  for(int i = 1; i < tam; i++){
    aux = V[i];
    if(aux < V[i-1]){
      for(int j = i; j > 0; j--){
        if(aux < V[j-1]){
          V[j] = V[j-1];
          V[j-1] = aux;
        }//if
      }//for
    }//if
  }//for
}//InserctionSort

/**
  *\brief Exibe um vetor
  *
  *\param V ponteiro para o vetor a ser exibido
  *\param tam para o tamanho do vetor
*/
void exibeVetor(int *V, int tam){

    for(size_t i = 0; i<tam; i++){
        printf("%i\n", V[i]);
    }

}

int main(int argc, char const *argv[]){

  int vetor[10] = {11,20,-9,2,-5,32,4,12,95,6};
  exibeVetor(vetor, 10);
  InsertionSort(vetor, 10);
  printf("\n-----------------\n");
  exibeVetor(vetor, 10);

  return 0;
}
