#include <stdio.h>
#include <stdlib.h>

int main () {
    int *inteiros = (int *) malloc(10 * sizeof(int));
    int i;

    if (inteiros == NULL) {
        printf("Erro ao alocar memória!");
        exit(1);
    }
    
    for (i = 0; i < 10; i++) {
        inteiros[i] = i;
    }
    
    printf("VETOR 'INTEIROS': \n");
    for (i = 0; i < 10; i++) {
        printf("%i ", inteiros[i]);
    }
    printf("\n");

    free(inteiros);
    return 0;
}
