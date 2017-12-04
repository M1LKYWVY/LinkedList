//
// Created by Dreamer on 04/12/2017.
//

#include <stdio.h>
#include "io.h"
#include "functions.h"
#include "highOrderFunctions.h"

FILE *file;

 void saveInt(int value) {
    fprintf(file,"%d ",value);
}

 int readInt() {
    int value;
    fscanf(file,"%d", &value);
    return value;
}

 void saveIntB(int value) {
    fwrite(&value,sizeof(int),1,file);
}

 int readIntB() {
    int value;
    fread(&value,sizeof(int),1,file);
    return value;
}

bool save(lList* first, const char* filename) {
    file = fopen(filename, "w");
    if(!file)
        return false;
    foreach(first, &saveInt);
    fclose(file);
    return true;
}

bool load(lList** first, const char* filename) {
    file = fopen(filename, "r");
    if(!file)
        return false;
    int value;
    while (fscanf(file, "%d", &value)!=EOF) {

        listAddBack(value, first);
    }
    fclose(file);
    return true;

}

bool serialize(lList* first, const char* filename){
    file = fopen(filename, "wb");
    if(!file)
        return false;
    foreach(first, &saveIntB);
    fclose(file);
    return true;
}

bool deserialize(lList** first, const char* filename){
    file = fopen(filename, "rb");
    if(!file)
        return false;
    map_mut(*first, (int (*)(int)) &readIntB);
    fclose(file);
    return true;
}