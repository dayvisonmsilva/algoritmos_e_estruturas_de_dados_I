// Programa para corrigir provas de múltipla escolha.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, i, k, qtd_questoes_certas, num_aprovados = 0;
    char questao;
    printf("Iniciando programa...\n");
    // leitura do número de questões
    printf("Digite o número de questões da prova: ");
    scanf("%d", &N);

    // Alocando os vetores dinamicamente
    char *gabarito_prova = (char*) malloc(N * sizeof(char));
    float *notas_alunos = (float*) malloc(10 * sizeof(float));
    
    if (gabarito_prova == NULL || notas_alunos == NULL) {
        printf("Erro de alocação detectado!\n");
        return 1; // encerra o programa com status de erro
    }

    // laço que irá preencher o vetor 'gabarito_prova' com as respostas corretas 
    printf("Preencha o Gabarito das questões: \n");
    for (i = 0; i < N; i++) {
        printf("Questão - %d: ", i+1);
        scanf(" %c", &gabarito_prova[i]);
    }

    printf("\nHora de inserir as notas dos alunos: \n");
    printf("As questões possuem 5 alternativas: A, B, C, D, E\n");
    for (i = 0; i < 10; i++) {
        qtd_questoes_certas = 0;
        printf("\nAluno Nº%d\n", i+1);
        for (k = 0; k < N; k++) {
            printf("Questão - %d: ", k+1);
            scanf(" %c", &questao);

            // verifica se a questao esta correta e salva na 
            // variavel para que possa ser feito o calculo das notas mais abaixo
            if (questao == gabarito_prova[k])
                qtd_questoes_certas++;
        }
        /*aqui eu pego a qtd de questões certas e multiplico pelo peso de cada questao (10/N)
        , ou seja, se o aluno acertar as N questoes (N == qtd_questoes_certas) ele terá 10 pontos*/
        notas_alunos[i] = (10.0/N) * qtd_questoes_certas; 
    }
    // loop 'for' para exibir os resultados obtidos
    printf("\n-----RESULTADOS-----\n");
    for (i = 0; i < 10; i++) {
        printf("Aluno - %d\tNota: %.2f\n", i+1, notas_alunos[i]);
        if (notas_alunos[i] >= 6.0) {
            num_aprovados++;
        }
    }
    printf("\nA porcentagem de alunos aprovados foi de %.2f%%\n", 100.0 * num_aprovados / 10);
    
    free(gabarito_prova);
    free(notas_alunos);
    return 0;
}