#include <iostream>
#include <string>

using namespace std;

string Parity(int a);

int main()
{
    cout << Parity(55) << endl;
    cout << Parity(11) << endl;
    cout << Parity(44) << endl;

    return 0;
}

string Parity(int a)
{
    int Tens = a / 10;
    int Units = a % 10;
    char d = '0' + Tens;
    char j = '0' + Units;

    string Numb("Number ");
    Numb += d;
    Numb += j;
    Numb += " is ";

    if (a % 2)
    {
        Numb += "odd ";
    }
    else
    {
        Numb += "even ";
    }

    return Numb;
}
