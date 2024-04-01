/*
** Função :o programa calcula o resultado das funções fatorial
 e fat_duplo para os números números 2-20, com intuito de montar 
 uma tabela de exemplo incluindo suas diferenças.
 O resultado é salvo em um arquivo txt.
** Autor : Anna Carolina Campos de Alcântara Veloso
** Data : 28/03/2024
** Observações:
*/

#include <stdio.h>
int n, resultado;

int fatorial(n) {
    resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int fat_duplo(n){
    resultado = 1;
    for (int i = n; i > 0; i -= 2) {
        resultado *= i;
    }
    return resultado;
}

int main(void) {
    const int valorMax = 20;

    FILE *arquivo = fopen("arquivoResposta.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    printf("------------TABELA DE EXEMPLO-------------\n");
    printf("N\t| Fatorial\t| Fatorial Duplo\t| diferença\n");
    printf("-------------------------------------------\n");
    for (int i = 2; i <= valorMax; ++i) {
        int fator_normal = fatorial(i);
        int fator_duplo = fat_duplo(i);
        int diferenca = fator_normal - fator_duplo;
        printf("%d\t| %-10d\t| %-15d\t| %-9d\n", i, fator_normal, fator_duplo, diferenca);
        fprintf(arquivo, "%d\t| %-10d\t| %-15d\t| %-9d\n", i, fator_normal, fator_duplo, diferenca);
    }
    fclose(arquivo);

    return 0;
}