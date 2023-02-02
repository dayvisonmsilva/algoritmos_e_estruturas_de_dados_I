#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int i, quantidadeFrutas;

    printf("Digite a quantidade de frutas que deseja adicionar: ");
    scanf("%i", &quantidadeFrutas);

    // Alocando vetor de ponteiros
    float *precoFrutas = (float *) malloc(quantidadeFrutas * sizeof(float));
    char **nomesFrutas = (char **) malloc(quantidadeFrutas * sizeof(char*));
    
    // Alocando cada linha da matriz 'nomeFrutas'
    for (i = 0; i < quantidadeFrutas; i++) {
        nomesFrutas[i] = (char *) malloc(100 * sizeof(char));
    }

    // Verificando se o espaço foi alocado corretamente
    if ((nomesFrutas == NULL) || (precoFrutas == NULL)) {
        printf("Erro ao alocar memória!");
        exit(1);
    }
    
    for (i = 0; i < quantidadeFrutas; i++) {
        printf("Fruta N°%i. Nome: ", i+1);
        scanf("%s", nomesFrutas[i]);

        printf("Fruta N°%i. Preço: ", i+1);
        scanf("%f", &precoFrutas[i]);
        printf("------------------------------\n");
    }

    // Realocando o Vetor 'nomesFrutas'
    for (i = 0; i < quantidadeFrutas; i++) {
        //printf("Tamanho do vetor %d", (int)strlen(nomesFrutas[i])+1);
        nomesFrutas[i] = (char *) realloc(nomesFrutas[i] ,((int)strlen(nomesFrutas[i]) + 1) * sizeof(char));
    }
    
    printf("\n-----------------TABELA FRUTAS-----------------\n");
    for (i = 0; i < quantidadeFrutas; i++) {
        printf("Fruta: %s\n", nomesFrutas[i]);
        printf("Preço: R$%.2f\n\n", precoFrutas[i]);
    }
    
    // Liberando os espaços alocados
    free(precoFrutas);
    
    for (i = 0; i < quantidadeFrutas; i++) {
        free(nomesFrutas[i]);
    }
    free(nomesFrutas);

    return 0;
}
