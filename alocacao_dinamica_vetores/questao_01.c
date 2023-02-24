// Programa pesquisa
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, i;
    int num_feminino = 0, num_feminino_gostou = 0;
    int num_masculino = 0, num_masculino_nao_gostou = 0;

    printf("Iniciando questionario...\n");
    // leitura do número de entrevistados
    printf("Digite o número de entrevistados: ");
    scanf("%d", &N);

    char *sexo = (char*) malloc(N * sizeof(char));
    char *opiniao = (char*) malloc(N * sizeof(char));

    if (sexo == NULL || opiniao == NULL) {
        printf("Erro de alocação detectado!\n");
        return 1; // encerra o programa com status de erro
    }

    // laço 'for' para realizar a qtd de entrevistas informadas pelo usuário
    for (i = 0; i < N; i++) {
        printf("\nEntrevistado %d:\n", i+1);
        printf("Sexo (M/F): ");
        scanf(" %c", &sexo[i]);
        printf("Opinião sobre o produto: Gostou(S) - não gostou(N): ");
        scanf(" %c", &opiniao[i]);
        if (sexo[i] == 'F') {
            num_feminino++; // armazenando a qtd de mulheres entrevistadas
        }  else {
            num_masculino++; // armazenando a qtd de homens entrevistados
        }
    }

    for (i = 0; i < N; i++) {
        if (sexo[i] == 'F' && opiniao[i] == 'S') {
            num_feminino_gostou++;
        } else if (sexo[i] == 'M' && opiniao[i] == 'N') {
            num_masculino_nao_gostou++;
        }
    }

    // cálculo das porcentagens
    float pct_feminino_gostou = 100.0 * num_feminino_gostou / num_feminino;
    float pct_masculino_nao_gostou = 100.0 * num_masculino_nao_gostou / num_masculino;

    // exibição dos resultados
    printf("\n%.2f%% das mulheres gostaram do produto\n", pct_feminino_gostou);
    printf("%.2f%% dos homens não gostaram do produto\n", pct_masculino_nao_gostou);

    free(sexo);
    free(opiniao);
    return 0;
}
