#include "pretreatment.h"

void pretreatment(char* content)
{
    string _content = initString();
    for (position i=0; content[i]!='\0'; i++)
    {
        // if 
        addCharacter(&_content, content[i]);
    }
}