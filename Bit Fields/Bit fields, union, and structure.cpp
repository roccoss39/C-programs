#include <iostream>

void ToBit(long a);

using namespace std;

struct StructDate
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
    StructDate Birthday;
};

int main()
{
    cout << "Enter your StructDate of birth DDMMYYYY: ";
    long lVal;
    cin >> lVal;
    MyUnion UnionDate;
    UnionDate.TotalWord = lVal;

    cout << "blue means bits 0-5: " << UnionDate.Birthday.blue << endl;
    cout << "green means bits 10-14: " << UnionDate.Birthday.green << endl;
    cout << "red means bits 16-18: " << UnionDate.Birthday.red << endl;

    ToBit(lVal);
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