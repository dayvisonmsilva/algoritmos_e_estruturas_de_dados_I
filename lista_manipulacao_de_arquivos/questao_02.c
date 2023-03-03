#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *arquivo_entrada;
    int vetor[10];
    char linha[10];
    int i = 0;
    int maior_elemento, menor_elemento, media;

    // abrindo o arquivo de entrada e atribuindo a variavel entrada (FILE*)
    arquivo_entrada = fopen("entrada_q3.txt", "rt");
    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    // le linha a linha
    while (fgets(linha, 10, arquivo_entrada) != NULL){
        sscanf(linha, "%d", &vetor[i]);
        i++;
        printf("valor: %d\n", vetor[i]);
    }

    return 0;
}