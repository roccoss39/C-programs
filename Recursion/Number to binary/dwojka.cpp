#include <iostream>

using namespace std;
void dwojka(int a);
int main()
{
    int a;
    cout<<"Podaj liczbe ";
    cin>>a;
    dwojka(a);
}
void dwojka(int a)
{
    if (a!=1)
        dwojka(a/2);
    cout<<a%2;

}

