#include <stdio.h>
#include <string.h>

int main() {
    int n = 0; // numero da linha corrente
    int achou = 0; // indica se aahou subcadeia
    char entrada[121], subcadeia[121];
    char linha[121]; // armazena cada linha do arquivo
    FILE *fp; // ponteiro do arquivo de entrada

    // pede ao usuario o nome do arquivo e a subcadeia
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%120s", entrada);
    printf("Digite a subcadeia: ");
    scanf("%120s", subcadeia);

    // abre arquivo para leitura
    fp = fopen(entrada, "rt");
    if (fp == NULL) {
        printf("Nao foi possivel abrir arquivo de entrada.\n");
        return 1;
    }
    
    // le linha a linha
    while (fgets(linha, 121, fp) != NULL) {
        n++;
        if (strstr(linha, subcadeia) != NULL) {
            achou = 1;
            break;
        }
    }
    // fecha arquivo
    fclose(fp);

    // exibe saida
    if (achou) {
        printf("Achou na linha %d.\n", n);
    } else {
        printf("Nao achou.\n");
    }
    
    return 0;
}