#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
 * \brief Intercala os subvetores mantendo a ordenação
 *
 * \param vetor ponteiro para o vetor a ser intercalado
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

    int *aux, p1, p2, tam, i, j, k;
    tam = fim-inicio+1;
    p1 = inicio;
    p2=meio+1;
    aux = (int*)malloc(tam*sizeof(int));
    if(aux!=NULL){
        for (i=0; i<tam; i++) {
            if(p1<=meio && p2<=fim){
                if(vetor[p1]<vetor[p2]){
                    aux[i] = vetor[p2++];
                } else{
                    aux[i] = vetor[p1++];
                }
            }else{
                if(p1<=meio){
                    aux[i] = vetor[p1++];
                }else{
                    aux[i] = vetor[p2++];
                }
            }
        }//for
        for(j=0, k=inicio; j<tam; j++, k++){
            vetor[k] = aux[j];
        }
    }//if
    free(aux);

}//merge

/**
 * \brief Ordena o vetor usando Mergesort
 *
 * \param vetor ponteiro para o vetor a ser ordenado
 * \param inicio indice inicial do vetor
 * \param fim indice final do vetor
 *
 * 1 - Testa o caso base
 * 2 - Faz as 2 chamadas recursivas
 * 3 - Chama a função merge para intercalar os 2 subvetores
 */

void mergeSort(int *vetor, int inicio, int fim){

    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }

}//mergeSort


int main(){

    int *V = NULL;
    int tam = 15;
    V = vetor(tam);
    exibeVetor(V, tam);
    printf("\n-------------\n");
    mergeSort(V, 0, tam-1);
    exibeVetor(V, tam);

  return 0;
}
