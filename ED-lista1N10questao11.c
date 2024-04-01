/*
** Função : O progrma recebe um tamanho para os arrays que serão criados
 e compara para verificar se são permutaçãoes ou não.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 01/04/2024
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>

int permut_circular(int* array1, int* array2, int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        int igual = 1;

        for (int j = 0; j < tamanho; j++) {
            if (array1[j] != array2[(i + j) % tamanho]) {
                igual = 0;
                break;
            }
        }
        if (igual) return 1;
    }
    return 0;
}

int main() {
    int tamanho;
    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int* array1 = (int*)malloc(tamanho * sizeof(int));
    int* array2 = (int*)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array2[i]);
    }

    if (permut_circular(array1, array2, tamanho)) {
        printf("Os arrays são permutações circulares um do outro.\n");
    } else {
        printf("Os arrays não são permutações circulares um do outro.\n");
    }

    free(array1);
    free(array2);

    return 0;
}
