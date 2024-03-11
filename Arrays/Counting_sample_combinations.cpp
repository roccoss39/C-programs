// zadanie bez klasy string, pojemników, wektorow, biblioteki <cstring>, klas itp.
// surowe operacje na tablicach (bardziej język c++)

#include <iostream>
#include <cstdlib>
#include <ctime> // starsza biblioteka ctime
using namespace std;

const int SIZE_1 = 2, SIZE_2 = 2, SIZE_3 = 2, SIZE_4 = 2;
const int MAX_COMBINATIONS = 10000;
int result[MAX_COMBINATIONS];
int tab[SIZE_1][SIZE_2][SIZE_3][SIZE_4];

void Filling(int t[][SIZE_2][SIZE_3][SIZE_4]);
void MergeText(char tab[], char abbreviation[]);
void RemovePlus(char t[]);
void Clear(char tab[]);
void Display(int tab[]);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Filling(tab);
	Display(result);
}

void Filling(int t[][SIZE_2][SIZE_3][SIZE_4])
{
	char tab[30] = {""}, DGF[] = " DGF +", HEC[] = " HEC +", GER[] = " GER +", FRS[] = " FRS +";

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
			MergeText(tab, FRS);
		if ((t[i][j][n][m] >> 1) & 1)
			MergeText(tab, GER);
		if (((t[i][j][n][m] >> 2) & 1))
			MergeText(tab, HEC);
		if (((t[i][j][n][m] >> 3) & 1))
			MergeText(tab, DGF);

		RemovePlus(tab);
		cout << tab << endl;
		Clear(tab);
	}
}

void MergeText(char tab[], char abbreviation[])
{
	int i = 0;
	while (tab[i] != '\0')
	{
		i++;
	}
	for (int j = 0;; i++, j++)
	{
		tab[i] = abbreviation[j];
		if (abbreviation[j] == '\0')
			break;
	}
}

void Clear(char tab[])
{
	tab[0] = '\0';
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

void Display(int tab[])
{
	char array[30] = {" "}, DGF[] = " DGF +", HEC[] = " HEC +", GER[] = " GER +", FRS[] = " FRS +";
	int temp;
	for (int x = 0; x < MAX_COMBINATIONS - 1; x++)
	{
		for (int y = 0; y < MAX_COMBINATIONS; y++)
		{
			//sorting by number of bits
			if ((((tab[y] >> 0) & 1) + ((tab[y] >> 1) & 1) + ((tab[y] >> 2) & 1) + (((tab[y] >> 3) & 1)) > ((tab[y + 1] >> 0) & 1) + ((tab[y + 1] >> 1) & 1) + ((tab[y + 1] >> 2) & 1) + ((tab[y + 1] >> 3) & 1)))
			{
				temp = tab[y + 1]; // bubble sorting 
				tab[y + 1] = tab[y];
				tab[y] = temp;
			}
		}
	}
	for (int i = 0; i < MAX_COMBINATIONS; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((tab[i]) == tab[j] && (i != 0))
			{
				break;
			}
			if ((j == i - 1) || (i == 0))
			{
				static int numb, sum;
				numb = tab[i];
				sum = 0;
				Clear(array);

				if ((tab[i] >> 0) & 1)
					MergeText(array, FRS);
				if ((tab[i] >> 1) & 1)
					MergeText(array, GER);
				if ((tab[i] >> 2) & 1)
					MergeText(array, HEC);
				if ((tab[i] >> 3) & 1)
					MergeText(array, DGF);

				RemovePlus(array);
				cout << "COMBINATIONS:" << array << " ->";

				for (int i = 0; i < MAX_COMBINATIONS; i++)
				{
					if (numb == tab[i])
						sum++;
				}
				cout << " " << sum << " TIMES" << endl;
			}
		}
	}
}
