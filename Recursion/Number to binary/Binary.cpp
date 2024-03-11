#include <iostream>

using namespace std;
void Binary(int number);
int main()
{
    int number;
    cout << "Insert number ";
    cin >> number;
    Binary(number);
}
void Binary(int number)
{
    if (number != 1)
        Binary(number / 2);
    cout << number % 2;
}
