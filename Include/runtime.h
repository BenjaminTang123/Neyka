#ifndef RUNTIME_H
#define RUNTIME_H

#include "object.h"

// Running configure
typedef struct runningConfigure
{
    string workingDirectory;
    char* intallerDirectory;
    char* fileName;
} runningConfigure;
runningConfigure configure;

// Be used to store various Object objects at runtime
Object* runningLevel;

void run(char* code);

#endif