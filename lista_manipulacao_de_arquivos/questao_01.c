#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *arquivo_entrada, *arquivo_saida;
    char linha[100], nome[100]; // armazena cada linha do arquivo / nome do aluno
    float nota1, nota2, nota3, media = 0;

    // abrindo o arquivo de entrada e atribuindo a variavel entrada (FILE*)
    arquivo_entrada = fopen("entrada_q3.txt", "rt");
    if (arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    // abrindo o arquivo de saida e atribuindo a variavel entrada (FILE*)
    arquivo_saida = fopen("saida_q3.txt", "wt");
    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // le linha a linha
    while (fgets(linha, 100, arquivo_entrada) != NULL){
        sscanf(linha, "%20[^\t]\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3) / 3.0;
        printf("NOME: %s\n", nome);
        // Escreve no arquivo de saida os dados dos alunos
        fprintf(arquivo_saida, "%s\t%.1f\t %s\n", nome, media, (media >= 7.0) ? "aprovado" : "reprovado");
    }
    // Fecha os arquivos abertos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
    return 0;
}