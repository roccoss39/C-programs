#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

long double exponentiation(long double number, long double power);

int main()
{
    int number, power;
    cout << "Provide the number and the exponent of the power sequentially:";
    cin >> number >> power;

    cout << setprecision(100000);

    auto start = system_clock::now();
    cout << exponentiation(number, power);
    auto stop = system_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count() / 1e6; // zamiana na sekundy

    cout << endl
         << "Time of calculation: " << fixed << setprecision(10) << time << "s" << endl;

    return 0;
}
long double exponentiation(long double number, long double power)
{
    if (power == 0)
        return 1;
    else
    {
        return number * exponentiation(number, power - 1);
    }
}
