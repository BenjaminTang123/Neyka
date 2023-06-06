#ifndef FILE_H
#define FILE_H

#define FILE FILE*

FILE openFile(char* path);
string readFile(FILE f);
void closeFile(FILE f);

string parseSourceFile(string* workingDirectory, char* fileName);

#endif