#include <stdio.h>
#include <stdlib.h>
#include "./ListaSimplesmenteEncadeada/listaSimpEncadString.h"

int main(){

    ListNumber *lista_numeros = createListNumber();
    //ListString *lista_nomes = createListString();
    
    //printf("Digite o numero da entrada numerica que eleva 10:\n");
    char file_name[35];
    //int num;
    //scanf("%d", &num);
    int num = 6;
    sprintf(file_name, "ArquivoLeitura/numeros_10^%d.bin", num);

    insert_bin(file_name, lista_numeros);
    //insert_txt("ArquivoLeitura/nomes_aleatorios.txt", lista_nomes);

    //printf("\nBubble Sort para entrada numerica:");
    //bubble_sort_numeros(lista_numeros);

    //printf("\nBubble Sort para entrada textual:");
    //bubble_sort_nomes(lista_nomes);

    //printf("\nMerge Sort para entrada textual:");
    //merge_sort_names(lista_nomes);

    printf("\nMerge Sort para entrada numerica:");
    merge_sort_number(lista_numeros);

    // escrevendo os arquivos ordenados
    writeFileNumber(lista_numeros, "numeros_ordenados.txt");
    //writeFileStr(lista_nomes, "nomes_ordenados.txt");

    freeNumber(lista_numeros);
    //freeStr(lista_nomes);
}
