#include <iostream>
#include <string>
using namespace std;

string Change(int Number);

int main()
{
    cout << Change(5123) << endl;
    cout << Change(6999) << endl;
    cout << Change(1531) << endl;
    cout << Change(-9234) << endl;
    cout << Change(32) << endl;
    cout << Change(12) << endl;
    cout << Change(-1) << endl;
    cout << Change(523) << endl;
    cout << Change(1006) << endl;
    cout << Change(1040) << endl;
    cout << Change(-17) << endl;
    cout << Change(-15) << endl;
    cout << Change(0) << endl;

    return 0;
}

string Change(int Number)
{
    string l;

    if (Number < 0)
    {
        l = "minus ";
        Number *= -1;
    }
    if (Number == 0)
        return l = "zero";

    string tys[] = {"tysiac", "tysiace", "tysiecy"};
    string set[] = {"sto", "dwiescie", "sta", "set"};
    string dzi[] = {"dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
    string kilkanascie[] = {"jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
    string jed[] = {"jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};

    int tysi = Number / 1000;
    Number %= 1000;
    int setk = Number / 100;
    Number %= 100;
    int dzie = Number / 10;
    Number %= 10;
    int jedn = Number;

    if (tysi > 0)
    {
        if (tysi == 1)
            l += jed[tysi - 1] + " " + tys[0] + " ";
        else if (tysi < 5)
        {
            l += jed[tysi - 1] + " " + tys[1] + " ";
        }
        else
        {
            l += jed[tysi - 1] + " " + tys[2] + " ";
        }
    }
    
    if (setk > 0)
    {
        if (setk == 1)
            l += set[0] + " ";
        else if (setk == 2)
            l += set[1] + " ";
        else if (setk == 5)
            l += jed[setk - 1] + " " + set[3] + " ";
        else
        {
            l += jed[setk - 1] + " " + set[3] + " ";
        }
    }

    if (dzie > 1)
    {
        l += dzi[dzie - 1] + " ";
    }
    else if (dzie == 1)
    {
        l += kilkanascie[jedn - 1] + " ";
        return l;
    }

    if (jedn > 0)
    {
        l += jed[jedn - 1];
    }
    return l;
}
