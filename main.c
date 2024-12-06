#include <stdio.h>
#include <stdlib.h>
#include "./QuickSort/quickS.h"
#include "./MergeSort/mergeS.h"
#include "./ListaSimplesmenteEncadeada/listaSimpEncad.h"

FILE *reading() {
    FILE *file = fopen("./arquivoLeitura/nomes_aleatorios.txt", "r");

    if(file == NULL) {
        printf("O arquivo não pode ser aberto\n");
        exit(0);
    }

    return file;
}

int main() {
    FILE *arquivo = reading();

    
    return 0;
}