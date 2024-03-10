#include <iostream>

using namespace std;

class Robot
{
public:
    bool Turn_right(double Value);
    bool Turn_left(double Value);
    bool Hoist_right_arm(double Value);
    bool Hoist_left_arm(double Value);
    bool Go_forward(double Value);
    bool Go_back(double Value);
    void Commit();
};
bool Turn_right(double Value)
{
    cout << "Turning right " << Value << " deg" << endl;
    return true;
}

bool Turn_left(double Value)
{
    cout << "Turning left " << Value << " deg" << endl;
    return true;
}

bool Hoist_right_arm(double Value)
{
    cout << "Hoisting right arm " << Value << " deg" << endl;
    return true;
}

bool Hoist_left_arm(double Value)
{
    cout << "Hoisting left arm " << Value << " deg" << endl;
    return true;
}

bool Go_forward(double Value)
{
    cout << "Going forward " << Value << "m" << endl;
    return true;
}

bool Go_back(double Value)
{
    cout << "Going back " << Value << "m" << endl;
    return true;
}
void Commit()
{
    int Choose, CountStep;
    double Array[20];
    bool (*ArrayPointer[20])(double);
    bool (*FunctionPointer[6])(double) = {&Turn_right, &Turn_left, &Hoist_right_arm, &Hoist_left_arm, &Go_forward, &Go_back};
    do
    {
        CountStep = 0;
        for (int i = 0; i < 20; i++)
        {
            cout << "Insert task: ";
            do
            {
                if (!(cin >> Choose))
                {
                    cout << "Invalid data! Try again." << endl;
                    cin.clear();
                    cin.ignore();
                }
            } while (cin.fail());

            if (Choose == 7)
                break;

            switch (Choose)
            {
            case 0:
            case 1:
            case 2:
            case 3:
                CountStep++;
                cout << "How many degree? ";
                cin >> Array[i];
                ArrayPointer[i] = (FunctionPointer[Choose]);
                break;
            case 4:
            case 5:
                CountStep++;
                cout << "How many meters? ";
                cin >> Array[i];
                ArrayPointer[i] = (FunctionPointer[Choose]);
                break;
            case 9:
                exit(1);
            default:
                cout << "Wrong data." << endl;
                i--;
                break;
            }
        }
        for (int i = 0; i < CountStep; i++)
        {
            (ArrayPointer[i])(Array[i]);
        }
        for (int i = 0; i < CountStep; i++)
        {
            (ArrayPointer[i]) = 0;
        }
    } while (Choose != 9);
}

void menu();

int main()
{
    menu();
    Commit();
}

void menu()
{
    cout << "############## DIALOGUE WINDOW ################\n"
         << "0: Turn right\n"
         << "1: Turn left\n"
         << "2: Hoist (move down) right arm\n"
         << "3: Hoist (move down) left arm\n"
         << "4: Go forward\n"
         << "5: Go back\n"
         << "7: Commit!\n"
         << "9: End\n";
}

