//Program tworzy pliki o okreslonych parametrach, pliki znajda sie w folderze z plikiem
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
int raport(int nr_probki, int liczba_masowa, string izotop);

int main()
{
	raport(1234,000,"Probka z wodorotlenkiem chloru");
	raport(1212,002,"druga probka do oddania");
	system("pause");
	return 0;
}
int raport(int nr_probki, int liczba_masowa, string izotop)
{
for (int i=0;i<izotop.length();i++)	
{
	if (izotop[i]==' ') izotop[i]='_';
}

ostringstream stru;
stru << "Raport_" << setfill('0') << setw(4) << nr_probki <<"_reakcji_" << setw(3) << liczba_masowa << "_" << izotop << ".txt";


ofstream zapisz((stru.str()).c_str());
zapisz<<"testy lab";
}
