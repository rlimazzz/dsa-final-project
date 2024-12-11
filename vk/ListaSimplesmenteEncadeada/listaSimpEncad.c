#include <stdlib.h>
#include <stdio.h>
#include "listaSimpEncad.h"

struct element {
    int data;
    struct element *next;
};

List* createList() {
    List* list = (List*) malloc(sizeof(List));

    if(list != NULL) {
        *list = NULL;
    }

    return list;
}

void freeList(List* list) {
    if (list != NULL) {
        Element* node;
        while ((*list) != NULL) {
            node = *list;
            *list = (*list)->next;
            free(node);
        }
        free(list);
    }
}

int appendInit(List *list, int element) {
    if (list == NULL) {
        return -1;
    }

    Element* node = (Element*) malloc(sizeof(element));
    if (node == NULL) {
        return -2;
    }

    node->data = element;
    node->next = (*list);
    *list = node;
    return 1;
}

int deleteInit(List* list) {
    if (list == NULL || (*list) == NULL) {
        return -1;
    }

    Element *node = *list;
    *list = node->next;
    free(node);
    return 1;
}

int removeFirst(List *list, int number) {
    if (list == NULL || (*list) == NULL || number <= 0) {
        return -1;
    }

    for (int i = 0; i < number; i++) {
        Element *node = *list;
        *list = node->next;
        free(node);
        if (*list == NULL) {
            break;
        }
    }
    return 1;
}

int removeLast(List *list, int number) {
    if (list == NULL || (*list) == NULL || number <= 0) {
        return -1;
    }

    Element *penult = NULL, *last = *list;
    int total = 0;

    while (last != NULL) {
        total++;
        last = last->next;
    }

    if (number >= total) {
        freeList(list);
        *list = NULL;
        return 1;
    }

    penult = *list;
    for (int i = 1; i < total - number; i++) {
        penult = penult->next;
    }

    Element* current = penult->next;
    penult->next = NULL;
    while (current != NULL) {
        Element* temp = current;
        current = current->next;
        free(temp);
    }

    return 1;
}

void print(List *list) {
    if (list == NULL || *list == NULL) { 
        printf("A lista está vazia.\n");
        return;
    }

    Element *node = *list;
    while (node != NULL) {
        printf("Váriavel: %d\n", node->data); 
        node = node->next;
    }
}