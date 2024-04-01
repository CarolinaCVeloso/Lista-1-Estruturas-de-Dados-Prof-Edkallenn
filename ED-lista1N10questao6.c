/*
** Função : O programa recebe um número inteiro positivo n como
e informa se esse número é carmichael.
 Ele também lista os números carmichael até o limite determinado pelo usuário.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 01/03/2024
** Observações:
*/


#include <stdio.h>
#include <stdbool.h>
int mdc(int a, int b) {
  while (b > 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int mod_pow(int a, int b, int m) {
  if (b == 0) {
    return 1;
  }
  int temp = mod_pow(a, b / 2, m);
  if (b % 2 == 0) {
    return (temp * temp) % m;
  } else {
    return ((temp * temp) % m * a) % m;
  }
}

bool num_carmichael(int n) {
  if (n == 2) {
    for (int a = 3; a < n; a += 2) {
      if (mod_pow(a, 2, n) != 1) {
        return 0;
      }
    }
    return 1;
  }

  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  for (int a = 2; a < n; a++) {
    if (mdc(a, n) == 1) {
      if (mod_pow(a, n, n) != 1) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  int n, valor_limite;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);
  bool carmichael = num_carmichael(n);

  if (carmichael) {
    printf("%d é um número de Carmichael\n", n);
  } else {
    printf("%d não é um número de Carmichael\n", n);
  }


  printf("Digite um valor limite inteiro e positivo: ");
  scanf("%d", &valor_limite);
  for (int i = 2; i <= valor_limite; i++) {
    if (num_carmichael(i)) {
      printf("%d ", i);
    }
  }
  return 0;
}