/*
** Função : O progrma recebe um número inteiro positivo n e informa
 se n é um número feliz/infeliz .
** Autor : Anna Carolina Campos de ALcântara Veloso
** Data : 31/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

int soma_quad_digitos(int num) {
    int soma = 0;
    while (num > 0) {
        int digito = num % 10;
        soma += digito * digito;
        num /= 10;
    }
    return soma;
}
bool num_feliz(int num) {
    int visitados[1000] = {0}; 
    while (num != 1 && !visitados[num]) {
        visitados[num] = 1;
        num = soma_quad_digitos(num);
    }
    return num == 1;
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    if (num_feliz(n)) {
        printf("%d é um número feliz.\n", n);
    } else {
        printf("%d é um número infeliz.\n", n);
    }
    return 0;
}
