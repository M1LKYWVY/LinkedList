
//
// Created by Dreamer on 03/12/2017.
//

#include <stdio.h>
#include "highOrderFunctions.h"
#include "functions.h"

void foreach(lList *list, void (*fp)(int)) {
    lList *listNode = list;
    while (listNode) {
        fp(listNode->value);
        listNode = listNode->node;
    }
}

struct LinkedList* map(lList *list, int (*fp)(int)) {
    lList *listNode = listCreate(fp(list->value));
    list = list->node;
    while (list) {
        listAddBack(fp(list->value), &listNode);
        list = list->node;
    }
    return listNode;
}

struct LinkedList* map_mut(struct LinkedList *list, int (*fp)(int)) {
    lList *listNode = list;
    while (listNode) {
        listNode->value = fp(listNode->value);
        listNode = listNode->node;
    }
    return listNode;
}

int foldl(struct LinkedList *list, int accumulator, int (*fp)(int,int)) {                                                                       \
    if (!list) return 0;
    lList * current = list;
    while (current)
    {
        accumulator = fp(current->value, accumulator);
        current = current->node;
    }
    return accumulator;
}

struct LinkedList* iterate(int initial, int (*fp)(int), size_t length) {
    lList *listNode = listCreate(initial);
    int size = (int) length;
    for (int i = 1; i<size; ++i) {
        initial = fp(initial);
        listAddBack(initial, &listNode);
    }
    return listNode;
}