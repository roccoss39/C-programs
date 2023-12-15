#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
char c;
int a;
double dtablica[200];
for (int i=0;i<200;i++)
	{
		dtablica[i]=0.01*i;
	}	

fstream strumien("dtab.bin",ios::in|ios::out|ios::binary|ios::trunc);
if (!strumien) cout<<"blad otwarcia"; else cout<<"Otwarcie ok"<<endl;
strumien.write(reinterpret_cast <char*>(&dtablica),sizeof dtablica);

for (int i=0;i<200;i++)
	{
		dtablica[i]=0;
	}
	for (int i=0;i<200;i++)
	{
		cout<<dtablica[i]<<" " ;
	}
	cout<<endl;
	cout<<"Tablica zapisana do pliku w trybie binarnym, wyzerowana w programie"<<endl;


cout<<"Podaj nr w tablicy ktory wczytac (0-199) ";
cin>>a;
strumien.seekg(8*a, ios::beg);
strumien.read(reinterpret_cast<char*>(&dtablica[a]), 8);
	for (int i=0;i<200;i++)
	{
		if (i%10==0)
		cout<<endl<<setfill('-')<<setw(3)<<i<<" ";
		cout<<setw(4)<<dtablica[i]<<" " ;
	
		
	}
//	cout<<"suma to"<<dtablica[a]+dtablica[5];
}


