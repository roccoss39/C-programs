// main.c (kod C)

#include "c_wrapper.hpp"

int main() {
    MyClass* myObject = MyClass_new();  
    MyClass_setData(myObject, 20);
    MyClass_doSomething(myObject);      
    MyClass_delete(myObject);           
    return 0;
}
