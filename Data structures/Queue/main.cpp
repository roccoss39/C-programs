#include <iostream>
#include <windows.h>
using namespace std;

void push(int kolejka[], int &ind);
void pop(int kolejka[], int &ind);
void size(int ind);
const char* empty(int index);
void wyswietl_menu (int kolejka[], int index);
void wyswietl_kolejka (int kolejka[], int index);

int main()
{
    int index=0, kolejka[5];
    wyswietl_menu (kolejka,index);
}

void wyswietl_menu (int kolejka[], int index)
{
    int wybor;
    do
    {
        cout << "MENU GLOWNE KOLEJKI:"<<endl;
        cout<<string(40,'*')<<endl;
        cout << "1. PUSH (dodaje element do kolejki) "<<endl;
        cout << "2. POP (usuwa element z kolejki) "<<endl;
        cout << "3. SIZE (ile elementow w kolejce) "<<endl;
        cout << "4. EMPTY (czy kolejka jest pusta?) "<<endl;
        cout << "5. Koniec programu "<<endl;
        cout<<string(40,'*')<<endl;
        cout << "Wybor: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            push(kolejka, index);
            break;

        case 2:
            pop(kolejka, index);
            break;

        case 3:
            size(index);
            break;

        case 4:
            cout<<empty(index);
			   Sleep(1000);
            break;

        }
        wyswietl_kolejka(kolejka,  index);
    }
    while (wybor != 5);
}

void push(int kolejka[], int &index)
{
    int liczba;
    if ((index<5)&&(index>-1))
    {
        cin>>liczba;
        kolejka[index++]=liczba;

        //    cout<<":)"<<endl;
    }
    else
    {
        cout<<"kolejka jest pelna!"<<endl;
        Sleep(1000);
    };
}

void pop(int kolejka[], int &index)
{
    if ((index<6)&&(index>0))
    {
      //  cout<<(kolejka[--index])<<endl;

        for(int i=0;i<index;i++)
		{
			kolejka[i]=kolejka[i+1];
		}
		index--;
    }
    else
    {
        cout<<"kolejka jest pusta!"<<endl;
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

void wyswietl_kolejka (int kolejka[], int index)
{
    system("CLS");
    cout<<string(30,'*')<<endl;
    for (int i=0; i<index; i++)
    {//cout<<"idex:"<<index;
        cout<<kolejka[i]<<" ";
    }
    cout<<endl<<string(30,'*')<<endl;

}

