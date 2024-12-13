#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./ListaSimpEncad/listaSimpEncad.h"

int main(){
    int menu; 
    printf("Qual algoritmo deseja utilizar?\n1. Bubble Sort\n2. Merge Sort\n> ");
    scanf("%d", &menu);

    switch (menu){
        case 1:
            int escolha1;
            printf("Escolha um tipo de entrada:\n1. Numerica\n2. Textual\n> ");
            scanf("%d", &escolha1);
            switch (escolha1){
                case 1:
                    ListNumber *lista_numeros_crescente = createListNumber();
                    ListNumber *lista_numeros_decrescente = createListNumber();
                    printf("Digite o valor da entrada numerica que eleva 10:\n> ");
                    char file_name[35];
                    int num;
                    scanf("%d", &num);
                    sprintf(file_name, "ArquivoLeitura/numeros_10^%d.bin", num);

                    insert_bin(file_name, lista_numeros_crescente);
                    insert_bin(file_name, lista_numeros_decrescente);

                    printf("\n---------- Ordenacao em ordem crescente ----------");
                    bubble_sort_numeros_crescente(lista_numeros_crescente);

                    printf("\n---------- Ordenacao crescente da lista crescente ----------");
                    bubble_sort_numeros_crescente(lista_numeros_crescente);

                    printf("\n---------- Ordenacao em ordem decrescente ----------");
                    bubble_sort_numeros_decrescente(lista_numeros_decrescente);

                    printf("\n---------- Ordenacao crescente da lista decrescente ----------");
                    bubble_sort_numeros_crescente(lista_numeros_decrescente);

                    // escrevendo os arquivos ordenados
                    writeFileNumber(lista_numeros_crescente, "numeros_ordenados.txt");
                    freeNumber(lista_numeros_crescente);
                    freeNumber(lista_numeros_decrescente);
                    break;
                case 2:
                    ListString *lista_nomes = createListString();
                    insert_txt("ArquivoLeitura/nomes_aleatorios.txt", lista_nomes);

                    printf("\nBubble Sort para entrada textual:");
                    bubble_sort_nomes(lista_nomes);

                    // escrevendo os arquivos ordenados
                    writeFileStr(lista_nomes, "nomes_ordenados.txt");
                    freeStr(lista_nomes);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            int escolha2;
            printf("Escolha um tipo de entrada:\n1. Numerica\n2. Textual\n> ");
            scanf("%d", &escolha2);
            switch (escolha2){
                case 1:
                    ListNumber *lista_numeros_crescente = createListNumber();
                    ListNumber *lista_numeros_decrescente = createListNumber();

                    printf("Digite o valor da entrada numerica que eleva 10:\n> ");
                    char file_name[35];
                    int num;
                    scanf("%d", &num);
                    sprintf(file_name, "ArquivoLeitura/numeros_10^%d.bin", num);

                    insert_bin(file_name, lista_numeros_crescente);
                    insert_bin(file_name, lista_numeros_decrescente);
                    
                    clock_t inicio_1, inicio_2, inicio_3, inicio_4;
                    clock_t final_1, final_2, final_3, final_4;

                    double troca_count_1 = 0;
                    printf("\n---------- Ordenacao em ordem crescente ----------");
                    inicio_1 = clock();
                    merge_sort_number_crescente(lista_numeros_crescente, &troca_count_1);
                    final_1 = clock();
                    printf("\nTrocas: %.2lf\n", troca_count_1);
                    printf("Tempo: %lu ms\n", (final_1 - inicio_1) * 1000 / CLOCKS_PER_SEC);
                    
                    double troca_count_2 = 0;
                    printf("\n---------- Ordenacao crescente da lista crescente ----------");
                    inicio_2 = clock();
                    merge_sort_number_crescente(lista_numeros_crescente, &troca_count_2);
                    final_2 = clock();
                    printf("\nTrocas: %.2lf\n", troca_count_2);
                    printf("Tempo: %lu ms\n", (final_2 - inicio_2) * 1000 / CLOCKS_PER_SEC);

                    double troca_count_3 = 0;
                    printf("\n---------- Ordenacao em ordem decrescente ----------");
                    inicio_3 = clock();
                    merge_sort_number_decrescente(lista_numeros_decrescente, &troca_count_3);
                    final_3 = clock();
                    printf("\nTrocas: %.2lf\n", troca_count_3);
                    printf("Tempo: %lu ms\n", (final_3 - inicio_3) * 1000 / CLOCKS_PER_SEC);


                    double troca_count_4 = 0;
                    printf("\n---------- Ordenacao crescente da lista decrescente ----------");
                    inicio_4 = clock();
                    merge_sort_number_crescente(lista_numeros_decrescente, &troca_count_4);
                    final_4 = clock();
                    printf("\nTrocas: %.2lf\n", troca_count_4);
                    printf("Tempo: %lu ms\n", (final_4 - inicio_4) * 1000 / CLOCKS_PER_SEC);

                    // escrevendo os arquivos ordenados
                    char destino_file_name[60];
                    sprintf(destino_file_name, "ListasOrdenadasGeradas/numeros_10^%d.bin", num);
                    writeFileNumber(lista_numeros_crescente, destino_file_name);
                    freeNumber(lista_numeros_crescente);
                    freeNumber(lista_numeros_decrescente);
                    break;
                case 2:
                    ListString *lista_nomes = createListString();
                    insert_txt("ArquivoLeitura/nomes_aleatorios.txt", lista_nomes);

                    printf("\nMerge Sort para entrada textual:");

                    double troca_count = 0;

                    clock_t inicio = clock();
                    merge_sort_names(lista_nomes, &troca_count);
                    clock_t final = clock();

                    printf("\nTrocas: %.2lf\n", troca_count);
                    printf("Tempo: %lu ms\n", (final - inicio) * 1000 / CLOCKS_PER_SEC);

                    // escrevendo os arquivos ordenados
                    writeFileStr(lista_nomes, "ListasOrdenadasGeradas/nomes_ordenados.txt");
                    freeStr(lista_nomes);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return 0;
}
