#ifndef FILE_H
#define FILE_H

#include "tranquillity.h"

#define FILE FILE*

FILE openFile(char* path);
string readFile(FILE f);
void closeFile(FILE f);

#endif