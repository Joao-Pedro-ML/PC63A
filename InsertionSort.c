#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *\brief Realiza o insertionSort
 *
 *\param V ponteiro para o vetor a ser exibido
 *\param tam tamanho do vetor
 *
 *
 */
void InsertionSort(int *V, int tam){
    int aux;
    int j;
    for(int i = 1; i < tam; i++){
        aux = V[i];
        
        for(j = i; j > 0 && aux < V[j-1]; j--){
            
            V[j] = V[j-1];
            
        }//for
        V[j] = aux;
        
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
    
    int vetor[15];
    for(int i = 0; i<15; i++){
        vetor[i] = rand()%100;
    }//for
    exibeVetor(vetor, 15);
    InsertionSort(vetor, 15);
    printf("\n-----------------\n");
    exibeVetor(vetor, 15);
    
    return 0;
}
