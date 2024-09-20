#include <iostream>
#include <windows.h>
using namespace std;

class MyQueue
{
    void push(int Queue[], int &Index);
    void pop(int Queue[], int &Index);
    void size(int Index);
    const char *empty(int Index);
    void display_queue(int Queue[], int Index);
};
void push(int Queue[], int &Index)
{
    int Value;
    if ((Index<5)&&(Index>-1))
    {
        cin>>Value;
        Queue[Index++]=Value;
    }
    else
    {
        cout<<"Queue is full!"<<endl;
        Sleep(1000);
    };
}

void pop(int Queue[], int &Index)
{
    if ((Index<6)&&(Index>0))
    {
        for(int i=0;i<Index;i++)
		{
			Queue[i]=Queue[i+1];
		}
		Index--;
    }
    else
    {
        cout<<"Queue is empty!"<<endl;
        Sleep(1000);
    }
}

void size(int Index)
{
    cout<<"Elements: "<<Index;
    Sleep(1000);
}

const char* empty(int Index)
{
    return (Index) ? "False" : "True";
}

void display_queue (int Queue[], int Index)
{
    cout<<string(30,'*')<<endl;
    for (int i=0; i<Index; i++)
    {
        cout<<Queue[i]<<" ";
    }
    cout<<endl<<string(30,'*')<<endl;
}

void Display_Menu(int Queue[], int Index);

int main()
{
    int Index = 0, Queue[5];
    Display_Menu(Queue, Index);
}

void Display_Menu(int Queue[], int Index)
{
    int Choice;
    do
    {
        cout << "Queue Main Menu:" << endl
        << string(40, '*') << endl
        << "1. PUSH (add element to queue) " << endl
        << "2. POP (remove element from queue) " << endl
        << "3. SIZE (how many elements in queue?) " << endl
        << "4. EMPTY (is queue empty?) " << endl
        << "5. End program " << endl
        << string(40, '*') << endl
        << "Choose: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            push(Queue, Index);
            break;

        case 2:
            pop(Queue, Index);
            break;

        case 3:
            size(Index);
            break;

        case 4:
            cout << empty(Index);
            Sleep(1000);
            break;
        }
        display_queue(Queue, Index);
    } while (Choice != 5);
}