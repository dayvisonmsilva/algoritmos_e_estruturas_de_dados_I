#include <stdio.h>

typedef enum mes {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Mes;

typedef struct data {
    int dia;
    int ano;
    Mes mes;
}Data;

void cadastraData(Data *PData){
    printf("Digite o dia: ");
    scanf("%d", &PData->dia);
    printf("Digite o ano: ");
    scanf("%d", &PData->ano);
    printf("Digite o mês: ");
    scanf(" %d", (int*)&PData->mes);
}

void exibeData(Data *PData){
    printf("%.2d/", PData->dia);
    switch (PData->mes) {
        case JANEIRO:
            printf("01");
            break;
        case FEVEREIRO:
            printf("02");
            break;
        case MARCO:
            printf("03");
            break;
        case ABRIL:
            printf("04");
            break;
        case MAIO:
            printf("05");
            break;
        case JUNHO:
            printf("06");
            break;
        case JULHO:
            printf("07");
            break;
        case AGOSTO:
            printf("08");
            break;
        case SETEMBRO:
            printf("09");
            break;
        case OUTUBRO:
            printf("10");
            break;
        case NOVEMBRO:
            printf("11");
            break;
        case DEZEMBRO:
            printf("12");
            break;
        default:
            printf("DESCONHECIDO");
            break;
    }
    printf("/%.2d\n", PData->ano);
}

int main() {
    Data data;

    cadastraData(&data);
    exibeData(&data);
    return 0;
}