/*
 * Choose based on different operating systems
*/ 
#define __WINDOWS
// #define __LINUX

#ifdef __WINDOWS
#   define PATH_SEPARATOR "\\"
#endif
#ifdef __LINUX
#   define __LINUX
#endif

#ifndef __TEMP__
#   define __TEMP__
#endif

#ifndef _STDIO_H
#   include <stdio.h>
#endif
#ifndef _GLIBCXX_STDLIB_H
#   include <stdlib.h>
#endif
#ifndef _STDBOOL_H
#   include <stdbool.h> 
#endif
