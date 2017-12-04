//
// Created by Dreamer on 04/12/2017.
//

#ifndef SPLLAB4_IO_H
#define SPLLAB4_IO_H

#include <stdbool.h>
#include "functions.h"

bool save(lList* first, const char* filename);
bool load(lList** first, const char* filename);
bool serialize(lList* first, const char* filename);
bool deserialize(lList** first, const char* filename);

#endif //SPLLAB4_IO_H
