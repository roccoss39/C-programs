#include "myclass.hpp"
#include <iostream>

MyClass::MyClass() : data(0) {}

MyClass::~MyClass() {}

void MyClass::doSomething() {
    std::cout << "Data value: " << data << std::endl;
}

void MyClass::setData(int value) {
    data = value;
}

int MyClass::getData() const {
    return data;
}
