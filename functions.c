//
// Created by Dreamer on 01/12/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

struct LinkedList* makeNode() {
    lList *listNode = (lList*) malloc(sizeof(lList));
    if(!listNode)
        exit(EXIT_FAILURE);
    return listNode;
}

struct LinkedList* listCreate(int number) {
    lList *listNode = makeNode();
    listNode->value = number;
    listNode->node = NULL;
    return listNode;
}

void listAddFront(int number, struct LinkedList **list) {
    lList *listNode = makeNode();
    listNode->value = number;
    listNode->node = *list;
    *list = listNode;
}

void listAddBack(int number, struct LinkedList **list) {
    lList *listNode = *list;
    while (listNode->node) listNode = listNode->node;
    lList *newListNode = makeNode();
    listNode->node = newListNode;
    newListNode->value = number;
    newListNode->node = NULL;
}

int listGet(int index, struct LinkedList *list) {
    lList *listNode = listGetAt(index, list);
    if (listNode) {
        return listNode->value;
    }
    else {
        return 0;
    }
}

struct LinkedList* listGetAt(int index, struct LinkedList *list) {
    lList *listNode = list;
    while (index--) {
        if (!list) {
            return NULL;
        }
        listNode = listNode->node;
    }
    return listNode;
}

int listLength(struct LinkedList *list) {
    lList *listNode = list;
    int count = 0;
    while (listNode) {
        count++;
        listNode = listNode->node;
    }
    return count;
}

void listFree(struct LinkedList *list) {
    if (list) {
        listFree(list->node);
        free(list);
    }
}

int listSum(struct LinkedList *list) {
    lList *listNode = list;
    int sum = 0;
    while (listNode) {
        sum+=listNode->value;
        listNode = listNode->node;
    }
    return sum;
}
