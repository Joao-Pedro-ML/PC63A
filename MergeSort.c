#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibeVetor(int *V, int tam){

  for(size_t i = 0; i<tam; i++){
      printf("%i\n", V[i]);
  }

}

int *vetor(int tam){
    int *tmp=NULL;
    tmp=(int*)malloc(tam*sizeof(int));
    for(int i=0;i<tam;i++){
        tmp[i]=rand()%100;
    }//for
    return tmp;
}//func vetor

/**
 * \brief Ordena o vetor usando Mergesort
 *
 * \param V ponteiro para o vetor a ser ordenado
 * \param inicio indice inicial do vetor
 * \param fim indice final do vetor
 *  
 * 1 - Testa o caso base
 * 2 - Faz as 2 chamadas recursivas
 * 3 - Chama a função merge para intercalar os 2 subvetores 
 */

void mergeSort(int *vetor, int inicio, int fim){

  if(inicio == fim){
    mergeSort();
  }

}//mergeSort

/**
 * \brief Intercala os subvetores mantendo a ordenação
 *
 * \param V ponteiro para o vetor a ser intercalado
 * \param inicio indice inicial do subvetor1
 * \param meio indice final do subvetor1
 * \param fim indice final do subvetor2
 *
 * 1 - Aloca o vetor temporario
 * 2 - Copia os valores para o vetor
 *     temporário intercalando
 * 3 - Volta os valores para o vetor original
 * 4 - Libera memória do vetor temporario
 */

void merge(int *vetor, int inicio, int meio, int fim){

  meio = ((fim-inicio)/2)+1;
  int *aux = (int *)malloc(fim*sizeof(int));
  for(int i = 0; i<fim; i++){
    if(inicio >= fim/2){
      aux[i] = V[meio];
      meio++;
    }//if
    if(){
      
    }//if
  }//for

}//merge

int main(){

  int *V = NULL;
  V = vetor(10);
  exibeVetor(V, 10);

  return 0;
}
