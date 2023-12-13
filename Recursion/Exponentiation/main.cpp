#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;
long double potega(long double a, long double b);
int main()
{
    int a,b;
    cout<<"Podaj kolejno liczbe i wykladnik potegi:";
    cin>>a>>b;

    cout<<setprecision(100000);

    auto start = system_clock::now();
    cout<< potega(a, b);
    auto stop = system_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double czas = duration.count() / 1e6; // zamiana na sekundy

    cout <<endl<< "Czas obliczen: " << fixed << setprecision(10) << czas << "s" << endl;

    return 0;
}
long double potega(long double a, long double b)
{
    if (b==0)
        return 1;
    else
    {

        return a*potega(a,b-1);
    }
}
