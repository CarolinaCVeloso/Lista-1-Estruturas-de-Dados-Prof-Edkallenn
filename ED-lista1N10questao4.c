/*
** Função : O progrma recebe um num e diz se ele é automorfico ou não.
Ele pede um limite n e imprime todos os números automorfos até o limite dado.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 28/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num_automorfico(int num) {
    int quadrado = num * num;
    int temp = num; 
    int num_digitos = 0;
    while (temp > 0) {
        num_digitos++; 
        temp /= 10;
    }
    int divisor = pow(10, num_digitos);
    return quadrado % divisor == num; 
}

int* verificar_num_automorfico(int limite_superior, int* num_automorficos_encontrados) {
    int* automorficos = malloc(limite_superior * sizeof(int)); 
    if (automorficos == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    *num_automorficos_encontrados = 0; 
    for (int i = 2; i <= limite_superior; i++) {
        if (num_automorfico(i)) {
            automorficos[*num_automorficos_encontrados] = i;
            (*num_automorficos_encontrados)++;
        }
    }

    return automorficos;
}

int main() {
  int numero_verificar;
  printf("Digite um número para verificar se ele é automórfico: ");
  scanf("%d", &numero_verificar);

  if (num_automorfico(numero_verificar)) {
      printf("O número é automórfico\n");
  } else {
      printf("O número não é automórfico\n");
  }

    int limite_superior;
    printf("Digite um limite superior (até 1000) para verificar os números automórficos: ");
    scanf("%d", &limite_superior);

    if (limite_superior <= 0 || limite_superior > 1000) {
        printf("Limite inválido. O limite deve estar entre 1 e 1000.\n");
        printf("Digite um limite superior (até 1000) para verificar os números automórficos: ");
        scanf("%d", &limite_superior);
    }

    int num_automorficos_encontrados;
    int* automorficos = verificar_num_automorfico(limite_superior, &num_automorficos_encontrados);

    printf("Números automórficos entre 2 e %d:\n", limite_superior);
    for (int i = 0; i < num_automorficos_encontrados; i++) {
        printf("%d ", automorficos[i]);
    }
    printf("\n");

    free(automorficos); 

    return 0;
}
