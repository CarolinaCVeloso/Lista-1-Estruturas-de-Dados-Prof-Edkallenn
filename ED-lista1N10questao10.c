/*
** Função : O programa apresenta a sequência de fibonacci para o valor limite estabelecido.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 01/04/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

int* fibonacci_limit(int limite) {
    int* fibonacci = (int*)malloc(1 * sizeof(int)); 
    if (fibonacci == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    int tamanho = 1; 
    fibonacci[0] = 0; 
    int proximo = 1; 
    int indice = 1; 


    while (proximo <= limite) {
       
        fibonacci = (int*)realloc(fibonacci, (tamanho + 1) * sizeof(int));
        if (fibonacci == NULL) {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }

        fibonacci[indice++] = proximo; 
        tamanho++; 

        int temp = proximo;
        proximo += fibonacci[indice - 2];
        fibonacci[indice - 1] = temp;
    }

    fibonacci = (int*)realloc(fibonacci, (tamanho + 1) * sizeof(int));
    if (fibonacci == NULL) {
        printf("Erro ao realocar memória.\n");
        exit(1);
    }
    fibonacci[tamanho] = -1;

    return fibonacci; 
}

int main() {
    int limite;
    printf("Digite o número máximo para a série de Fibonacci: ");
    scanf("%d", &limite);

    int* fibonacci = fibonacci_limit(limite);

    printf("Série de Fibonacci até %d:\n{", limite);
    for (int i = 0; fibonacci[i] != -1; ++i) {
        printf("%d ", fibonacci[i]);
    }
    printf("-1}\n");

    free(fibonacci); 

    return 0;
}
