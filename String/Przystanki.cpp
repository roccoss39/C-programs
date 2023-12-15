#include <iostream>
#include <string>
using namespace std;
string przystanek(int a);


int main ()
{
cout<<	przystanek(1)<<endl;
cout<<	przystanek(2)<<endl;
}

string przystanek(int a)
{
		string przystanki[] = {
        "Dworzec Glowny",
        "Plac Wolnosci",
        "Nowy Swiat",
        "Rondo Solidarnosci",
        "Park Saski",
    };
string kolejny_przystanek("Nastepny przystanek: ");
kolejny_przystanek+=przystanki[a-1];
return kolejny_przystanek;
}
