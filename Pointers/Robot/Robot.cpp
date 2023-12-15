#include <iostream>

using namespace std;

bool obrot_prawo(double ile);
bool obrot_lewo(double ile);
bool podnies_prawe_ramie(double ile);
bool podnies_lewe_ramie(double ile);
bool idz_przod(double ile);
bool idz_tyl(double ile);
void menu();
void akcja();

int main()
{
    menu();
    akcja();
}

bool obrot_prawo(double ile)
{
    cout << "obracam sie w prawo o " <<ile<<" deg"<< endl;
    return true;
}

bool obrot_lewo(double ile)
{
    cout << "obracam sie w lewo o " <<ile<<" deg"<< endl;
    return true;
}

bool podnies_prawe_ramie(double ile)
{
    cout << "podnosze prawe ramie o " <<ile<<" deg"<< endl;
    return true;
}

bool podnies_lewe_ramie(double ile)
{
    cout << "podnosze lewe ramie o " <<ile<<" deg"<< endl;
    return true;
}

bool idz_przod(double ile)
{
    cout << "ide w przod o " <<ile<<"m"<< endl;
    return true;
}

bool idz_tyl(double ile)
{
    cout << "ide w tyl o " <<ile<<"m"<< endl;
    return true;
}

void menu()
{
    cout << "############## OKNO DIALOGOWE ################\n"
         << "0: obrot w prawo\n"
         << "1: obrot w lewo\n"
         << "2: podnies (opusc) prawe ramie\n"
         << "3: podnies (opusc) leweramie\n"
         << "4: idz w przod\n"
         << "5: idz w tyl\n"
         << "7: wykonaj\n"
         << "9: koniec\n";
}

void akcja()
{
    int a, n;
    double t[20];
    bool (*wsk[20])(double);
    bool (*tabw[6])(double) = {&obrot_prawo, &obrot_lewo, &podnies_prawe_ramie, &podnies_lewe_ramie, &idz_przod, &idz_tyl};
    do
    {
        n = 0;
        for (int i = 0; i < 20; i++)
        {
            cout << "Wprowadz polecenie: ";
            do{
            	if (!(cin >> a)) 
				{
              	    cout << "Niepoprawne dane! Sprobuj ponownie." << endl;
                	cin.clear(); 
                	cin.ignore(); 
            	}
           	}while(cin.fail());

            if (a == 7)
                break;

            switch (a)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            	n++;
                cout<<"o ile stopni? ";
                cin>>t[i];
                wsk[i] = (tabw[a]);
                break;
            case 4:
            case 5:
                n++;
                cout<<"o ile metrow? ";
                cin>>t[i];
                wsk[i] = (tabw[a]);
                break;
            case 9:
                exit(1);
            default:
                cout << "zle podales znak" << endl;
                i--;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            (wsk[i])(t[i] );
        }
        for (int i = 0; i < n; i++)
        {
            (wsk[i]) = 0;
        }
    } while (a != 9);
}

