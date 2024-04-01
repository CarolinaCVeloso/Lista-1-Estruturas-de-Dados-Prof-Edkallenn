/*
** Função : O progrma mostra os números de Armstrong entre 1 e 100.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 31/03/2024
** Observações:
*/
#include <stdio.h>
#include <stdbool.h>

int cont_digitos(int num) {
    int contg = 0;
    while (num != 0) {
        num /= 10;
        contg++;
    }
    return contg;
}

bool num_armstrong(int num) {
    int original = num;
    int soma = 0;
    int n_digitos = cont_digitos(num);
    while (num != 0) {
        int digito = num % 10;
        soma += pow(digito, n_digitos);
        num /= 10;
    }
    return soma == original;
}

int main() {
    printf("Os números de Armstrong entre 1 e 100 são:\n");
    for (int i = 1; i <= 100; i++) {
        if (num_armstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
