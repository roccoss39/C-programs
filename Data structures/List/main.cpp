#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

list<int> MyList;
void Display_list();
void Menu();
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Menu();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void Display_list()
{
    for (auto it = MyList.begin(); it != MyList.end(); it++)
        cout << *it << " ";
    cout << endl;
    Sleep(3000);
}

void Menu()
{
    while (true)
    {
        int Choice;
        cout << " LIST MENU:" << endl
             << "---------------------------" << endl
             << "1.  push_front" << endl
             << "2.  push_back" << endl
             << "3.  pop_front" << endl
             << "4.  pop_back" << endl
             << "5.  size" << endl
             << "6.  max_size" << endl
             << "7.  empty" << endl
             << "8.  remove" << endl
             << "9.  sort" << endl
             << "10. reverse" << endl
             << "11. display numbers" << endl
             << "12. exit" << endl
             << "---------------------------" << endl
             << "Choose: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            int Val1;
            cin >> Val1;
            MyList.push_front(Val1);
            break;
        case 2:
            int Val2;
            cin >> Val2;
            MyList.push_back(Val2);
            break;
        case 3:
            MyList.pop_front();
            break;
        case 4:
            MyList.pop_back();
            break;
        case 5:
            cout << MyList.size();
            Sleep(1000);
            break;
        case 6:
            cout << MyList.max_size();
            Sleep(1000);
            break;
        case 7:
            cout << MyList.empty();
            Sleep(1000);
            break;
        case 8:
            int Val8;
            cin >> Val8;
            MyList.remove(Val8);
            break;
        case 9:
            MyList.sort();
            break;
        case 10:
            MyList.reverse();
            break;
        case 11:
            Display_list();
            break;
        case 12:
            exit(1);
            break;
        default:
            cout << "Fault";
            Sleep(1000);
            break;
        }
    }
}
