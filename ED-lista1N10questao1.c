/*
** Função : O usuário insere duas entradas para o sistema utilizar
no cálculo da Potencia Fatorial Crescente e Decrescente e exibe
 uma tabela usando X fixo e N variante e vice versa para a fatorial crescente 
 e decrescente. 
O resultado é salvo em um arquivo txt.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 28/03/2024
** Observações:
*/
#include <stdio.h>

int pot_fat_crescente(int x, int n) {
    int resultado = 1;
    for (int i = 0; i < n; ++i) {
        resultado *= (x + i);
    }
    return resultado;
}


int pot_fat_decrescente(int x, int n) {
    int resultado = 1;
    for (int i = 0; i < n; ++i) {
        resultado *= (x - i);
    }
    return resultado;
}

int main(void) {
    printf("Digite um número natural 'x' e sua potência 'n' (separados por espaço) para calcular a Potência Fatorial Crescente e Decrescente: \n");

    int x, n;
    while (1) {
        scanf("%d %d", &x, &n);
        if (x >= 0 && n >= 0) {
            break;
        } else {
            printf("Erro! Os dois números devem ser números naturais!\n");
        }
    }

    FILE *arquivo = fopen("arquivoResposta.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o resultado.\n");
        return 1;
    }

    printf("------------TABELA DE EXEMPLO-------------\n");
    printf("X\t| N\t| Crescente\t| Decrescente\n");
    printf("-------------------------------------------\n");

    int x_fixo = 2; 
    for (int n = 2; n <= 10; ++n) {
        int pfcrescente = pot_fat_crescente(x_fixo, n);
        int pfdecrescente = pot_fat_decrescente(x_fixo, n);
        printf("%d\t| %d\t| %d\t\t| %d\n", x_fixo, n, pfcrescente, pfdecrescente);
        fprintf(arquivo, "%d\t| %d\t| %d\t| %d\n", x_fixo, n, pfcrescente, pfdecrescente); 
    }
    printf("=========================================\n");
    int n_fixo = 4; 
    for (int x = 2; x <= 10; ++x) {
        int pfcrescente = pot_fat_crescente(x, n_fixo);
        int pfdecrescente = pot_fat_decrescente(x, n_fixo);
        printf("%d\t| %d\t| %d\t\t| %d\n", x, n_fixo, pfcrescente, pfdecrescente);
        fprintf(arquivo, "%d\t| %d\t| %d\t| %d\n", x, n_fixo, pfcrescente, pfdecrescente);
    }
    fclose(arquivo);
    printf("\nA tabela exemplo consta no Arquivo texto gerado!\n");

return 0;
}