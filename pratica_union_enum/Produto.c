#include <stdio.h>

typedef enum tipo {
    ALIMENTO,
    BEBIDA,
    ALETRONICO
}Tipo;

typedef struct produto {
    char nome[80];
    float preco;
    Tipo tipo;
}Produto;

void cadastraProduto(Produto *PProduto){
    printf("Digite o nome: ");
    scanf(" %[^\n]", PProduto->nome);
    printf("Digite o preço: ");
    scanf("%f", &PProduto->preco);
    printf("Digite o tipo do produto: ");
    scanf("%d", (int*)&PProduto->tipo);
}

void exibeProduto(Produto *PProduto){
    printf("\nDados Produto: \n");
    printf("Nome: R$ %s\n", PProduto->nome);
    printf("Preço: %.2f\n", PProduto->preco);
    printf("Tipo do produto: ");
    if (PProduto->tipo==ALIMENTO) {
        printf("ALIMENTO\n");
    } else if (PProduto->tipo==BEBIDA) {
        printf("BEBIDA\n");
    } else {
        printf("ELETRÔNICO\n");
    }
    
}

int main() {
    Produto produto;

    cadastraProduto(&produto);
    exibeProduto(&produto);
    return 0;
}