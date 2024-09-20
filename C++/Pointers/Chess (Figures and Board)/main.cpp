#include <iostream>
using namespace std;

typedef long LongType;

const int ChessboardSize = 256;
const int NumPieces = 32;
const int Columns = 8;
const int Rows = 8;
const int CellSize = 4;

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
    char *Chessboard = new char[ChessboardSize];
    for (int j = 0; j < ChessboardSize; j++)
    {
        Chessboard[j] = '0';
    }
    return Chessboard;
}

void Creating_Pieces(char *Chessboard)
{
    char Letter;
    LongType *Pieces[NumPieces];
    static int CountPieces = 0;
    long PositionNumber, Position;

    for (int j = 0; j < NumPieces; j++)
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

        if (Letter < 'A' || Letter > 'H' || PositionNumber < 1 || PositionNumber > Rows)
        {
            cout << "Wrong position!" << endl;
            break;
        }

        Position = ((Letter - 'A') * Columns + PositionNumber - 1) * CellSize;

        cout << "Memory location: " << Position << endl;

        Pieces[CountPieces] = new (&Chessboard[Position]) LongType;
        *(Pieces[CountPieces]) = Position;
        CountPieces++;
    }

    cout << "Number of created pieces: " << CountPieces << ". Positions:";

    for (int j = 0; j < CountPieces; j++)
    {
        cout << *(Pieces[j]) << " ";
    }

    for (int j = 0; j < CountPieces; j++)
    {
        Pieces[j]->~LongType();
    }

    cout << "\nRemoved pieces.";
}
