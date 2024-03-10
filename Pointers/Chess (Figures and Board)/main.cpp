// Chessboard and pieces without class.
#include <iostream>
using namespace std;

typedef long LongType;

char *Creating_Chessboard();
void Creating_Pieces(char *Chessboard);

int main()
{
    char *Chessboard = Creating_Chessboard();
    Creating_Pieces(Chessboard);

    delete[] Chessboard;
    cout << "\nRemoved chessboard.";
    return 0;
}

char *Creating_Chessboard()
{
    char *Chessboard = new char[256];
    for (int j = 0; j < 256; j++)
    {
        Chessboard[j] = '0';
    }
    return Chessboard;
}

void Creating_Pieces(char *Chessboard)
{
    char Letter;
    LongType *Pieces[32];
    static int CountPieces = 0;
    long PositionNumber, Position;

    for (int j = 0; j < 32; j++)
    {
        Pieces[j] = nullptr;
    }

    while (true)
    {
        cout << "Enter the position to create a figure, for example F4, or press 'x' to display the positions of the figures (addresses): ";
        cin >> Letter;

        if (Letter == 'x')
        {
            break;
        }

        cin >> PositionNumber;

        if (Letter < 'A' || Letter > 'H' || PositionNumber < 1 || PositionNumber > 8)
        {
            cout << "Wrong position!" << endl;
            break;
        }

        Position = ((Letter - 'A') * 8 + PositionNumber - 1) * 4;

        cout << "Memory location: " << Position << endl;

        Pieces[CountPieces] = new (&Chessboard[Position]) LongType; // zbudowanie obiektu long na pozycji char, new placement
        *(Pieces[CountPieces]) = Position;                          // figura posiada dane o swojej pozycji
        CountPieces++;
    }

    cout << "Number of created pieces: " << CountPieces << ". Positions:";

    for (int j = 0; j < CountPieces; j++)
    {
        cout << *(Pieces[j]) << " ";
    }

    // usuwanie figur
    for (int j = 0; j < CountPieces; j++)
    {
        Pieces[j]->~LongType(); // Reczne wywolanie destruktora dla figur (zwolnienie miejsca na szachownicy) gdyz nie rezerwowano pamieci, a zbudowano obiekt na szachownicy
    }

    cout << "\nRemoved pieces.";
}
