#include "config.h"

#include "lcstring.h"
#include "file.h"

FILE openFile(char* path)
{
    /* Open file */

    FILE sourceFilePointer = fopen(path, "r");
    if(sourceFilePointer == NULL)
    {
        fprintf(stderr, "SourceFileOpeningError: Source file cannot be opened");
        exit(1);
    }

    return sourceFilePointer;
}

string readFile(FILE f)
{
    /* Read the content of file */

    string _content = initString();
    for (char t[20]; fgets(t, 20, f); ) addString(&_content, t);

    return _content;
}

inline void closeFile(FILE f)
{
    fclose(f);
}

string parseSourceFile(string* workingDirectory, char* fileName)
{
    // get source code
    string _tmpPath = copyString(workingDirectory);
    addString(&_tmpPath, PATH_SEPARATOR);
    addString(&_tmpPath, fileName);
    #ifdef __WINDOWS
    replaceString(&_tmpPath, PATH_SEPARATOR, "/");
    #endif
// printf("path: %s\n", _tmpPath.stringContent);
    FILE _f1 = openFile(_tmpPath.stringContent);
    string sourceCode = readFile(_f1);
    closeFile(_f1);
    free(_tmpPath.stringContent);

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
    sourceCode = __content;
// printf("%s\n\n", sourceCode.stringContent);

    return sourceCode;
}
