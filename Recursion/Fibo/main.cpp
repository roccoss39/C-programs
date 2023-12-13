#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;


double czas;
int fibo(int a);
int main()
{

    int n;
    cout<<"Ile wypisac pierwszych liczb ciagu fibo? "<<endl;
    cin>>n;

    auto start = system_clock::now();;
    for (int i=1; i<=n; i++)
    {
        cout<<fibo(i)<<" ";
    }
    cout<<endl;
    auto stop = system_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double czas = duration.count() / 1e6; // zamiana na sekundy

    cout << "Czas obliczenia danych liczb fibo: " << fixed << setprecision(10) << czas << "s" << endl;


    return 0;
}
int fibo(int a)
{

    if((a==1)||(a==2))
    {
        return 1;
    }
    else
    {
        return fibo(a-2)+fibo(a-1);
    }
}
