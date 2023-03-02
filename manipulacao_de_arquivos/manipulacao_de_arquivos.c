#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    fp = fopen("entrada.txt", "wt");

    if (fp == NULL) {
        printf("Erro na abertura de arquivo!\n");
        exit(1);
    }
    
    int valor = fclose(fp);

    if (valor != 0) {
        printf("Erro ao fechar o arquivo!\n");
    }
    else {
        printf("Arquivo fechado com sucesso!\n");
    }

    return (0);
}