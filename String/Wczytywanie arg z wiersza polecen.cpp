//Argumenty przesylane np. przez konsole cmd, pierwszy argument okresla skad beda pochodzic dane
#include <iostream>
#include <string>
using namespace std;
string f(int argq,char *argv[]);

int main (int argq,char *argv[])
{
f( argq, argv);
}

string f(int argq,char *argv[])
{
	string  wstr;

for(int i=0;i<argq;i++)
{
	if (i==1)
	{
		wstr=wstr.assign(argv[i],4 );

	if (wstr=="-ser")
	{
		wstr=wstr.assign(argv[i+1] );
		wstr="Dane beda pochodzic z serwera: "+wstr;
	}
	else	if (wstr=="-pli")
	{
		wstr=wstr.assign(argv[i+1] );
		wstr="Dane beda pochodzic z pliku: "+wstr;
	}
	else	if (wstr=="-str")
	{
		wstr=wstr.assign(argv[i+1] );
		wstr="Dane beda pochodzic ze strumienia: "+wstr;
	}
	}
}
cout<<wstr;
}
