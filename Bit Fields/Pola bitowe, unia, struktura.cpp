#include <iostream>

void zamien(long a);

using namespace std;

struct data
{
    unsigned int niebieski : 6;
    unsigned int : 4;
    unsigned int zielony : 5;
    unsigned int czerwony : 3;
    unsigned int : 14;
};

union moja
{
    long cale;
    data urodziny;
};

int main()
{
    cout << "Podaj date urodzenia DDMMRRRR: ";
    long dat;
    cin >> dat;
    moja datka;
    datka.cale = dat;

    cout << "Niebieski czyli bity 0-5: " << datka.urodziny.niebieski << endl;
    cout << "Zielony czyli bity 10-14: " << datka.urodziny.zielony << endl;
    cout << "Czerwony czyli bity 16-18: " << datka.urodziny.czerwony << endl;

    zamien(dat);
}

void zamien(long a)
{
    static int i;
    i++;
    if (a > 1)
        zamien(a / 2);
    if (i % 4 == 0)
        cout << " ";
    i--;
    cout << a % 2;
}

