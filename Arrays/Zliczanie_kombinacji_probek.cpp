//Zadanie z ksi¹zki Symfonia C++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int const rozmiar1=2,rozmiar2=2,rozmiar3=2,rozmiar4=2;
int tab[rozmiar1][rozmiar2][rozmiar3][rozmiar4];
void wypelnianie (int t[][2][2][2]);
void sklejtekst(char tab[], char skrot []);
void plusik(char t[]);
void czyszczenie(char tab[]);
void pokaz(int tab[]);
int const zakres=10000;
int wyniki[zakres];

int main()
{

srand(static_cast<unsigned int>(time(0)));
int random_number =rand() % 2;

wypelnianie (tab);
pokaz((wyniki));
}

void wypelnianie (int t[][rozmiar2][rozmiar3][rozmiar4])
{
char tab[30]={""},DGF[]=" DGF +",HEC[]=" HEC +",GER[]=" GER +", FRS[]=" FRS +"; //Ka¿da nazwa odpowiada innemu zapalonemu bitowi, brak nazwy to brak zapalonych bitow
for(int x=0,j,m,n,i;x<zakres;x++)
	{	i=rand() % 2;
		j=rand() % 2;
		n=rand() % 2;
		m=rand() % 2;
		
		t[i][j][n][m]=i*2*2*2+j*2*2+n*2+m;
		cout<<i<<" "<<j<<" "<<n<<" "<<m<<"  "<<t[i][j][n][m];
		wyniki[x]=t[i][j][n][m];

				if ((t[i][j][n][m]>>0)&1)
				sklejtekst(tab, FRS);
				if ((t[i][j][n][m]>>1)&1)
				sklejtekst(tab, GER);
				if (((t[i][j][n][m]>>2)&1))
				sklejtekst(tab, HEC);
				if (((t[i][j][n][m]>>3)&1))
				sklejtekst(tab, DGF);

				plusik(tab);
				cout<<tab;
				cout<<endl;
				czyszczenie(tab);
	}	
}

void sklejtekst(char tab[], char skrot [])
{int i=0;
	for(i;i<30;i++)
	{
		if (tab[i]==0)
		{
		break;
		}
	}	
		for(int j=0;;i++,j++)	
		{
		tab[i]=skrot[j];
		if(skrot[j]==0)
		break;
		}
}
void czyszczenie(char tab[])
{
	for(int i=0;i<30;i++)
	{
		tab[i]=0;
	}
}
void plusik(char t[])
{
	for(int i=0;i<30;i++)
	{
	if(t[i]==0)
	{
		if (t[i-1]=='+')
		(t[i-1]=0);
	}
	}
}
void pokaz(int tab[])
{cout<<endl;
char tabi[30]={" "},DGF[]=" DGF +",HEC[]=" HEC +",GER[]=" GER +", FRS[]=" FRS +";
int a;
for(int x=0; x<zakres-1;x++)
{

	for (int y=0;y<zakres;y++)
		{
			if ((((tab[y]>>0)&1) + ((tab[y]>>1)&1) + ((tab[y]>>2)&1)+(((tab[y]>>3)&1)) > ((tab[y+1]>>0)&1)+((tab[y+1]>>1)&1) + ((tab[y+1]>>2)&1) + ((tab[y+1]>>3)&1)))
			{
				a=tab[y+1];
				tab[y+1]=tab[y];
				tab[y]=a;
			}
		}
}
	for (int i=0;i<zakres;i++)
	{ 
		for (int j=0;j<=i;j++)
		{
			if((tab[i])==tab[j]&&(i!=0))
			{
				break;
			}
			if ((j==i-1) || (i==0))
			{
			static int c,suma;
			c=tab[i];
			suma=0;
			czyszczenie(tabi);
				if ((tab[i]>>0)&1)
				sklejtekst(tabi, FRS);
				if ((tab[i]>>1)&1)
				sklejtekst(tabi, GER);
				if ((tab[i]>>2)&1)
				sklejtekst(tabi, HEC);
				if ((tab[i]>>3)&1)
				sklejtekst(tabi, DGF);
				plusik(tabi);
				cout<<"KOMBINACJA:"<<tabi<<" ->";

				
			for (int i=0;i<zakres;i++)
			{
				if(c==tab[i])
				suma++;
			}
			cout<<" "<<suma<<" RAZY"<<endl;
			}
		}	
	}
}
