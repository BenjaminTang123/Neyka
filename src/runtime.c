#include "runtime.h"

void initRunningLevel(void)
{
    runningLevel = (Object*)malloc(sizeof(Object));
    runningLevel->className = "RunningLevel";
    runningLevel->code = NULL;
    string path = initString();
    addString(&path, "runtime");
    runningLevel->path = path;  

}

void run(char* code)
{
    /* 
     * This function is used to run the passed in code
     * Parameter `code` needs to free
    */
}