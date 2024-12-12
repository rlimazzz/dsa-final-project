#include <stdio.h>
#include <stdlib.h>
#include "./MergeSort/mergeS.h"
#include "./ListaSimplesmenteEncadeada/listaSimpEncadString.h"
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
    
    Lista *lista_nomes = cria_lista();
    FILE *arquivo = reading();

    int progresso = 1;
    char linha[500];
    if(arquivo != NULL) {
        while(fgets(linha, sizeof(linha), arquivo)) {
            Nome nome;
            sscanf(linha, "%[^\n]", nome.nome);
            insere_lista_inicio(lista_nomes, nome);
            printf("\r%d", progresso);
            progresso++;
        }
    }
    fclose(arquivo);
    printf("\nArquivo lido com sucesso!\n");

    bubble_sort_nomes(lista_nomes);
    printf("\nOrdenado com sucesso!\n");
    
    stop_timer(&timer);

    double elapsed = elapsed_time(&timer);
    printf("Tempo de execução: %.6f segundos\n", elapsed);

    libera_lista(lista_nomes);
    return 0;
}
