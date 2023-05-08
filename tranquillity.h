#ifndef TRANQUILLITY_H
#define TRANQUILLITY_H

#define __WINDOWS
// #define __LINUX

#ifdef __WINDOWS
#define __PATH_SEPARATOR "\\"
#endif
#ifdef __LINUX
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "lcstring.h"
#include "file.h"

typedef struct runningConfigure
{
    string workingDirectory;
    char* intallerDirectory;
    char* fileName;
} runningConfigure;

#endif
