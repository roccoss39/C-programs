#include <iostream>
#include <time.h>
using namespace std;
void babelkowe(int tab[], int rozm);
int main()
{
    srand(time(NULL));
    int ile=100;
    int tablica[ile];

    //Wczytywanie losowych liczb do tablicy
    for(int i=0; i<ile; i++)
    {
        tablica[i] = rand()%ile+1;
    }
    for (int i =0; i<ile; i++)
    {
        cout<<tablica[i]<<" ";
    }

    cout<<endl<<endl<<"Po sortowaniu"<<endl;

    babelkowe(tablica, ile);

    //Po sortowaniu
    for (int i =0; i<ile; i++)
    {
        cout<<tablica[i]<<" ";
    }

    return 0;
}
void babelkowe(int tab[], int rozm)
{
    int temp;
    for(int i=0; i<rozm; i++)
    {
        for(int j=0; j<rozm; j++)
        {
            if (tab[j]>tab[j+1])
            {
                temp=tab[j+1];
                tab[j+1]=tab[j];
                tab[j]=temp;
            }
        }
    }
}
