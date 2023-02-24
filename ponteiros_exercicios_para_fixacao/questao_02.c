#include <stdio.h>

/*
Sim, o compilador nos fornecerá uma mensagem de erro.
a) O compilador nos fornecerá uma mensagem de aviso (warning), que dentro de diferentes contestos podem passar batido, como por exemplo
uma variável declarada e não usada, mas no caso de ponteiros e uso de memória isso acarretará diretamente em um erro.
b) O compilador emite essa mensagem porque há um erro de tipagem no código. A variável "p" é um ponteiro e precisa apontar para um endereço de memória válido, 
mas no código dado, o endereço para o qual o ponteiro "p" aponta não é definido corretamente. Em vez disso, o valor da variável "x" é atribuído diretamente a "p", o que é incorreto.
c) Não podemos executar o programa corretamente, pois ocorre uma falha de segmentação. Ou seja, o programa tenta acessar uma área restrita da memória ou inexistente.
d) Para corrigir o erro, precisamos atribuir o endereço de memória de "x" a "p", em vez do valor de "x". Portanto, o código deve ser modificado.
e) Depois de corrigir o código, podemos compilar e executar o programa, que deve ser executado sem problemas.
*/

int main(void) {
  int x, *p;
  x = 100;
  p = &x; //atribuir o endereço de x para o ponteiro p
  printf("Valor de p = %p\tValor de *p = %d\n", p, *p);
}