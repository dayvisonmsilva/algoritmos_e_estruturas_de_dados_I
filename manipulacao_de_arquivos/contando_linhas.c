#include <stdio.h>
#include <stdlib.h>

int main () {
    int c;
    int nlinhas = 0;
    FILE *fp = fopen("entrada.txt", "rt");

    if (fp == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    // Leitura de caracteres 
    /* while ((c=fgetc(fp)) != EOF) {
        nlinhas++;
    }*/
    
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') 
            nlinhas++;  
    }

    fclose(fp);
    printf("Numero de linhas  = %d\n", nlinhas); 
    return 0;
}