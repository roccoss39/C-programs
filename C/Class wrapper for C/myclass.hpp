#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class MyClass {
public:
    MyClass();
    ~MyClass();

    void doSomething();
    void setData(int value);
    int getData() const;

private:
    int data;
};

#endif // MYCLASS_HPP
