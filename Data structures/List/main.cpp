#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

list <int> lista;
void push_front();
void push_back();
void pop_front();
void pop_back();
void size();
void max_size();
void empty();
void remove();
void sort();
void reverse();
void wyswietl_liste();
void menu();
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    menu();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void wyswietl_liste()
{
    system("CLS");
    cout<<string(30,'*')<<endl;
    for (list <int>::iterator i=lista.begin(); i!=lista.end(); i++)
        cout<<*i<<" ";
    cout<<endl<<string(30,'*')<<endl;
}

void menu()
{
    while(1)
    {
        wyswietl_liste();

        int wybor;
        cout << " MENU GLOWNE LISTY:"<<endl;
        cout << "---------------------------"<<endl;
        cout << "1.  push_front"<<endl;
        cout << "2.  push_back"<<endl;
        cout << "3.  pop_front"<<endl;
        cout << "4.  pop_back"<<endl;
        cout << "5.  size"<<endl;
        cout << "6.  max_size"<<endl;
        cout << "7.  empty"<<endl;
        cout << "8.  remove"<<endl;
        cout << "9.  sort"<<endl;
        cout << "10. reverse"<<endl;
        cout << "11. exit"<<endl;
        cout << "---------------------------"<<endl;
        cout << "Wybor: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            push_front();
            break;
        case 2:
            push_back();
            break;
        case 3:
            pop_front();
            break;
        case 4:
            pop_back();
            break;
        case 5:
            size();
            break;
        case 6:
            max_size();
            break;
        case 7:
            empty();
            break;
        case 8:
            remove();
            break;
        case 9:
            sort();
            break;
        case 10:
            reverse();
            break;
        case 11:
            exit(1);
            break;

        default:
            cout<<"blad";
            Sleep(1000);
            break;
        }
    }
}

void push_front()
{
    int x;
    cin>>x;
    lista.push_front(x);
}

void push_back()
{
    int x;
    cin>>x;
    lista.push_back(x);
}

void pop_front()
{
    lista.pop_front();
}
void pop_back()
{
    lista.pop_back();
}
void size()
{
    cout<<lista.size();
    Sleep(1000);
}

void max_size()
{
    cout<<lista.max_size();
    Sleep(1000);
}

void empty()
{
    cout<<lista.empty();
    Sleep(1000);
}

void remove()
{
    int x;
    cin>>x;
    lista.remove(x);
}

void sort()
{
    lista.sort();
}

void reverse()
{
    lista.reverse();
}
