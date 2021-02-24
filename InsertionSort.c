#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibeVetor(int *V, int tam){

  for(size_t i = 0; i<tam; i++){
      printf("%i\n", V[i]);
  }

}

void SelectionSort(int* V, int a){
    int menor, troca;
    for (int i = 0; i<a; i++) {
        menor = i;
        for (int j=i+1; j<a; j++) {
            if(V[j]<V[menor]){
                menor = j;
            }//if
        }//for
        if (i!=menor) {
            troca=V[i];
            V[i] = V[menor];
            V[menor]= troca;
        }//if
    }//for
}//selectionsort

int main(int argc, char const *argv[]){
    
    int vetor[10];
    for(int i = 0; i<10; i++){
        vetor[i] = rand()%100;
    }//for
    exibeVetor(vetor, 10);
    SelectionSort(vetor, 10);
    printf("\n-----------------\n");
    exibeVetor(vetor, 10);
    
    return 0;
}
