//Program napisany na podstawie kursu znajduj¹cego siê na stronie https://miroslawzelent.pl/
#include <iostream>
#include <windows.h>
using namespace std;

void push(int stos[], int &ind);
void pop(int stos[], int &ind);
void size(int ind);
const char* empty(int index);
void wyswietl_menu (int stos[], int index);
void wyswietl_stos (int stos[], int index);

int main()
{
    int index=0, stos[5];
    wyswietl_menu (stos,index);
}

void wyswietl_menu (int stos[], int index)
{
    int wybor;
    do
    {
        cout << "MENU GLOWNE STOSU:"<<endl;
        cout<<string(40,'*')<<endl;
        cout << "1. PUSH (dodaje element na szczyt stosu) "<<endl;
        cout << "2. POP (usuwa element ze szczytu stosu) "<<endl;
        cout << "3. SIZE (ile elementow na stosie) "<<endl;
        cout << "4. EMPTY (czy stos jest pusty?) "<<endl;
        cout << "5. Koniec programu "<<endl;
        cout<<string(40,'*')<<endl;
        cout << "Wybor: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            push(stos, index);
            break;

        case 2:
            pop(stos, index);
            break;

        case 3:
            size(index);
            break;

        case 4:
            cout<<empty(index);
			   Sleep(1000);
            break;

        }
        wyswietl_stos(stos,  index);
    }
    while (wybor != 5);
}

void push(int stos[], int &index)
{
    int liczba;
    if ((index<5)&&(index>-1))
    {
        cin>>liczba;
        stos[index++]=liczba;

        //    cout<<":)"<<endl;
    }
    else
    {
        cout<<"stos pelny!"<<endl;
        Sleep(1000);
    };
}

void pop(int stos[], int &index)
{
    if ((index<6)&&(index>0))
    {
        cout<<(stos[--index])<<endl;
    }
    else
    {
        cout<<"stos pusty!"<<endl;
        Sleep(1000);
    }
}

void size(int index)
{
    cout<<"Elementy: "<<index;
    Sleep(1000);
}

const char* empty(int index)
{
    return (index) ? "False" : "True";
}

void wyswietl_stos (int stos[], int index)
{
    system("CLS");
    cout<<string(30,'*')<<endl;
    for (int i=index-1; i>=0; i--)
    {//cout<<"idex:"<<index;
        cout<<stos[i]<<endl;
    }
    cout<<string(30,'*')<<endl;

}

