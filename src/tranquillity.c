#include "config.h"

#include "lcstring.h"
#include "file.h"

int main(int argc, char **argv)
{   
    string workingDirectory;
    char* installerDirectory;
    char* fileName;
    string sourceCode;

    // get the working directory
    __TEMP__ char* buffer = (char*)malloc(200*sizeof(char));
    __TEMP__ char* res = getcwd(buffer, 200);
    if (!res)
    {
        fprintf(stderr, "DirectoryError: Unable to get current working directory\n");
        free(buffer);
        exit(1);
    }

    workingDirectory = initString();
    addString(&workingDirectory, buffer);
    free(buffer);

    if (argc >= 2)
    {
        installerDirectory = argv[0];
        fileName = argv[1];
    }
    else 
    {
        fprintf(stderr, "ParamaterError: Incoming parameter exception\n");
        exit(1);
    }

    sourceCode = parseSourceFile(&workingDirectory, fileName);

    return 0;
}
