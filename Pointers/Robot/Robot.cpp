#include <iostream>

using namespace std;

#include "Robot.h"

bool Robot::Turn_right(double Value)
{
    cout << "Turning right " << Value << "deg" << endl;
    return true;
}

bool Robot::Turn_left(double Value)
{
    cout << "Turning left " << Value << "deg" << endl;
    return true;
}

bool Robot::Hoist_right_arm(double Value)
{
    cout << "Hoisting right arm " << Value << "deg" << endl;
    return true;
}

bool Robot::Hoist_left_arm(double Value)
{
    cout << "Hoisting left arm " << Value << "deg" << endl;
    return true;
}

bool Robot::Go_forward(double Value)
{
    cout << "Going forward " << Value << "m" << endl;
    return true;
}

bool Robot::Go_back(double Value)
{
    cout << "Going back " << Value << "m" << endl;
    return true;
}
void Robot::Commit()
{
    int Choose, CountStep;
    double Array[20];
    bool (Robot::*ArrayPointer[20])(double) = {nullptr};
    bool (Robot::*FunctionPointer[6])(double) = {&Robot::Turn_right, &Robot::Turn_left, &Robot::Hoist_right_arm, &Robot::Hoist_left_arm, &Robot::Go_forward, &Robot::Go_back};
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
                ArrayPointer[i] = FunctionPointer[Choose];
                break;
            case 4:
            case 5:
                CountStep++;
                cout << "How many meters? ";
                cin >> Array[i];
                ArrayPointer[i] = FunctionPointer[Choose];
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
            (this->*ArrayPointer[i])(Array[i]);
        }
        for (int i = 0; i < CountStep; i++)
        {
            (ArrayPointer[i]) = nullptr;
        }
    } while (Choose != 9);
}

void menu();

int main()
{
    Robot robot;
    menu();
    robot.Commit();
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
