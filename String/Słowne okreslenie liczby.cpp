#include <iostream>
#include <string>
using namespace std;

string zamiana(int a);

int main()
{
    cout << zamiana(5123) << endl;
    cout << zamiana(6999) << endl;
    cout << zamiana(1531) << endl;
    cout << zamiana(-9234) << endl;
    cout << zamiana(32) << endl;
    cout << zamiana(12) << endl;
    cout << zamiana(-1) << endl;
    cout << zamiana(523) << endl;
    cout << zamiana(1006) << endl;
    cout << zamiana(1040) << endl;
    cout << zamiana(-17) << endl;
    cout << zamiana(-15) << endl;
    cout << zamiana(0) << endl;

    return 0;
}

string zamiana(int a)
{
    string l;

    if (a < 0)
    {
        l = "minus ";
        a *= -1;
    }
    if (a == 0)
        return l = "zero";

    string tys[] = {"tysiac", "tysiace", "tysiecy"};
    string set[] = {"sto", "dwiescie", "sta", "set"};
    string dzi[] = {"dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
    string kilkanascie[] = {"jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
    string jed[] = {"jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};

    int tysi = a / 1000;
    a %= 1000;
    int setk = a / 100;
    a %= 100;
    int dzie = a / 10;
    a %= 10;
    int jedn = a;

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

