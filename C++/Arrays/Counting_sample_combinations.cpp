// Task without the string class, containers, vectors, <cstring> library, classes, etc. Raw operations on arrays (more like C language)

#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

const int SIZE_1 = 2, SIZE_2 = 2, SIZE_3 = 2, SIZE_4 = 2;
const int MAX_COMBINATIONS = 10000;
int result[MAX_COMBINATIONS];
int arr[SIZE_1][SIZE_2][SIZE_3][SIZE_4];

void Filling(int t[][SIZE_2][SIZE_3][SIZE_4]);
void MergeText(char arr[], char abbreviation[]);
void RemovePlus(char t[]);
void Clear(char arr[]);
void Display(int arr[]);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Filling(arr);
	Display(result);
}

void Filling(int t[][SIZE_2][SIZE_3][SIZE_4])
{
	char arr[30] = {""}, DGF[] = " DGF +", HEC[] = " HEC +", GER[] = " GER +", FRS[] = " FRS +";

	for (int x = 0; x < MAX_COMBINATIONS; x++)
	{
		int j, m, n, i;
		i = rand() % 2;
		j = rand() % 2;
		n = rand() % 2;
		m = rand() % 2;

		t[i][j][n][m] = i * 2 * 2 * 2 + j * 2 * 2 + n * 2 + m;
		result[x] = t[i][j][n][m];

		if ((t[i][j][n][m] >> 0) & 1)
			MergeText(arr, FRS);
		if ((t[i][j][n][m] >> 1) & 1)
			MergeText(arr, GER);
		if (((t[i][j][n][m] >> 2) & 1))
			MergeText(arr, HEC);
		if (((t[i][j][n][m] >> 3) & 1))
			MergeText(arr, DGF);

		RemovePlus(arr);
		cout << arr << endl;
		Clear(arr);
	}
}

void MergeText(char arr[], char abbreviation[])
{
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	for (int j = 0;; i++, j++)
	{
		arr[i] = abbreviation[j];
		if (abbreviation[j] == '\0')
			break;
	}
}

void Clear(char arr[])
{
	arr[0] = '\0';
}

void RemovePlus(char t[])
{
	for (int i = 0; i < 30; i++)
	{
		if ((t[i] == 0) && (t[i - 1] == '+'))
		{
				(t[i - 1] = '\0');
		}
	}
}

void Display(int arr[])
{
	char array[30] = {" "}, DGF[] = " DGF +", HEC[] = " HEC +", GER[] = " GER +", FRS[] = " FRS +";
	int temp;
	for (int x = 0; x < MAX_COMBINATIONS - 1; x++)
	{
		for (int y = 0; y < MAX_COMBINATIONS; y++)
		{
			//sorting by number of bits
			if ((((arr[y] >> 0) & 1) + ((arr[y] >> 1) & 1) + ((arr[y] >> 2) & 1) + (((arr[y] >> 3) & 1)) > ((arr[y + 1] >> 0) & 1) + ((arr[y + 1] >> 1) & 1) + ((arr[y + 1] >> 2) & 1) + ((arr[y + 1] >> 3) & 1)))
			{
				temp = arr[y + 1]; // bubble sorting 
				arr[y + 1] = arr[y];
				arr[y] = temp;
			}
		}
	}
	for (int i = 0; i < MAX_COMBINATIONS; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((arr[i]) == arr[j] && (i != 0))
			{
				break;
			}
			if ((j == i - 1) || (i == 0))
			{
				static int numb, sum;
				numb = arr[i];
				sum = 0;
				Clear(array);

				if ((arr[i] >> 0) & 1)
					MergeText(array, FRS);
				if ((arr[i] >> 1) & 1)
					MergeText(array, GER);
				if ((arr[i] >> 2) & 1)
					MergeText(array, HEC);
				if ((arr[i] >> 3) & 1)
					MergeText(array, DGF);

				RemovePlus(array);
				cout << "COMBINATIONS:" << array << " ->";

				for (int i = 0; i < MAX_COMBINATIONS; i++)
				{
					if (numb == arr[i])
						sum++;
				}
				cout << " " << sum << " TIMES" << endl;
			}
		}
	}
}
