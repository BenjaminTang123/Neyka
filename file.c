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

void closeFile(FILE f)
{
    fclose(f);
}