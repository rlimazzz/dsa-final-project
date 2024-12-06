#include <stdio.h>
#include <stdlib.h>
#include "./QuickSort/quickS.h"
#include "./MergeSort/mergeS.h"
#include "./ListaSimplesmenteEncadeada/listaSimpEncad.h"

FILE *reading() {
    FILE *file = fopen("./ArquivoLeitura/nomes_aleatorios.txt", "r");

    if(file == NULL) {
        printf("O arquivo não pode ser aberto\n");
        exit(0);
    }

    return file;
}

int main() {
    FILE *arquivo = reading();

    char nomes[500];

    if(arquivo != NULL) {
        while(fgets(nomes, 500, arquivo) != NULL) {
            printf("%s", nomes);
        }
    }

    fclose(arquivo);
    return 0;
}