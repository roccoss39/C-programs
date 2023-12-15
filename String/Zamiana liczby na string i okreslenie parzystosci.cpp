#include <iostream>
#include <string>

using namespace std;

string parzystosc(int a);

int main()
{
    cout << parzystosc(55) << endl;
    cout << parzystosc(11) << endl;
    cout << parzystosc(44) << endl;

    return 0;
}

string parzystosc(int a)
{
    int dziesiatki = a / 10;
    int jednosci = a % 10;
    char d = '0' + dziesiatki;
    char j = '0' + jednosci;

    string lic("Liczba ");
    lic += d;
    lic += j;
    lic += " jest ";

    if (a % 2)
    {
        lic += "nieparzysta ";
    }
    else
    {
        lic += "parzysta ";
    }

    return lic;
}

