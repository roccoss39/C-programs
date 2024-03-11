#include <iostream>

void ToBit(long a);

using namespace std;

struct Date
{
    unsigned int blue : 6;
    unsigned int : 4;
    unsigned int green : 5;
    unsigned int red : 3;
    unsigned int : 14;
};

union MyUnion
{
    long TotalWord;
    Date Birthday;
};

int main()
{
    cout << "Enter your date of birth DDMMYYYY: ";
    long date;
    cin >> date;
    MyUnion UnionDate;
    UnionDate.TotalWord = date;

    cout << "blue means bits 0-5: " << UnionDate.Birthday.blue << endl;
    cout << "green means bits 10-14: " << UnionDate.Birthday.green << endl;
    cout << "red means bits 16-18: " << UnionDate.Birthday.red << endl;

    ToBit(date);
}

void ToBit(long a)
{
    static int i;
    i++;
    if (a > 1)
        ToBit(a / 2);
    if (i % 4 == 0)
        cout << " ";
    i--;
    cout << a % 2;
}