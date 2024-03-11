// Argumenty przesylane np. przez konsole cmd, pierwszy argument okresla skad beda pochodzic dane
#include <iostream>
#include <string>
using namespace std;
void MyFunction(int argq, char *argv[]);

int main(int argq, char *argv[])
{
	MyFunction(argq, argv);
}

void MyFunction(int argq, char *argv[])
{
	string MyString;

	for (int i = 0; i < argq; i++)
	{
		if (i == 1)
		{
			MyString = MyString.assign(argv[i], 4);

			if (MyString == "-ser")
			{
				MyString = MyString.assign(argv[i + 1]);
				MyString = "Data will originate from the server: " + MyString;
			}
			else if (MyString == "-pli")
			{
				MyString = MyString.assign(argv[i + 1]);
				MyString = "The data will originate from a file: " + MyString;
			}
			else if (MyString == "-str")
			{
				MyString = MyString.assign(argv[i + 1]);
				MyString = "The data will originate from a stream: " + MyString;
			}
		}
	}
	cout << MyString;
}
