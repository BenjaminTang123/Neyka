#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#include "lcstring.h"

struct Object 
{
    char* className;
    char* code;
    string path;
    struct Object* variablePool;
    size_t variablePoolCapacity;
    struct Object* inheriting;
    bool floatingScopalityThis;
};
typedef struct Object Object;

struct descriptor
{
    char* start;
    char* value;
    char* end;
    struct descriptor* link;
    Object* pointingClass;
};
typedef struct descriptor descr;

typedef struct DescriptorPool
{
    Object* HeadObject;
    descr* pool;
    unsigned short descrCount;
} DescriptorPool;

#define Function Object
#define Array Object
#define String Object

typedef struct Float
{
    Object* HeadObject;
    double content;
} Float;

typedef struct Int
{
    Object* HeadObject;
    long long int content;
} Int;

#endif