#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char nome[50];
    int cpf;
    int idade;
} Pessoa;

void cadastraPessoa(int qtd_pessoas, Pessoa *PPessoa){
    int i;
    for (i = 0; i < qtd_pessoas; i++) {
        printf("\nPessoa N°%i\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]", PPessoa[i].nome);
        printf("CPF (apenas números): ");
        scanf(" %i", &PPessoa[i].cpf);
        printf("Idade: ");
        scanf("%i", &PPessoa[i].idade);
    }
}

void exibePessoas(int qtd_pessoas, Pessoa *PPessoa){
    int i;
    printf("\n----------------PESSOAS----------------\n");
    for (i = 0; i < qtd_pessoas; i++) {
        printf("Nome: %s\n", PPessoa[i].nome);
        printf("CPF: %i\n", PPessoa[i].cpf);
        printf("Idade: %i\n\n", PPessoa[i].idade);
    }
}

void alteraIdade(int qtd_pessoas, Pessoa* pessoa){
    int i, CPF, v = 0;

    printf("Digite o CPF da pessoa que deseja alterar a idade: ");
    scanf("%i", &CPF);
    for (i = 0; i < qtd_pessoas; i++) {
        if (pessoa[i].cpf == CPF) {
            printf("Qual a idade da pessoa? ");
            scanf("%i", &pessoa[i].idade);
            printf("A idade do(a) %s foi alterada para %i\n", pessoa[i].nome, pessoa[i].idade);
            v = 1;
            break;
        } 
    }
    
    if(v == 0){
        printf("Nenhuma pessoa encontrada com o CPF especificado!\n");
    }    
}

void maiorMenorIdade (int qtd_pessoas, Pessoa* pessoa) {
    int i;
    int maior = 0, menor = 0;
    Pessoa p;

    for (i = 0; i < qtd_pessoas; i++) {
        if (pessoa[i].idade > maior) {
            p = pessoa[i];
            maior = p.idade;
        }
    }
    menor = maior;
    printf("\nMaior idade: %i --> %s", p.idade, p.nome);

    for (i = 0; i < qtd_pessoas; i++) {
        if (pessoa[i].idade < menor) {
            p = pessoa[i];
            menor = p.idade;
        }
    }
    printf("\nMenor salário: %i --> %s\n", p.idade, p.nome);   
}


int main(void) {
    int qtd_pessoas;
    int opcao = 0;

    printf("Digite a quantidade de pessoas que deseja cadastrar: ");
    scanf("%i", &qtd_pessoas);

    Pessoa *pessoas;
    pessoas = (Pessoa*) malloc(sizeof(Pessoa)*qtd_pessoas);

    cadastraPessoa(qtd_pessoas, pessoas);
    exibePessoas(qtd_pessoas, pessoas);

    printf("Deseja alterar a idade de alguém?\nSim(1) Não(0): ");
    scanf("%i", &opcao);
    
    switch (opcao) {
    case 1:
        alteraIdade(qtd_pessoas, pessoas);
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
    
    maiorMenorIdade(qtd_pessoas, pessoas);

    return 0;
}