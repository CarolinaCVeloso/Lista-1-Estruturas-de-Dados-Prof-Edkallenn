/*
** Função : O programa exibe todos os números perfeitos entre 1 e 100000.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 31/03/2024
** Observações:
*/
#include <stdio.h>
int num_perfeito(int n) {
    int soma_divisores = 0;
    
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            soma_divisores += i;
        }
    }
    return soma_divisores == n;
}

int main() {
printf("Os números perfeitos entre 1 e 100.000 são: \n");
    for (int i = 1; i <= 100000; ++i) {
        if (num_perfeito(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
