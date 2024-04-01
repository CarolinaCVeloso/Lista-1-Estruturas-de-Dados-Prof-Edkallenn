/*
** Função : O progrma recebe um número inteiro positivo n e calcula a soma 
dos fatoriais inversos até o termo n .
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 29/03/2024
** Observações:
*/
#include <stdio.h>

int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; ++i) {
        resultado *= i;
    }
    return resultado;
}

double soma_fat_inversos(int n) {
    double soma = 0.0;
    for (int i = 1; i <= n; ++i) {
        soma += 1.0 / fatorial(i);
    }
    return soma;
}

int main() {
    int n;
    printf("Digite um número inteiro positivo n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O número deve ser positivo.\n");
        printf("Digite um número inteiro positivo n: ");
        scanf("%d", &n);
    }

    double resultado = soma_fat_inversos(n);
    printf("A soma dos fatoriais inversos de 1 a %d é: %.6lf\n", n, resultado);

    return 0;
}
