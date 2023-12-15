#include <iostream>

using namespace std;
int nwd(int a, int b);
int main()
{
    cout<<"Podaj ile razy ma sie wykonac program, a nastepnie 2 liczby do wyznaczenia NWW ";
    int a,b,c,d;

    cin>>a;

    for (int i=0; i<a; i++)
    {

        cin>>b>>c;
        d=(c*b/(nwd(b, c)));
        cout<<d<<endl;

    }
    return 0;
}
int nwd(int a, int b)
{
    int temp,pol=a/2;

    if (a%b==0)
        return b;
    if(b%a==0)
        return a;

    for(int i=pol; i>0; i--)
    {
        if ((a%i==0) &&(b%i)==0)
        {
            return i;
        }
    }
}
