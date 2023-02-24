#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3
#define MAX_TURMAS 3

typedef struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;

typedef struct turma {
    char id; 
    int vagas; 
    Aluno* alunos[MAX_VAGAS];
}Turma;

typedef enum boolean { False, True }Boolean;

int verificar_turma_existente(Turma **turma, char id, int n); // minha funcao

Turma* cria_turma(char id); // funcao do projeto

void imprime_turmas(Turma** turmas, int n); // funcao do projeto

void matricula_aluno(Turma* turma, int mat, char* nome); // funcao do projeto

Turma* procura_turma(Turma** turmas, char id, int n); // funcao do projeto

void lanca_notas(Turma* turma); // funcao do projeto

void imprime_alunos(Turma* turma); // funcao do projeto

void libera_turma(Turma** turmas, int n); // minha funcao

int main() {
    Turma* turmas[MAX_TURMAS]; 
    int opcao, matricula, numTurmas = 0;
    char id;
    char nome[81];

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as\n");
    printf("funcionalidades de matricula, lancamento de notas e listagem de\n");
    printf("alunos.\n");
    printf("Autor: DAYVISON DE MOURA SILVA Versao: 1.0\n");

 do {
    printf("\nMENU:\n");
    printf("1 – Criar turma\n");
    printf("2 – Listar turmas\n");
    printf("3 – Matricular aluno\n");
    printf("4 – Lancar notas\n");
    printf("5 – Listar alunos\n");
    printf("6 – Sair\n\n");

    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("\nCriando nova turma...\n");
            printf("Digite o identificador da turma: ");
            scanf(" %c", &id);
            /*Verificações básicas para saber a possibilidade de criação de uma nova turma
            Caso o número maximo de turmas for atingido ou for tentado criar uma nova turma
            com um ID já existente o usuário será impedido.*/
            if (verificar_turma_existente(turmas, id, numTurmas) == True) {
                printf("ATENCAO: Ja existe uma turma com o ID '%c'\n", id);
            } else if(numTurmas == MAX_TURMAS){
                printf("NUMERO MAXIMO DE TURMAS ATINGIDO!\n");
            } else {
                turmas[numTurmas++] = cria_turma(id);
            }
            break;
        case 2:
            imprime_turmas(turmas, numTurmas);
            break;
        case 3:
            printf("\nMatriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            printf("Digite a matricula: ");
            scanf(" %d", &matricula);
            printf("Digite o nome: ");
            scanf(" %[^\n]s", nome);
            verificar_turma_existente(turmas, id, numTurmas) ? matricula_aluno(procura_turma(turmas, id, numTurmas), matricula, nome) : printf("Turma inexistente!\n");      
            break;
        case 4:
            printf("\nLancando notas...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            verificar_turma_existente(turmas, id, numTurmas) ? lanca_notas(procura_turma(turmas, id, numTurmas)) : printf("Turma inexistente!\n");                  
            break; 
        case 5:
            printf("\nListando alunos...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            verificar_turma_existente(turmas, id, numTurmas) ? imprime_alunos(procura_turma(turmas, id, numTurmas)) : printf("Turma inexistente!\n");
            break;           
        case 6:
            printf("\nObrigado por usar este programa!");
            break;
        default:
            printf("Opção inválida. Por favor, tente outra opção!\n");
            break;
        }
    } while(opcao != 6);

    libera_turma(turmas, numTurmas);

    return 0;
}

// Em C, quando passamos um vetor para uma função, 
// ela irá receber o endereço do primeiro elemento da vetor.
int verificar_turma_existente(Turma **turmas, char id, int n) {
    Boolean verificador = 0;
    for (int i = 0; i < n; i++) {
        if (turmas[i]->id == id) {
            verificador = 1;
        }       
    }
    return verificador;
}

Turma* procura_turma(Turma** turmas, char id, int n){ 
    for (int i = 0; i < n; i++) {
        if (turmas[i]->id == id) {
            return turmas[i];
        }
    }
    return NULL;
}

/* Na função cria_turma foi criado um vetor de ponteiro Turma, para criar uma nova turma, 
então ele foi alocado dinamicamente para que possa ser utilizado fora do escopo da função, já que
mesmo que fosse passado no 'return' a memória referente a ele seria perdida. Em seguida, cada posição do vetor 
de alunos foi iniciada com o valor NULL.*/
Turma* cria_turma(char id) {
    Turma* turma = (Turma*) malloc(sizeof(Turma));
    if (turma != NULL) {
        printf("Turma %c criada com sucesso!\n", id);
    } else {
        printf("Erro ao criar a turma. Nao ha mais espaco na memoria.\n");
        exit(1);
    }
    turma->id = id;
    turma->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++) {
        turma->alunos[i] = NULL;
    }
    return turma;
}

void imprime_turmas(Turma **turmas, int n) {
    printf("\nListando turmas...\n");     
    for (int i = 0; i < n; i++) {
        printf("Turma %c - %i vagas disponíveis\n", turmas[i]->id, turmas[i]->vagas);
    }
}

void matricula_aluno(Turma *turma, int mat, char *nome) { 
    // Não é feito nenhuma verificação no número de vagas da turma. Isso poruqe o aluno só será adicionado
    // caso for encontrado uma vaga NULL no vetor de alunos
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            // criando um novo aluno
            Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
            aluno->mat = mat;
            strcpy(aluno->nome, nome);
            for (int j = 0; j < 3; j++) {
                aluno->notas[j] = 0.0;
            }
            aluno->media = 0.0;

            turma->alunos[i] = aluno; // adiciona o aluno na turma
            turma->vagas -= 1; // atualiza a qtd de vagas da turma para futuras impressoes
            printf("Aluno matriculado com sucesso!\n");
            return; // A função é finalizada caso a turma tenha vagas e o aluno for adicionado
        }
    }
    printf("Não há vagas na turma %c!\n", turma->id);
}

// Funcao para lancar as notas dos alunos matriculados na turma
void lanca_notas(Turma* turma) {
    
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            float media = 0.0;
            printf("Matricula: %d\tAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (int k = 0; k < 3; k++) {
                printf("Digite a nota %d: ", k+1);
                scanf("%f", &(turma->alunos[i]->notas[k]));
                media += turma->alunos[i]->notas[k];
            }
            turma->alunos[i]->media = media/3;
        }
    }   
}

void imprime_alunos(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matricula: %d\n", turma->alunos[i]->mat);
            printf("Nome: %s\n", turma->alunos[i]->nome);
            printf("Media: %.2f\n", turma->alunos[i]->media);
        } 
    } 
}

void libera_turma(Turma** turmas, int n){
    int i, k;
    for (i = 0; i < n; i++) {
        for (k = 0; k < MAX_VAGAS; k++) {
            if (turmas[i]->alunos[k] != NULL) {
                free(turmas[i]->alunos[k]);
            }
        }
        free(turmas[i]);
    }
    
}