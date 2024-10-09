#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

// Closes the application when the button is clicked
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form1->Close();
}
