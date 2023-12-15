#include <iostream>
using namespace std;

typedef long LongType;

char* tworzenie_szachownicy();
void tworzenie_figur(char* szachownica);

int main()
{
    char* szachownica = tworzenie_szachownicy();
    tworzenie_figur(szachownica);

    delete[] szachownica;
    cout << "\nUsunieto szachownice.";
    return 0;
}

char* tworzenie_szachownicy()
{
    char* szachownica = new char[256];
    for (int j = 0; j < 256; j++)
    {
        szachownica[j] = '0';
    }
    return szachownica;
}

void tworzenie_figur(char* szachownica)
{
    char a;
    LongType* figury[32];
    static int ile = 0;
    long b, pozycja;

    for (int j = 0; j < 32; j++)
    {
        figury[j] = nullptr;
    }

    while (1)
    {
        cout << "Podaj miejsce stworzenia figury np. F4 lub nacisnij 'x' aby pokazac miejsce figury (adres): ";
        cin >> a;

        if (a == 'x')
        {
            break;
        }

        cin >> b;

        if (a < 'A' || a > 'H' || b < 1 || b > 8)
        {
            cout << "Bledne wspolrzedne!" << endl;
            break;
        }

        pozycja = ((a - 'A') * 8 + b - 1) * 4;

        cout << "Miejsce w pamieci to: " << pozycja << endl;

        figury[ile] = new (&szachownica[pozycja]) LongType; // zbudowanie obiektu long na pozycji char, new placement
        *(figury[ile]) = pozycja; // figura posiada dane o swojej pozycji
        ile++;
    }

    cout << "Liczba stworzonych figur: " << ile << ". Miejsca to:";

    for (int j = 0; j < ile; j++)
    {
        cout << *(figury[j]) << " ";
    }

    // Usuñ figury
    for (int j = 0; j < ile; j++)
    {
        figury[j]->~LongType(); // Reczne wywo³anie destruktora dla figury (zwolnienie miejsca na szachownicy) gdyz nie rezerwowano pamieci, a zbudowano obiekt na szachownicy
    }

    cout << "\nUsunieto figury.";
}
