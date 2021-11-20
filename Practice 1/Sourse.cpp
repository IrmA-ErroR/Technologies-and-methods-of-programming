// Source.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bounded_random(l, h) ( rand() % ((h) - (l) + 1) + (l) )

typedef struct NODE {
    int value;
    struct NODE* next;
} node_t;

typedef struct LIST {
    node_t* first;
    node_t* last;
} list_t;

list_t* new_list(void) {
    list_t* list = (list_t*)malloc(sizeof(list_t));
    if (!list)
        return NULL;

    list->first = list->last = NULL;

    return list;
}

void del_list(list_t* list) {
    while (list->first) {
        list->last = list->first->next;
        free(list->first);
        list->first = list->last;
    }

    free(list);
}

int push(list_t* list, const int value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if (!node)
        return -1;

    node->value = value;
    node->next = NULL;

    if (!list->first)
        list->first = node;
    else
        list->last->next = node;
    list->last = node;

    return 0;
}

void dump(const list_t* list) {
    const node_t* node = list->first;

    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }

    printf("\n");
}

int max_value(const list_t* list) {
    const node_t* maxnode, * node;

    for (maxnode = list->first, node = list->first->next; node; node = node->next)
        if (maxnode->value < node->value)
            maxnode = node;

    return maxnode->value;
}

#define LOW (0)
#define HIGH (99)

int main(void) {
    size_t count;

    srand(time(NULL));

    while (printf("Number fo elements: ") && scanf("%u", &count) == 1 && count) {
        list_t* list = new_list();
        if (!list) {
            fprintf(stderr, "Memory error!\n");
            exit(1);
        }

        while (count--) {
            if (push(list, bounded_random(LOW, HIGH))) {
                fprintf(stderr, "Memory error!\n");
                exit(1);
            }
        }

        printf("All values:\n");
        dump(list);
        printf("Max value: %d\n", max_value(list));

        del_list(list);
    }

    exit(0);
}

