#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#define ARRAY_SIZE 200
#define DOUBLE_SIZE sizeof(double)

int main()
{
    int NrArray;
    double Darray[ARRAY_SIZE];
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        Darray[i] = 0.01 * i;
    }

    fstream MyStream("dtab.bin", ios::in | ios::out | ios::binary | ios::trunc);
    if (!MyStream)
        cout << "Opening fault";
    else
        cout << "Opening ok" << endl;

    MyStream.write(reinterpret_cast<char *>(&Darray), sizeof Darray);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        Darray[i] = 0;
    }

    cout << endl;
    cout << "An array saved to a file in binary mode, zeroed out in the program." << endl;
    cout << "Provide the number in the array to write (0-" << ARRAY_SIZE - 1 << ").";
    cin >> NrArray;

    MyStream.seekg(DOUBLE_SIZE * NrArray, ios::beg);
    MyStream.read(reinterpret_cast<char *>(&Darray[NrArray]), DOUBLE_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (i % 10 == 0)
            cout << endl << setfill('-') << setw(3) << i << " ";
        cout << setw(4) << Darray[i] << " ";
    }
}
