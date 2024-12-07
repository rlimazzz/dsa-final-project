#include <stdio.h>
#include <stdlib.h>
#include "./QuickSort/quickS.h"
#include "./MergeSort/mergeS.h"
#include "./ListaSimplesmenteEncadeada/listaSimpEncad.h"
#include "./Timer/timer.h"

FILE *reading() {
    FILE *file = fopen("./ArquivoLeitura/nomes_aleatorios.txt", "r");

    if(file == NULL) {
        printf("O arquivo não pode ser aberto\n");
        exit(0);
    }

    return file;
}

int main() {
    Timer timer;

    start_timer(&timer);
    printf("Olá mundo\n");

    FILE *arquivo = reading();

    char nomes[500];

    if(arquivo != NULL) {
        while(fgets(nomes, 500, arquivo) != NULL) {
            printf("%s", nomes);
        }
    }

    fclose(arquivo);

    stop_timer(&timer);

    double elapsed = elapsed_time(&timer);
    printf("Tempo de execução: %.6f segundos\n", elapsed);
    return 0;
}