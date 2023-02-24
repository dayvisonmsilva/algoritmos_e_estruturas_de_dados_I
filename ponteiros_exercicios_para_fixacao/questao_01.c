#include <stdio.h>

int main  (void) {
    int x, y, *p;
    y = 0; // é atribuido o valor 0 a 'y'
    p = &y; // 'p' agora armazena o local de memoria de 'y'
    x = *p; // x recebe o valor que esta armazenado na memoria para qual 'p' aponta
    x = 4; // 'x' agora recebe o valor 4 substituindo o valor '*p'
    (*p)++; // o valor que esta na memoria para qual 'p' aponta agora eh incrementado em 1
    --x; // 'x' é subtraido em 1
    (*p) += x; // o valor que esta na memoria para qual 'p' aponta agora recebe ele mesmo + o valor de 'x'
    
    // y = 0, x = 3, *p = 4
    printf("X = %d,\tY = %d,\t*P = %d\n", x, y, *p);
    return 0;
}