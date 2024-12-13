#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listaSimpEncadString.h" //inclui os Protótipos

// -------------------------------------------------------------------------------------
//                              Implementação das listas
// -------------------------------------------------------------------------------------
struct stringElement{
    Name data;
    struct stringElement *next;
};

struct numberElement{
    Number data;
    struct numberElement *next;
};

typedef struct stringElement ElementS;
typedef struct numberElement ElementN;

ListString* createListString(){
    ListString* list = (ListString*) malloc(sizeof(ListString));
    if(list != NULL)
        *list = NULL;
    return list;
}

ListNumber* createListNumber(){
    ListNumber* list = (ListNumber*) malloc(sizeof(ListNumber));
    if(list != NULL)
        *list = NULL;
    return list;
}

void freeStr(ListString* list){
    if(list != NULL){
        ElementS* node;
        while((*list) != NULL){
            node = *list;
            *list = (*list)->next;
            free(node);
        }
        free(list);
    }
}

void freeNumber(ListNumber* list){
    if(list != NULL){
        ElementN* node;
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
    ElementS* node;
    node = (ElementS*) malloc(sizeof(ElementS));
    if(node == NULL)
        return 0;
    node->data = name;
    node->next = (*list);
    *list = node;
    return 1;
}

// Funcao usada para iserir o arquivo .txt com os nomes em uma lista
void insert_txt(const char *name_file, ListString* list) {
    FILE *file = fopen(name_file, "r");
    if(file == NULL) {
        printf("O arquivo não pode ser aberto\n");
        exit(0);
    }

    int progresso = 1;
    printf("\nLendo o arquivo nomes_aleatorios.txt:\n");
    char linha[100];
    if(name_file != NULL) {
        while(fgets(linha, sizeof(linha), file)) {
            Name nome;
            sscanf(linha, "%[^\n]", nome.name);
            insertInit(list, nome);
            printf("\r%d", progresso);
            progresso++;
        }
    }
    fclose(file);
    printf("\nArquivo de nomes lido com sucesso!\n");
}

int insertInitNumber(ListNumber* list, Number number){
    if(list == NULL)
        return 0;
    ElementN* node;
    node = (ElementN*) malloc(sizeof(ElementN));
    if(node == NULL)
        return 0;
    node->data = number;
    node->next = (*list);
    *list = node;
    return 1;
}

// Funcao usada para iserir o arquivo .bin com os numeros em uma lista
void insert_bin(const char *name_file, ListNumber* list) {
    FILE *file = fopen(name_file, "rb");
    if(file == NULL) {
        printf("O arquivo não pode ser aberto\n");
        exit(0);
    }

    int progresso = 1;
    printf("\nLendo o arquivo %s:\n", name_file);
    if(name_file != NULL) {
        Number numero;
        while(fread(&numero, sizeof(int), 1, file)) {
            insertInitNumber(list, numero);
            printf("\r%d", progresso);
            progresso++;
        }
    }
    fclose(file);
    printf("\nArquivo de numeros lido com sucesso!\n");
}

int removeInit(ListString* list){
    if(list == NULL)
        return 0;
    if((*list) == NULL)
        return 0;

    ElementS *node = *list;
    *list = node->next;
    free(node);
    return 1;
}

int removeInitNumber(ListNumber* list){
    if(list == NULL)
        return 0;
    if((*list) == NULL)
        return 0;

    ElementN *node = *list;
    *list = node->next;
    free(node);
    return 1;
}

int sizeStr(ListString* list){
    if(list == NULL)
        return 0;
    int cont = 0;
    ElementS* node = *list;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}

int sizeNumber(ListNumber* list){
    if(list == NULL)
        return 0;
    int cont = 0;
    ElementN* node = *list;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}

// Funcao usada para escrever a lista de nomes ordenada em um arquivo
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
    ElementS* node = *list;
    while (node != NULL) {
        fprintf(file, "%s\n", node->data.name);
        node = node->next;
    }
    fclose(file);

    printf("\nLista escrita com sucesso no arquivo '%s'.\n", name_file);
}

// Funcao usada para escrever a lista de numeros ordenada em um arquivo
void writeFileNumber(ListNumber* list, const char* name_file) {
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
    ElementN* node = *list;
    while (node != NULL) {
        fprintf(file, "%d\n", node->data.number);
        node = node->next;
    }
    fclose(file);

    printf("\nLista escrita com sucesso no arquivo '%s'.\n", name_file);
}

// -------------------------------------------------------------------------------------
//                              Algoritmos de ordenação
// -------------------------------------------------------------------------------------

// Bubble sort para ordenar os nomes
void bubble_sort_nomes(ListString* list) {
    if (list == NULL || *list == NULL)
        return;

    int toggle;
    double trocas = 0;
    ElementS *node, *next = NULL;

    clock_t inicio = clock();
    do {
        toggle = 0;
        node = *list;

        while (node->next != next) {
            // (> 0) ordena de forma crescente e (< 0) ordena de forma descrescente
            if (strcmp(node->data.name, node->next->data.name) > 0) {
                Name temp = node->data;
                node->data = node->next->data;
                node->next->data = temp;

                toggle++;
                trocas++;
            }
            node = node->next;
        }
        next = node->next;
    } while (toggle != 0);
    clock_t final = clock();

    printf("\nTrocas: %.2lf\n", trocas);
    printf("Tempo: %lu ms\n", (final - inicio) * 1000 / CLOCKS_PER_SEC);
}

// Bubble sort para ordenar os numeros
void bubble_sort_numeros(ListNumber* list) {
    if (list == NULL || *list == NULL)
        return;

    int toggle;
    double trocas = 0;
    ElementN *node, *next = NULL;

    clock_t inicio = clock();
    do {
        toggle = 0;
        node = *list;

        while (node->next != next) {
            // (> 0) ordena de forma crescente e (< 0) ordena de forma descrescente
            if (node->data.number > node->next->data.number) {
                Number temp = node->data;
                node->data = node->next->data;
                node->next->data = temp;

                toggle++;
                trocas++;
            }
            node = node->next;
        }
        next = node->next;
    } while (toggle != 0);
    clock_t final = clock();

    printf("\nTrocas: %.2lf\n", trocas);
    printf("Tempo: %lu ms\n", (final - inicio) * 1000 / CLOCKS_PER_SEC);    
}

int trocas = 0;

//merge sort para ordenar os nomes
void split_list(ListString source, ListString* frontRef, ListString* backRef) {
    ListString slow = source;
    ListString fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

ListString merge_sorted_lists(ListString a, ListString b) {
    ListString result = NULL, tail = NULL;

    while (a != NULL && b != NULL) {
        ListString temp;
        if (strcmp(a->data.name, b->data.name) <= 0) {
            temp = a;
            a = a->next;
        } else {
            temp = b;
            b = b->next;
            trocas++; 
        }

        if (result == NULL) {
            result = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }

    if (a != NULL) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    return result;
}


void merge_sort_names(ListString* list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL) {
        return;
    }

    clock_t inicio = clock();

    ListString a = NULL, b = NULL;
    split_list(*list, &a, &b);
    
    merge_sort_names(&a);
    merge_sort_names(&b);
    
    *list = merge_sorted_lists(a, b);

    clock_t final = clock();
    printf("\nTrocas: %d\n", trocas);
    printf("Tempo: %lu ms\n", (final - inicio) * 1000 / CLOCKS_PER_SEC);
}


ListString create_node(char* data) {
    ListString newNode = (ListString)malloc(sizeof(ElementS));
    if (!newNode) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->data.name, data, sizeof(newNode->data.name) - 1);
    newNode->data.name[sizeof(newNode->data.name) - 1] = '\0';
    newNode->next = NULL;
    return newNode;
}

int merge_trocas_number = 0;

//merge sort para ordenar os numeros
void split_list_number(ListNumber source, ListNumber* frontRef, ListNumber* backRef) {
    ListNumber slow = source;
    ListNumber fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

ListNumber merge_sorted_lists_number(ListNumber a, ListNumber b) {
    ListNumber result = NULL, tail = NULL;

    while (a != NULL && b != NULL) {
        ListNumber temp;
        if (a->data.number <= b->data.number) {
            temp = a;
            a = a->next;
        } else {
            temp = b;
            b = b->next;
            merge_trocas_number++;
        }

        if (result == NULL) {
            result = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }

    if (a != NULL) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    return result;
}



void merge_sort_number(ListNumber* list) {
    clock_t inicio = clock();

    ListNumber head = *list;
    ListNumber a = NULL;
    ListNumber b = NULL;

    if (head == NULL || head->next == NULL) {
        return;
    }

    split_list_number(head, &a, &b);

    merge_sort_number(&a);
    merge_sort_number(&b);

    *list = merge_sorted_lists_number(a, b);

    clock_t final = clock();
    printf("\nTrocas: %d\n", merge_trocas_number);
    printf("Tempo: %lu ms\n", (final - inicio) * 1000 / CLOCKS_PER_SEC);
}


