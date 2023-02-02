#include <stdio.h>
#include <stdlib.h>

int main() {
int linhas=3, colunas=3, i, j;

// Alocando vetor de ponteiros
int **matriz = (int **) malloc(linhas * sizeof(int *));

// Alocando cada linha da matriz
for (i = 0; i < linhas; i++) {
    matriz[i] = (int *) malloc(colunas * sizeof(int));
}

for (i = 0; i < linhas; i++)
    for (j = 0; j < colunas; j++)
        matriz[i][j] = j;

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