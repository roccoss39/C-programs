#include <iostream>
#include <time.h>
using namespace std;
void quicksort(int *tab,int od, int ile);

int main()
{
    srand(time(NULL));
    int r=200;
    int tablica[r];

    //Wczytywanie losowych liczb do tablicy
    for(int i=0; i<r; i++)
    {
        tablica[i] = rand()%r+1;
    }

    //Przed sortowaniem
    for (int i =0; i<r; i++)
    {
        cout<<tablica[i]<<" ";
    }

    cout<<endl<<endl<<"Po sortowaniu"<<endl;

    quicksort(tablica,0, r);

    //Po sortowaniu
    for (int i =0; i<r; i++)
    {
        cout<<tablica[i]<<" ";
    }
}

void quicksort(int *tab,int od, int ile)
{
    int  indexgorny=ile-1;
    int  indexdolny=od;
    int  bufor;
    const int os=tab[od]; //os czyli oœ podzia³u (po³owiczny)
    do
    {
        while((tab[indexgorny]>=(os))&&(!(indexdolny==indexgorny)))
        {
            indexgorny--;
        }
        bufor=tab[indexgorny];
        tab[indexgorny]=tab[indexdolny];
        tab[indexdolny]=bufor;

        while((tab[indexdolny]<=(os))&&(!(indexdolny==indexgorny)))
        {
            indexdolny++;
        }
        bufor=tab[indexgorny];
        tab[indexgorny]=tab[indexdolny];
        tab[indexdolny]=bufor;
    }
    while (!(indexdolny==indexgorny));

    if(indexdolny-od>=2)
        quicksort(tab,od,indexdolny);
    if(ile-indexgorny>=3)
        quicksort(tab,indexgorny+1,ile);
}

