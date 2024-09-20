#include <iostream>
#include <limits>

void ToBit(long a);

using namespace std;

struct StructDate
{
    unsigned int blue : 6;
    unsigned int : 4;
    unsigned int green : 5;
    unsigned int red : 3;
    unsigned int : 14;
};

union MyUnion
{
    long TotalWord;
    StructDate Birthday;
};

int main()
{
    long lVal;
    while (true) {
        cout << "Enter your Date of birth DDMMYYYY: ";
        cin >> lVal;

        // Check for input validity
        if (cin.fail() || lVal < 10000000 || lVal > 99999999) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a date in the format DDMMYYYY." << endl;
            continue;
        }

        // Validate the date
        if (!isValidDate(lVal)) {
            cout << "Invalid date. Please check the day and month." << endl;
            continue;
        }

        MyUnion UnionDate;
        UnionDate.TotalWord = lVal;

        cout << "blue means bits 0-5: " << UnionDate.Birthday.blue << endl;
        cout << "green means bits 10-14: " << UnionDate.Birthday.green << endl;
        cout << "red means bits 16-18: " << UnionDate.Birthday.red << endl;

        ToBit(lVal);
        break; // Exit the loop on valid input
    }
}

void ToBit(long a)
{
    static int i;
    i++;
    if (a > 1)
        ToBit(a / 2);
    if (i % 4 == 0)
        cout << " ";
    i--;
    cout << a % 2;
}

bool isValidDate(long date) {
    int day = date / 1000000;
    int month = (date / 10000) % 100;
    int year = date % 10000;

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    // Check for month-specific days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) return false;
        } else {
            if (day > 28) return false;
        }
    }
    return true;
}