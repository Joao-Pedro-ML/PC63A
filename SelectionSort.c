#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *V, int tam){

  int a;
  int x = 0;
  int menor = 0;

  do{
    for(int i = x; i<tam-1; i++){
      if(V[i]>V[menor]){
        menor = i;
      }//if
      a = V[menor];
      V[menor] = V[x];
      V[x] = a; 
      x++;
    }//for
  }while(x != tam);
}//void

void exibeVetor(int *V, int tam){

  for(size_t i = 0; i<tam; i++){
    printf("%i\n", V[i]);
  }

}

int main(int argc, char const *argv[]){

  int vetor[10] = {10,-2,21,32,7,0,9,6,46,-5};
  exibeVetor(vetor, 10);
  SelectionSort(vetor, 10);
  printf("\n-----------------\n");
  exibeVetor(vetor, 10);

  return 0;
}
