#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "tranquillity.h"
#include "lcstring.h"
#include "file.h"

void parseSourceFile(string* workingDirectory, char* fileName)
{
    // get source code
    string _tmpPath = copyString(workingDirectory);
    addString(&_tmpPath, __PATH_SEPARATOR);
    addString(&_tmpPath, fileName);

    #ifdef __WINDOWS
    replaceString(&_tmpPath, __PATH_SEPARATOR, "/");
    #endif

    // printf("path: %s\n", _tmpPath.stringContent);
    FILE _f1 = openFile(_tmpPath.stringContent);
    string sourceCode = readFile(_f1);
    closeFile(_f1);
    free(_tmpPath.stringContent);

    // delete blank in code
    char* _content = sourceCode.stringContent;

    string __content = initString();
    short _stringMode = false;
    short _commentMode = 0;
    for (position i=0; _content[i]!='\0'; i++)
    {
        if (_content[i] == '"' && _content[i] == '\'' && _commentMode == 0) _stringMode = !_stringMode;
        if (_content[i] == '/' && _content[i+1] == '/' && _stringMode == false && _commentMode == 0) _commentMode = 1;
        if (_content[i] == '/' && _content[i+1] == '*' && _stringMode == false && _commentMode == 0) _commentMode = 2;
        if (_content[i] == '*' && _content[i+1] == '/' && _stringMode == false && _commentMode == 2) { i += 2; _commentMode = 0;}
        if (_content[i] == '\n' && _commentMode == 1) _commentMode = 0;
        if (_commentMode == 0) addCharacter(&__content, _content[i]);
    }
    free(_content);
    sourceCode = __content;

    replaceString(&sourceCode, "\t", "");
    replaceString(&sourceCode, "\n", "");
    printf("%s\n\n", sourceCode.stringContent);
}

int main(int argc, char **argv)
{   
    string workingDirectory;
    char* intallerDirectory;
    char* fileName;

    // get the working directory 
    char* buffer = (char*)malloc(200*sizeof(char));
    char* res = getcwd(buffer, 200);
    if (!res)
    {
        fprintf(stderr, "DirectoryError: Unable to get current working directory\n");
        exit(1);
    }
    workingDirectory = initString();
    addString(&workingDirectory, buffer);
    free(buffer);

    // get the file name to be run
    if (argc >= 2)
    {
        intallerDirectory = argv[0];
        fileName = argv[1];
    }
    else 
    {
        fprintf(stderr, "ParamaterError: Incoming parameter exception\n");
        exit(1);
    }

    parseSourceFile(&workingDirectory, fileName);

    return 0;
}
