// Programa para calcular a area de um hexagono
#include <stdio.h>
#include <math.h>

// funcao que calcula a area do hexagono
void calcula_hexagono(float l, float *area, float *perimetro);

int main (void) {
    float lado, area, perimetro;

    printf("Digite o valor do lado do hexagono: ");
    scanf(" %f", &lado);

    // Aqui, atraves do operador '&' podemos passar o endereço de uma variável para a funcao
    // Como estamos passando o endereco das variaveis, mesmo elas podem ser alteradas de dentro da funcao
    // e seu valor poderá ser mudado e acessado fora do escopo da funcao.
    calcula_hexagono(lado, &area, &perimetro);
    printf("Area = %.2f\tPerimetro = %.2f\n", area, perimetro);
    return 0;
}

void calcula_hexagono(float l, float *area, float *perimetro) {
    *area =  (3*pow(l, 2)*sqrt(3))/2;
    *perimetro = l*6;
}