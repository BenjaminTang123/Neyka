#include "object.h"

Object* initObject(char* className, char* code,  char* path, Object* inheriting)
{
    /*
     * By default, the variablePool capacity of the new Object is 0
     * Object needs to free
    */

    Object* obj = (Object*)malloc(sizeof(Object));

    // the class name is also type name
    obj->className = className;
    // if it does not exist or the code has been parsed, code's value is NULL
    obj->code = code;
    // path is used to control the scope
    string objectPath = initString();
    addString(&objectPath, path);
    obj->path = objectPath;
    // variable pool configure
    obj->variablePool = NULL;
    obj->variablePoolCapacity = 0;
    // inherits from which class
    // the subclass can call the variablePool of the parent class
    obj->inheriting = inheriting;
    /*
     * Determines the lookup of `this` pointer. 
     * This attribute determines the location of the variable controlled by `this` pointer. 
     * If this attribute is true and the attribute of the Object at the upper level is also true, 
     * the scope will float up until the attribute of the Object at the upper level is false.
     * The attribute is false by default
    */
    obj->floatingScopalityThis = false;
}