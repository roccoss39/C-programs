#include <vcl.h>
#pragma hdrstop

// Variables to store the state of the grid and the current player
char f1, f2, f3, f4, f5, f6, f7, f8, f9, currentPlayer;
TImage *Fields[9];

#include "Unit1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

// Function to check if there is a winner
void checkWinner()
{
    if ((f1 == f2 && f2 == f3 && f1 != 'n') ||
        (f4 == f5 && f5 == f6 && f4 != 'n') ||
        (f7 == f8 && f8 == f9 && f7 != 'n') ||
        (f1 == f4 && f4 == f7 && f1 != 'n') ||
        (f2 == f5 && f5 == f8 && f2 != 'n') ||
        (f3 == f6 && f6 == f9 && f3 != 'n') ||
        (f1 == f5 && f5 == f9 && f1 != 'n') ||
        (f3 == f5 && f5 == f7 && f3 != 'n'))
    {
        char *message;
        if (currentPlayer == 'x')
            message = "Circle wins!";
        else
            message = "Cross wins!";

        Application->MessageBox(message, "Game Over", MB_OK);
    }
}

TForm1 *Form1;

// Constructor of the form
__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
}

// Form initialization and setting the initial state of the game
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Field1->Picture->LoadFromFile("img/empty.bmp");
    Field2->Picture->LoadFromFile("img/empty.bmp");
    Field3->Picture->LoadFromFile("img/empty.bmp");
    Field4->Picture->LoadFromFile("img/empty.bmp");
    Field5->Picture->LoadFromFile("img/empty.bmp");
    Field6->Picture->LoadFromFile("img/empty.bmp");
    Field7->Picture->LoadFromFile("img/empty.bmp");
    Field8->Picture->LoadFromFile("img/empty.bmp");
    Field9->Picture->LoadFromFile("img/empty.bmp");
    TurnImage->Picture->LoadFromFile("img/circle_small.bmp");

    // Initialize the grid with 'n' (empty) and set the current player to 'o'
    f1 = f2 = f3 = f4 = f5 = f6 = f7 = f8 = f9 = 'n';
    currentPlayer = 'o';

    Field1->Enabled = true;
    Field2->Enabled = true;
    Field3->Enabled = true;
    Field4->Enabled = true;
    Field5->Enabled = true;
    Field6->Enabled = true;
    Field7->Enabled = true;
    Field8->Enabled = true;
    Field9->Enabled = true;
}

// Event handler for Field1 click
void __fastcall TForm1::Field1Click(TObject *Sender)
{
    if (f1 == 'n')
    {
        if (currentPlayer == 'o')
        {
            Field1->Picture->LoadFromFile("img/circle.bmp");
            f1 = 'o';
            currentPlayer = 'x';
            TurnImage->Picture->LoadFromFile("img/cross_small.bmp");
        }
        else
        {
            Field1->Picture->LoadFromFile("img/cross.bmp");
            f1 = 'x';
            currentPlayer = 'o';
            TurnImage->Picture->LoadFromFile("img/circle_small.bmp");
        }
        Field1->Enabled = false;
        checkWinner();
    }
}

// Event handler for Field2 click
void __fastcall TForm1::Field2Click(TObject *Sender)
{
    if (f2 == 'n')
    {
        if (currentPlayer == 'o')
        {
            Field2->Picture->LoadFromFile("img/circle.bmp");
            f2 = 'o';
            currentPlayer = 'x';
            TurnImage->Picture->LoadFromFile("img/cross_small.bmp");
        }
        else
        {
            Field2->Picture->LoadFromFile("img/cross.bmp");
            f2 = 'x';
            currentPlayer = 'o';
            TurnImage->Picture->LoadFromFile("img/circle_small.bmp");
        }
        Field2->Enabled = false;
        checkWinner();
    }
}

// (Similarly translate other click event handlers for Field3 through Field9)
