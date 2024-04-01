/*
** Função : O programa recebe dois números,
 exibe seus divisores próprios e diz se são amigáveis.
 Ele então busca pares de números amigáveis até um valor
 máximo informado pelo usuário.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 28/03/2024
** Observações:
*/

#include <stdio.h>
int numero1, numero2;

void saoAmigaveis(int numero1, int numero2) {
  int somaDivisoresN1 = 0, somaDivisoresN2 = 0;

  printf("Divisores de %d: ", numero1);
  for (int i = 1; i < numero1; i++) {
      if (numero1 % i == 0) {
          printf("%d ", i);
          somaDivisoresN1 += i;
      }
  }
  printf("\nSoma dos divisores de %d: %d\n", numero1, somaDivisoresN1);
  printf("Divisores de %d: ", numero2);
  for (int i = 1; i < numero2; i++) {
      if (numero2 % i == 0) {
          printf("%d ", i);
          somaDivisoresN2 += i;
      }
  }
  printf("\nSoma dos divisores de %d: %d\n", numero2, somaDivisoresN2);
   if (somaDivisoresN1 == numero2 && somaDivisoresN2 == numero1) {
          printf("%d e %d são números amigáveis!\n", numero1, numero2);
      } else {
          printf("%d e %d não são números amigáveis!\n", numero1, numero2);
      }
  }
void verificarPares(int n) {
    printf("Pares de números amigáveis até %d:\n", n);
  for (int i = 1; i <= n; i++) {
      int somaDivisoresN1 = 0;
      for (int k = 1; k < i; k++) {
          if (i % k == 0) {
              somaDivisoresN1 += k;
          }
      }
      for (int j = i + 1; j <= n; j++) {
          int somaDivisoresN2 = 0;
          for (int k = 1; k < j; k++) {
              if (j % k == 0) {
                  somaDivisoresN2 += k;
              }
          }
          if (somaDivisoresN1 == j && somaDivisoresN2 == i) {
              printf("%d e %d\n", i, j);
          }
      }
  }
}

int main(void) {

  printf("Digite dois números (separados por espaço) para verificar se são número amigáveis: ");
  scanf("%d %d", &numero1, &numero2);
  saoAmigaveis(numero1, numero2);

  int valor;
  printf("\nDigite um valor n para verificar pares de números amigáveis até esse valor: ");
  scanf("%d", &valor);
  verificarPares(valor);

  return 0;
}