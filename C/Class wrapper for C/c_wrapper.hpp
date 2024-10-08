#ifndef C_WRAPPER_HPP
#define C_WRAPPER_HPP

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct MyClass MyClass;
    MyClass *MyClass_new();
    void MyClass_delete(MyClass *object);
    void MyClass_doSomething(MyClass *object);
    void MyClass_setData(MyClass *object, int value);
    int MyClass_getData(MyClass *object);

#ifdef __cplusplus
}
#endif

#endif //C_WRAPPER_HPP