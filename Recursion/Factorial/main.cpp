#include <iostream>
#include <iomanip>

using namespace std;
long long silnia(long long a);
int main()
{
    int a;
    cout<<"Podaj liczbe:";
    cin >>a;
    cout<<silnia(a);

    return 0;
}
long long silnia(long long a)
{
    if(a<1)
    {
        return 1;
    }
    else if (a>1)
        return a*silnia(a-1);
}
