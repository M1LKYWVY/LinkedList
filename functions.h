//
// Created by Dreamer on 01/12/2017.
//

#ifndef SPLLAB4_FUNCTIONS_H
#define SPLLAB4_FUNCTIONS_H

typedef struct LinkedList {
    int value;
    struct LinkedList *node;
} lList;

struct LinkedList* listCreate(int number);
void listAddFront(int number, struct LinkedList **list);
void listAddBack(int number, struct LinkedList **list);
int listGet(int index, struct LinkedList *list);
void listFree(struct LinkedList *list);
int listLength(struct LinkedList *list);
struct LinkedList* listGetAt(int index, struct LinkedList *list);
int listSum(struct LinkedList *list);


#endif //SPLLAB4_FUNCTIONS_H


