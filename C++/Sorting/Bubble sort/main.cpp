#include <iostream>
#include <time.h>
using namespace std;
void Bubble_sort(int MyArray[], int ArraySize);
int main()
{
    srand(time(NULL));
    const int NumbersToSort = 100;
    int Arr[NumbersToSort];

    // Setting random numbers into an array
    for (int i = 0; i < NumbersToSort; i++)
    {
        Arr[i] = rand() % NumbersToSort + 1;
    }
    for (int i = 0; i < NumbersToSort; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << endl
         << endl
         << "After sorting" << endl;

    Bubble_sort(Arr, NumbersToSort);

    for (int i = 0; i < NumbersToSort; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}
void Bubble_sort(int MyArray[], int ArraySize)
{
    int temp;
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = 0; j < ArraySize - i; j++)
        {
            if (MyArray[j] > MyArray[j + 1])
            {
                temp = MyArray[j + 1];
                MyArray[j + 1] = MyArray[j];
                MyArray[j] = temp;
            }
        }
    }
}
