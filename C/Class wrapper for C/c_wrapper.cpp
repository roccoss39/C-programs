#include "c_wrapper.hpp"
#include "myclass.hpp"
#include <iostream>

 MyClass *MyClass_new()
 {
    return new MyClass;
 }

 void MyClass_delete(MyClass *object)
 {
    delete object;
    std::cout<<"Object deleted.\n";
 }

void MyClass_setData(MyClass *object, int value)
{
    object->setData(value);
    std::cout<<"Data has been set.\n";
}
int MyClass_getData(MyClass *object)
{
    return object->getData();
}
 void MyClass_doSomething(MyClass *object)
 {
  std::cout << "Object data is: " << object->getData() << std::endl;
 }