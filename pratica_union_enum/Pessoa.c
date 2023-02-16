#include <stdio.h>

typedef enum genero {
    MASCULINO,
    FEMININO
}Genero;

typedef struct pessoa {
    char nome[80];
    int idade;
    Genero genero;
}Pessoa;

void cadastraPessoa(Pessoa *PPessoa){
    printf("Digite o nome: ");
    scanf(" %[^\n]", PPessoa->nome);
    printf("Digite a idade: ");
    scanf("%d", &PPessoa->idade);
    printf("Digite o gênero da pessoa: ");
    scanf("%d", (int*)&PPessoa->genero);
}

void exibePessoa(Pessoa *PPessoa){
    printf("\nDados Pessoa: \n");
    printf("Nome: %s\n", PPessoa->nome);
    printf("Idade: %d\n", PPessoa->idade);
    PPessoa->genero=MASCULINO?printf("Masculino\n"):printf("Feminino\n");
}

int main() {
    Pessoa pessoa;

    cadastraPessoa(&pessoa);
    exibePessoa(&pessoa);
    return 0;
}