#include <stdio.h>
#include <stdlib.h>
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

    List* lista_nomes = createList();

    FILE* arquivo = reading();

    char nome[500];
    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        nome[strcspn(nome, "\n")] = '\0';
        insere_lista_inicio(lista_nomes, nome);
    }

    fclose(arquivo);

    printf("Lista de nomes lidos do arquivo:\n");
    imprime_lista(lista_nomes);

    stop_timer(&timer);
    double elapsed = elapsed_time(&timer);
    printf("Tempo de execução: %.6f segundos\n", elapsed);

    libera_lista(lista_nomes);

    return 0;
}