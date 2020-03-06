#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *V, int tam){
    
    int aux;
    int temp;
    int menor;
    int troca;
    
    for(aux = 0; aux<tam-1; aux++){
        menor = aux;
        for (temp=aux+1; temp < tam; temp++){
        if (V[temp] < V[menor]){
                menor = temp;
            }
        }
        if (menor != aux){
            troca = V[aux];
            V[aux]   = V[menor];
            V[menor] = troca;
        }
    }
}

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
