#include <iostream>
#include <windows.h>
using namespace std;

class Stack
{
public:
void push(int Stack[], int &Index);
void pop(int Stack[], int &Index);
void size(int Index);
const char *empty(int Index);
void Display_menu(int Stack[], int Index);
void Display_stack(int Stack[], int Index);
};

void push(int Stack[], int &Index)
{
    int Number;
    if ((Index < 5) && (Index >= 0))
    {
        cin >> Number;
        Stack[Index++] = Number;
    }
    else
    {
        cout << "Stack full!" << endl;
        Sleep(1000);
    };
}

void pop(int Stack[], int &Index)
{
    if ((Index < 6) && (Index > 0))
    {
        cout << (Stack[--Index]) << endl;
    }
    else
    {
        cout << "Stack empty!" << endl;
        Sleep(1000);
    }
}

void size(int Index)
{
    cout << "Elements: " << Index;
    Sleep(1000);
}

const char *empty(int Index)
{
    return (Index) ? "False" : "True";
}

void Display_stack(int Stack[], int Index)
{
    cout << string(30, '*') << endl;
    for (int i = Index - 1; i >= 0; i--)
    {
        cout << Stack[i] << endl;
    }
    cout << string(30, '*') << endl;
}

void Display_menu(int Stack[], int Index);

int main()
{
    int Index = 0, Stack[5];
    Display_menu(Stack, Index);
}


void Display_menu(int Stack[], int Index)
{
    int Choice;
    do
    {
        cout << "Stack Main Menu:" << endl
             << string(40, '*') << endl
             << "1. PUSH (adding element to stack) " << endl
             << "2. POP (removing element from stack) " << endl
             << "3. SIZE (how many elements on stack) " << endl
             << "4. EMPTY (is stack empty?) " << endl
             << "5. End program " << endl
             << string(40, '*') << endl
             << "Choose: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            push(Stack, Index);
            break;

        case 2:
            pop(Stack, Index);
            break;

        case 3:
            size(Index);
            break;

        case 4:
            cout << empty(Index);
            Sleep(1000);
            break;
        }
        Display_stack(Stack, Index);
    } while (Choice != 5);
}