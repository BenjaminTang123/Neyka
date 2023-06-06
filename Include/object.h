#ifndef OBJECT_H
#define OBJECT_H

#include <stdarg.h>
#include "config.h"

typedef struct ProcessingInCLanguage
{    
    bool CProcessing;
    void (*Method)(int count, ...);
} CProcessing;

struct Object
{
    const char *objName;
    struct Object *parent;
    struct Object *base;
    struct Object *member;
    size_t memberCount;
    char *doc;
    char *code;
};

typedef struct Object Object;

#define OBJECT_HEAD Object head

typedef struct Descriptor
{
    char *head;
    char *centre;
    char *end;
    bool internalDescriptorProcessing;
} descr;

typedef struct
{
    OBJECT_HEAD;
    descr* descriptor;
    size_t descrCount;
} DescriptorPool;


#endif