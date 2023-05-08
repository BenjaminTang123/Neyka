#include "tranquillity.h"

void deleteBlank(string* content)
{
    /* delete blank in code */
    char* _content = content->stringContent;

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
    *content = __content;

    replaceString(content, "\t", "");
    replaceString(content, "\n", "");
}

void parseSourceFile(runningConfigure* configure)
{
    // get source code
    string _tmpPath = copyString(&configure->workingDirectory);
    addString(&_tmpPath, __PATH_SEPARATOR);
    addString(&_tmpPath, configure->fileName);
    #ifdef __WINDOWS
    replaceString(&_tmpPath, __PATH_SEPARATOR, "/");
    #endif
    printf("path: %s\n", _tmpPath.stringContent);
    FILE _f1 = openFile(_tmpPath.stringContent);
    string sourceCode = readFile(_f1);
    closeFile(_f1);
    free(_tmpPath.stringContent);

    deleteBlank(&sourceCode);
    /* delete blank in code */
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
    *content = __content;

    replaceString(content, "\t", "");
    replaceString(content, "\n", "");

    printf("%s\n\n", sourceCode.stringContent);
}

int main(int argc, char **argv)
{   
    runningConfigure configure;

    // get the working directory 
    char* buffer = (char*)malloc(200*sizeof(char));
    char* res = getcwd(buffer, 200);
    if (!res)
    {
        fprintf(stderr, "DirectoryError: Unable to get current working directory\n");
        exit(1);
    }
    configure.workingDirectory = initString();
    addString(&configure.workingDirectory, buffer);
    free(buffer);

    // get the file name to be run
    if (argc >= 2)
    {
        configure.intallerDirectory = argv[0];
        configure.fileName = argv[1];
    }
    else 
    {
        fprintf(stderr, "ParamaterError: Incoming parameter exception\n");
        exit(1);
    }

    parseSourceFile(&configure);

    return 0;
}
