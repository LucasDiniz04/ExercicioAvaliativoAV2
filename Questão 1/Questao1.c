#include <stdio.h>

void bubbleSort(int vetor[], int tamanho){
    int i, j, temp;
    for (i=0; i<tamanho-1; i++){
        for (j=0; j<tamanho-i-1; j++){
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main(){
    int tamanho, i;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    
    printf("Digite os elementos do vetor:\n");
    for (i=0; i<tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    bubbleSort(vetor, tamanho);
    printf("Vetor ordenado em ordem crescente:\n");
    for (i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}