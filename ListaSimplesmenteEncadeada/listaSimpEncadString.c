#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimpEncadString.h" //inclui os Protótipos

//Definição do tipo lista
struct stringElement{
    Name data;
    struct stringElement *next;
};
typedef struct stringElement Element;

ListString* createListString(){
    ListString* list = (ListString*) malloc(sizeof(ListString));
    if(list != NULL)
        *list = NULL;
    return list;
}

void freeStr(ListString* list){
    if(list != NULL){
        Element* node;
        while((*list) != NULL){
            node = *list;
            *list = (*list)->next;
            free(node);
        }
        free(list);
    }
}

int insertInit(ListString* list, Name name){
    if(list == NULL)
        return 0;
    Element* node;
    node = (Element*) malloc(sizeof(Element));
    if(node == NULL)
        return 0;
    node->data = name;
    node->next = (*list);
    *list = node;
    return 1;
}

int removeInit(ListString* list){
    if(list == NULL)
        return 0;
    if((*list) == NULL)
        return 0;

    Element *node = *list;
    *list = node->next;
    free(node);
    return 1;
}

int sizeStr(ListString* list){
    if(list == NULL)
        return 0;
    int cont = 0;
    Element* node = *list;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}

void writeFileStr(ListString* list, const char* name_file) {
    if (list == NULL || *list == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Abre o arquivo em modo de escrita
    FILE *file = fopen(name_file, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", name_file);
        return;
    }

    // Percorre a lista e escreve cada elemento em uma nova linha
    Element* node = *list;
    while (node != NULL) {
        fprintf(file, "%s\n", node->data.name);
        node = node->next;
    }
    fclose(file);

    printf("Lista escrita com sucesso no arquivo '%s'.\n", name_file);
}

//Algoritmos de ordenação

void bubble_sort_nomes(ListString* list) {
    if (list == NULL || *list == NULL)
        return;

    int toggle;
    Element* node;
    int limit = sizeStr(list);
    printf("%d\n", limit);
    do {
        toggle = 0;
        node = *list;

        for (int i = 0; i < limit - 1; i++) {
            if (strcmp(node->data.name, node->next->data.name) > 0) {
                Name temp = node->data;
                node->data = node->next->data;
                node->next->data = temp;
                toggle = 1;
            }
            node = node->next;
        }
        printf("\r%d", limit);
        limit--; 
    } while (toggle);
}
