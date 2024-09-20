// szukanie GCD
#include <iostream>

using namespace std;
int GCD(int times, int numb1);
int main()
{
    cout << "Provide how many times the program should give GCD, then insert 2 numbers to calculate their GCD" << endl;

    int times, numb1, numb2;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        cin >> numb1 >> numb2;
        cout << (GCD(numb1, numb2)) << endl;
    }
    return 0;
}
int GCD(int times, int numb1)
{
    int temp, pol = times / 2;

    if (times % numb1 == 0)
        return numb1;
    if (numb1 % times == 0)
        return times;

    for (int i = pol; i > 0; i--)
    {
        if ((times % i == 0) && (numb1 % i) == 0)
        {
            return i;
        }
    }
    return 0;
}
