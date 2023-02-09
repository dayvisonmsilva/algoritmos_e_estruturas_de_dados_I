#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    int idFuncionario;
    char nome[50];
    float salario;
    char cargo[50];
} Funcionario;

void cadastraFuncionarios(int qtd_funcionarios, Funcionario *PFunc){
    int i;
    for (i = 0; i < qtd_funcionarios; i++) {
        PFunc[i].idFuncionario = i+1;
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
        printf("Funcionário ID: %i\n", PFunc[i].idFuncionario);
        printf("Nome: %s\n", PFunc[i].nome);
        printf("Cargo: %s\n", PFunc[i].cargo);
        printf("Salário: R$%.2f\n\n", PFunc[i].salario);
    }
}

void alteraSalario(int qtd_funcionarios, Funcionario* funcionario){
    int i, id, v = 0;
    float salario = 0.0f;
    printf("Digite o ID do funcionário que deseja alterar o salário: ");
    scanf("%i", &id);

    for (i = 0; i < qtd_funcionarios; i++) {
        if (funcionario[i].idFuncionario == id) {
            printf("Qual vai ser o novo salário do funcionário? ");
            scanf("%f", &salario);
            funcionario[i].salario = salario;
            v = 1;
            printf("O salário do(a) %s foi alterado para R$%.2f\n", funcionario[i].nome, funcionario[i].salario);
            break;
        } 
    }
    
    if(v == 0){
        printf("Nenhum funcionário encontrado com esse ID!\n");
    }    
}

void maiorMenorSalarios (int qtd_funcionarios, Funcionario* funcionario) {
    int i;
    float maior = 0.0;
    float menor = 0.0;
    Funcionario f;

    for (i = 0; i < qtd_funcionarios; i++) {
        if (funcionario[i].salario > maior) {
            f = funcionario[i];
            maior = f.salario;
        }
    }
    printf("\nMaior salário: R$%.2f; Cargo: %s", f.salario, f.cargo);

    for (i = 0; i < qtd_funcionarios; i++) {
        if (funcionario[i].salario < maior) {
            f = funcionario[i];
            menor = f.salario;
        }
    }
    printf("\nMenor salário: R$%.2f; Cargo: %s\n", f.salario, f.cargo);   
}


int main(void) {
    int qtd_funcionarios;
    int opcao = 0;

    printf("Digite a quantidade de funcionários que deseja cadastrar: ");
    scanf("%i", &qtd_funcionarios);

    Funcionario *funcionarios;
    funcionarios = (Funcionario*) malloc(sizeof(Funcionario)*qtd_funcionarios);

    cadastraFuncionarios(qtd_funcionarios, funcionarios);
    exibeFuncionarios(qtd_funcionarios, funcionarios);

    printf("Deseja alterar o salário de algum funcionário?\nSim(1) Não(0): ");
    scanf("%i", &opcao);
    
    switch (opcao) {
    case 1:
        alteraSalario(qtd_funcionarios, funcionarios);
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
    
    maiorMenorSalarios(qtd_funcionarios, funcionarios);

    return 0;
}
