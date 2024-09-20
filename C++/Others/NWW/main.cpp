#include <iostream>

using namespace std;

int LCM(int times, int number);

int main()
{
    cout << "Write how many times the program should give GCD, then insert 2 numbers to calculate their Least Common Multiple (LCM) ";
    int times, number, number2, result;

    cin >> times;

    for (int i = 0; i < times; i++)
    {

        cin >> number >> number2;
        result = (number2 * number / (LCM(number, number2)));
        cout << result << endl;
    }
    return 0;
}
int LCM(int times, int number)
{
    int temp, pol = times / 2;

    if (times % number == 0)
        return number;
    if (number % times == 0)
        return times;

    for (int i = pol; i > 0; i--)
    {
        if ((times % i == 0) && (number % i) == 0)
        {
            return i;
        }
    }
return 0;   
}
