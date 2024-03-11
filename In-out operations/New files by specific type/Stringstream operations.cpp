// Program tworzy pliki o okreslonych parametrach, pliki znajda sie w folderze z plikiem
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void raport(int Sample_number, int Molar_mass, string Isotope);

int main()
{
	raport(1234, 000, "Sample with chlorine hydroxide");
	raport(1212, 002, "The second sample to be submitted.");
	system("Pause");
	return 0;
}
void raport(int Sample_number, int Molar_mass, string Isotope)
{
	for (int i = 0; i < Isotope.length(); i++)
	{
		if (Isotope[i] == ' ')
			Isotope[i] = '_';
	}

	ostringstream MyStream;
	MyStream << "Raport_" << setfill('0') << setw(4) << Sample_number << "_reaction_" << setw(3) << Molar_mass << "_" << Isotope << ".txt";

	ofstream Save((MyStream.str()).c_str());

	Save << "Lab tests";
}
