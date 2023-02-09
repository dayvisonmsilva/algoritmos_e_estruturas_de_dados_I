#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[50];
    float salario;
    char cargo[50];
} Funcionario;

void cadastraFuncionarios(int qtd_funcionarios, Funcionario *PFunc){
    int i;
    for (i = 0; i < qtd_funcionarios; i++) {
        printf("\nFuncionário N°%i\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", PFunc[i].nome);
        printf("Cargo: ");
        scanf(" %[^\n]", PFunc[i].cargo);
        printf("Salário: ");
        scanf("%f", &PFunc[i].salario);
    }
}

void exibeFuncionarios(int qtd_funcionarios, Funcionario *PFunc){
    int i;
    printf("\n----------------FUNCIONÁRIOS----------------\n");
    for (i = 0; i < qtd_funcionarios; i++) {
        printf("Funcionário N°%i\n", i+1);
        printf("Nome: %s\n", PFunc[i].nome);
        printf("Cargo: %s\n", PFunc[i].cargo);
        printf("Salário: R$%.2f\n", PFunc[i].salario);
    }
}


int main(void) {
    int qtd_funcionarios;

    printf("Digite a quantidade de funcionários que deseja cadastrar: ");
    scanf("%i", &qtd_funcionarios);

    Funcionario *funcionarios;
    funcionarios = (Funcionario*) malloc(sizeof(Funcionario)*qtd_funcionarios);

    cadastraFuncionarios(qtd_funcionarios, funcionarios);
    exibeFuncionarios(qtd_funcionarios, funcionarios);
    return 0;
}