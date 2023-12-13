#include <iostream>
#include <windows.h>

using namespace std;

struct wezel
{
    int wartosc;
    int znajdz(wezel *&korzen, int liczba,int ile);
    wezel *lewy, *prawy;
    void dodaj(wezel *&korzen, int wartosc);
    wezel(int wart = 0) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}
};


void wezel::dodaj(wezel *&korzen, int wartosc)
{
    if (korzen == nullptr)
    {
        korzen = new wezel(wartosc);
    }
    else if (wartosc < korzen->wartosc)
    {
        dodaj(korzen->lewy, wartosc);
    }
    else
    {
        dodaj(korzen->prawy, wartosc);
    }
}

int wezel::znajdz(wezel *&korzen, int liczba,int ile)
{
    if (korzen == nullptr)
    {
        cout << "Nie znaleziono " << endl;
        return -1;
    }
    else if (liczba == korzen->wartosc)
        return ile;
    else if (korzen->lewy != nullptr && liczba == korzen->lewy->wartosc)
    {
        cout<<"\nznaleziono, wezel nr:";
        return 2 * ile;
    }
    else if (korzen->prawy != nullptr && liczba == korzen->prawy->wartosc)
    {
        cout<<"\nznaleziono, wezel nr:";
        return 2 * ile + 1;
    }
    else if (liczba < korzen->wartosc)
    {
        return znajdz(korzen->lewy, liczba,ile*=2);
    }
    else if (liczba > korzen->wartosc)
    {

        return znajdz(korzen->prawy, liczba,ile*=2);
    }
}

void rysuj(wezel *korzen, int wysokosc, int szerokosc);
void wykonaj(wezel *&korzen, wezel obiekt);
void resetkursor();
void wyswietl(wezel *korzen);
void menu();
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    wezel *korzen = nullptr;
    wezel drzewo;

    menu();
    wykonaj(korzen, drzewo);

delete korzen;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void wyswietl(wezel *korzen)
{

    static int ile_razy=0;
    ile_razy++;

    if (korzen == nullptr)
        cout<<"drzewo puste"<<endl;

    else if (korzen->prawy==nullptr && korzen -> lewy==nullptr&&ile_razy==1)
        cout<<"Wartosc korzenia to:"<<korzen->wartosc<<endl;

    else
    {
        if (korzen->prawy!=nullptr || korzen -> lewy!=nullptr)
            cout<<"Ojciec ma wartosc:"<<korzen->wartosc<<endl;

        if(korzen -> lewy!=nullptr)
            cout<<"Lewy potomek ma wartosc:"<<korzen->lewy->wartosc<<endl;

        if(korzen -> prawy!=nullptr)
            cout<<"Prawy potomek ma wartosc:"<<korzen->prawy->wartosc<<endl;

    }
    if (korzen->lewy != nullptr)
        wyswietl(korzen->lewy);
    if (korzen->prawy != nullptr)
        wyswietl(korzen->prawy);

}
void rysuj(wezel *korzen, int wysokosc, int szerokosc)
{
    COORD coord;
    coord.X = szerokosc;
    coord.Y = wysokosc;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    if (korzen != nullptr)
    {
        cout<<korzen->wartosc<<endl;
    }

    if (korzen->lewy!=nullptr)
        rysuj(korzen->lewy,wysokosc+1,szerokosc-13+wysokosc*2);
    if (korzen->prawy!=nullptr)
        rysuj(korzen->prawy,wysokosc+1,szerokosc+13-wysokosc*2);

}
void resetkursor()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 7;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i =0; i<22; i++)
    {
        cout << string(30, ' ') <<endl;
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu()
{
    system("CLS");
    cout << string(27, '*') << endl;
    cout << "1. Dodaj liczbe \n"
         << "2. Znajdz liczbe \n"
         << "3. Wyswietl relacje drzewa \n"
         << "4. Wyczysc ekran \n"
         << "5. Koniec \n";
    cout << string(27, '*') << endl;
}

void wykonaj(wezel *&korzen, wezel obiekt)
{
    int liczba, a;

    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cin >> a;
        resetkursor();
        switch (a)
        {
        case 1:
            cout << "Podaj wartosc:";
            cin >> liczba;
            obiekt.dodaj(korzen, liczba);
            rysuj(korzen, 0, 70);
            resetkursor();
            break;
        case 2:
            cout << "Podaj wartosc:";
            cin >> liczba;
            cout <<obiekt.znajdz(korzen, liczba,1) << "\n";
            Sleep(1000);
            resetkursor();
            break;
        case 3:
            wyswietl(korzen);
            break;
        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            menu();
            rysuj(korzen, 0, 70);
            resetkursor();
            break;
        case 5:
            break;
        default:
            cin.clear();
            cin.ignore();
            cout<<("wybierz wlasciwie");
            Sleep(1000);
            resetkursor();

            break;
        };

    }
    while (a != 5);
}

