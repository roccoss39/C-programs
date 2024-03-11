#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

double Time;
int fibo(int number);
int main()
{
    int sequence;
    cout << "How many of the first Fibonacci sequence numbers to print? " << endl;
    cin >> sequence;

    auto start = system_clock::now();
    ;
    for (int i = 1; i <= sequence; i++)
    {
        cout << fibo(i) << " ";
    }
    cout << endl;
    auto stop = system_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double Time = duration.count() / 1e6; // zamiana na sekundy

    cout << "Time for fibo calculating: " << fixed << setprecision(10) << Time << "s" << endl;

    return 0;
}
int fibo(int number)
{
    if ((number == 1) || (number == 2))
    {
        return 1;
    }
    else
    {
        return fibo(number - 2) + fibo(number - 1);
    }
}
