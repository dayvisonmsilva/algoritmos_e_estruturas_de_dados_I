#include <stdio.h>
#include <stdlib.h>

int ** criaMatrizInt(int linhas, int colunas) {
    int i;
    int **matriz = (int **) malloc(linhas * sizeof(int *));

    // Alocando cada linha da matriz
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }
    return matriz;
}

int main() {

int linhas = 3; 
int colunas = 3; 
int **matriz = criaMatrizInt(linhas, colunas);

// Preenchendo a matriz
int i, j;
for (i = 0; i < linhas; i++)
    for (j = 0; j < colunas; j++)
        matriz[i][j] = i*3 + j;

for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++){
        printf("%i ", matriz[i][j]);
    } 
    printf("\n");
}

// Liberando o espaço alocado
for (i = 0; i < linhas; i++) {
    free(matriz[i]);
}

free(matriz);
return 0;
}
