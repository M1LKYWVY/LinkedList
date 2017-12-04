#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <stdbool.h>
#include "functions.h"
#include "highOrderFunctions.h"
#include "io.h"

#define MAX 20

int abs(int arg) {
    return arg>0 ? arg : arg*(-1);
}

int bigger(int a, int b) {
    return a > b ? a:b;
}

int smaller(int a, int b) {
    return a < b ? a:b;
}

int adder(int a, int b) {
    return a+b;
}

void printValue(int arg) {
    printf("%d ", arg);
}

void printValueLine(int arg) {
    printf("%d\n", arg);
}

void printNewLine() {
   putchar('\n');
}

void printSpace() {
    putchar(' ');
}

int square(int arg) {
    return arg*arg;
}

int cube(int arg) {
    return arg*arg*arg;
}

int multiply(int arg) {
    return arg*2;
}

int main() {
    puts("Type integers to fill array as in example.\n"
                 "Example: 1 2 3 5");
    int value;
    int size = 0;
    scanf("%d", &value);
    lList *list = listCreate(value);
    size++;
    while((scanf("%d", &value) != EOF)) {
        size++;
        if (size == MAX) {
            puts("Too much integers.");
            return 0;
        }
        listAddFront(value, &list);
        char ch;
        scanf("%c",&ch);
        if (ch=='\n') {
            break;
        }
    }
    puts("Each with spaces:\n");
    foreach(list, &printValue);
    printNewLine();
    puts("Each with lines:\n");
    foreach(list, &printValueLine);
    printNewLine();
    lList *squareList = map(list, &square);
    puts("Square:\n");
    foreach(squareList, &printValueLine);
    listFree(squareList);
    printNewLine();
    lList *cubeList = map(list, &cube);
    puts("Cube:\n");
    foreach(cubeList, &printValueLine);
    listFree(cubeList);
    printNewLine();
    printf("Biggest element is %d\n", foldl(list, INT_MIN, bigger));
    printf("Smallest element is %d\n", foldl(list, INT_MAX, smaller));
    printf("Sum of element is %d\n", foldl(list, 0, adder));
    map_mut(list, &abs);
    puts("abs:\n");
    foreach(list, &printValueLine);
    lList *powerOf2 = iterate(2, multiply, 10);
    puts("Power of 2:\n");
    foreach(powerOf2, printValueLine);
    listFree(powerOf2);
    if (save(list, "info.txt")) {
        puts("Saved into info.txt\n");
    }
    else {
        puts("Did not save to info.txt\n");
    }

    if (load(&list, "info.txt")) {
        puts("Loaded from info.txt\n");
    }
    else {
        puts("Did not load from info.txt\n");
    }

    if (serialize(list, "info.bin")) {
        puts("Serialized into info.bin\n");
    }
    else {
        puts("Did not serialize into info.bin\n");
    }
    if (deserialize(&list, "info.bin")) {
        puts("Serialized from info.bin\n");
    }
    else {
        puts("Did not serialize from info.bin\n");
    }
    listFree(list);
    return 0;

}