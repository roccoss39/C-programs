#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int NrArray;
	double Darray[200];
	for (int i = 0; i < 200; i++)
	{
		Darray[i] = 0.01 * i;
	}

	fstream MyStream("dtab.bin", ios::in | ios::out | ios::binary | ios::trunc);
	if (!MyStream)
		cout << "Opening fault";
	else
		cout << "Opening ok" << endl;

	MyStream.write(reinterpret_cast<char *>(&Darray), sizeof Darray);

	for (int i = 0; i < 200; i++)
	{
		Darray[i] = 0;
	}

	cout << endl;

	cout << "An array saved to a file in binary mode, zeroed out in the program." << endl;

	cout << "Provide the number in the array to write (0-199).";

	cin >> NrArray;
	MyStream.seekg(8 * NrArray, ios::beg);
	MyStream.read(reinterpret_cast<char *>(&Darray[NrArray]), 8);

	for (int i = 0; i < 200; i++)
	{
		if (i % 10 == 0)
			cout << endl
				 << setfill('-') << setw(3) << i << " ";
		cout << setw(4) << Darray[i] << " ";
	}
}
