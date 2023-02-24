#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N, i, j, qtd_costas = 0;
    int cima, baixo, esquerda, direita;

    printf("Digite o número de linhas M: ");
    scanf("%d", &M);

    printf("Digite o número de colunas N: ");
    scanf("%d", &N);

    char **matriz = (char **)malloc(M * sizeof(char *));

    for (i = 0; i < M; i++) {
        matriz[i] = (char *)malloc(N * sizeof(char));
    }

    // preenchendo a matriz que representa o mapa
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    // verifica a quantidade de costas do território
    for (i = 0; i < M; i++) { // i = M, j = N
        for (j = 0; j < N; j++) {
            cima = i-1;
            baixo = i+1;
            direita = j+1;
            esquerda = j-1;
            
            // A primeira verificação já separa logo de cara quadrados de água e de terra
            // para que sejam aplicadas as verificações apenas em quadrados que ñ sejam de água.
            if (matriz[i][j] != '.') {
                // Se cair em um desses casos significa que os valores transbordam os limites da matriz
                // ou seja, podemos considerar ser um quadrado de costa ou que está em contato com água
                if ((cima < 0 || esquerda < 0) || (baixo >= M || direita >= N)) {
                    qtd_costas++;
                    // por ultimo, se ñ cair no caso anterior significa que não é um quadrado de borda do mapa.
                    // Portanto podemos verificar os quadrados vizinhos com a certeza de ñ ultrapassar a matriz
                } else if (matriz[cima][j] == '.' || matriz[baixo][j] == '.' || matriz[i][esquerda] == '.' || matriz[i][direita] == '.') {
                    qtd_costas++;
                }
            }
        }
    }

    printf("Quantidade de costas: %d\n", qtd_costas);

    // libera a memória alocada para a matriz
    for (i = 0; i < M; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
