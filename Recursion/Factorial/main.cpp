#include <iostream>
#include <iomanip>

using namespace std;

long long Factorial(long long number);
int main()
{
    int number;
    cout << "Insert number:";
    cin >> number;
    cout << Factorial(number);

    return 0;
}
long long Factorial(long long number)
{
    if (number < 1)
    {
        return 1;
    }
    else if (number > 1)
        return number * Factorial(number - 1);
}
