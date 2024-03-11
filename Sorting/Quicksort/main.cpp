#include <iostream>
#include <time.h>
using namespace std;
void quicksort(int *MyArray, int From, int To);

int main()
{
    srand(time(NULL));
    int NumbersToSort = 200;
    int Arr[NumbersToSort];

    // Wczytywanie losowych liczb do tablicy
    for (int i = 0; i < NumbersToSort; i++)
    {
        Arr[i] = rand() % NumbersToSort + 1;
    }

    // Przed sortowaniem
    for (int i = 0; i < NumbersToSort; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << endl
         << endl
         << "After sorting:" << endl;

    quicksort(Arr, 0, NumbersToSort);

    // Po sortowaniu
    for (int i = 0; i < NumbersToSort; i++)
    {
        cout << Arr[i] << " ";
    }
}

void quicksort(int *MyArray, int From, int To)
{
    int UpperIndex = To - 1;
    int LowerIndex = From;
    int Bufor;
    const int Axe = MyArray[From]; // Axe czyli os podzialu (polowiczny)
    do
    {
        while ((MyArray[UpperIndex] >= (Axe)) && (!(LowerIndex == UpperIndex)))
        {
            UpperIndex--;
        }
        Bufor = MyArray[UpperIndex];
        MyArray[UpperIndex] = MyArray[LowerIndex];
        MyArray[LowerIndex] = Bufor;

        while ((MyArray[LowerIndex] <= (Axe)) && (!(LowerIndex == UpperIndex)))
        {
            LowerIndex++;
        }
        Bufor = MyArray[UpperIndex];
        MyArray[UpperIndex] = MyArray[LowerIndex];
        MyArray[LowerIndex] = Bufor;
    } while (!(LowerIndex == UpperIndex));

    if (LowerIndex - From >= 2)
        quicksort(MyArray, From, LowerIndex);
    if (To - UpperIndex >= 3)
        quicksort(MyArray, UpperIndex + 1, To);
}
