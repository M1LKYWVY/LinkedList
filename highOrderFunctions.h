//
// Created by Dreamer on 03/12/2017.
//
#include <endian.h>
#include "functions.h"
#ifndef SPLLAB4_HIGHORDERFUNCTIONS_H
#define SPLLAB4_HIGHORDERFUNCTIONS_H

void foreach(lList *list, void (*fp)(int));
lList * map(struct LinkedList *list, int (*fp)(int));
struct LinkedList* map_mut(struct LinkedList *list, int (*fp)(int));
int foldl(struct LinkedList *list, int accumulator, int (*fp)(int,int));
struct LinkedList* iterate(int initial, int (*fp)(int), size_t length);

#endif //SPLLAB4_HIGHORDERFUNCTIONS_H
