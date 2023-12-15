
//Program dla n przyjmuje wartosc aktualnego indexu czyli n=i; Zlicza za pomoc¹ f wirtualnych sume wyrazow ciagu arytmetycznego i geometrycznego

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class ciagi
{
	public:
	
	virtual double suma_wyrazow(int n)=0;
	virtual ciagi* stworz_nowy()=0;
		~ciagi()
	{
		cout<<"Dziala destruktor ciagow\n";
	}

};
class ciag_arytmetyczny: public ciagi
{
	ciagi* stworz_nowy()
	{
	cout<<"Dziala konstru wirtualny arytm\n"<<endl;
	return new ciag_arytmetyczny;
	}
	
	public:
	double suma_wyrazow(int n)
	{
		//wzor an=2n+1, r=2, a1=0
		double suma;
		suma=((6+(n-1)*2)/2)*n;
		cout<<"Suma wyrazow ciagu arytmetycznego:"<<suma<<endl;
		return suma;
	}
	~ciag_arytmetyczny()
	{
		cout<<"Dziala destruktor ciagu arytmetycznego ";
	}
};

class ciag_geometryczny: public ciagi
{	
	ciagi* stworz_nowy()
	{
	cout<<"Dziala konstru wirtualny geo\n"<<endl;
	return new ciag_geometryczny;
	}
	
	public:
	double suma_wyrazow(int n)
	{
		//an=2^n q=2
		double suma;
		suma=2*(1-pow(2,n))/(-1);
	//	cout<<"2^n to:"<<2^n;
		cout<<"Suma wyrazow ciagu geometrycznego:"<<suma<<endl;
		return suma;
	}
		~ciag_geometryczny()
	{
		cout<<"Dziala destruktor ciagu geometrycznego ";
	}
};

int main()
{
int ile=10;
ciagi *	tab_ciagow[ile];
ciagi * wskaznik;
ciag_arytmetyczny domyslny;
ciag_geometryczny domyslny2;

for (int i=1;i<ile+1;i++)
{
	int wybor;
	cout<<"Jaki ciag stowrzyc(laczenie do stworzenia 10 ciagow)? 1:arytmetyczny / 2:geometryczny ";
	cin>>wybor;
		
	switch (wybor)
	{
		case 1:
			wskaznik=&domyslny;
			tab_ciagow[i]=wskaznik->stworz_nowy();
			cout<<"Tworze ciag arytmetyczny 2n+1 \n";
			break;
		case 2:
			wskaznik=&domyslny2;
			tab_ciagow[i]=wskaznik->stworz_nowy();
			cout<<"Tworze ciag geometryczny 2^n \n";
			break;
		default:
            cout << "Nieprawidlowy wybor." << endl;
            exit(1);
            
			
	}
	 
}
cout<<"\nciagi to:\n";
for (int i=1;i<ile+1;i++)
{cout<<"i="<<i<<" ";
tab_ciagow[i]->suma_wyrazow(i);
}
for (int i=1;i<ile+1;i++)
{
delete tab_ciagow[i];
}

}

	

