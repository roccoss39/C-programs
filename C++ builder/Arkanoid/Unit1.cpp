//---------------------------------------------------------------------------
//Program napisany na podstawie bloga https://miroslawzelent.pl/

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

bool kolizja(TImage* pilka, TImage* cegla)
{
    if (pilka->Left >= cegla->Left && pilka->Left <= cegla->Left + cegla->Width &&
        pilka->Top >= cegla->Top - pilka->Height && pilka->Top <= cegla->Top + cegla->Height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int do_wygrania = 12;
int x = -8, y = -8;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::TimerpilkaTimer(TObject* Sender)
{
    b->Left += x;
    b->Top += y;

    // Odbicie lewej œciany
    if (b->Left - 5 <= tlo->Left)
    {
        x = -x;
    }

    // Odbicie góry
    if (b->Top - 5 <= tlo->Top)
    {
        y = -y;
    }

    // Odbicie prawej œciany
    if (b->Left + b->Width + 5 >= tlo->Width)
    {
        x = -x;
    }

    // Koniec gry - przegrana
    if (b->Top >= p->Top + p->Height + 15)
    {
        Timerpilka->Enabled = false;
        b->Visible = false;
        Button1->Caption = "Pora¿ka. Jeszcze raz?";
        Button1->Visible = true;
    }
    else if (b->Left > p->Left - b->Width / 2 && b->Left < p->Left + p->Width &&
             b->Top + b->Height > p->Top)
    {
        if (y > 0)
            y = -y;
    }

    // Sprawdzenie kolizji z ceg³ami
    if (do_wygrania > 0)
    {
        AnsiString nazwa;
        for (int i = 1; i <= 12; i++)
        {
            nazwa = "Image" + IntToStr(i);
            TImage* wskIm = static_cast<TImage*>(Form1->FindComponent(nazwa));
            if (kolizja(b, wskIm) && wskIm->Visible == true)
            {
                x = -x;
                y = -y;
                wskIm->Visible = false;
                do_wygrania--;
            }
        }
    }

    // Koniec gry - wygrana
    if (do_wygrania <= 0)
    {
        Timerpilka->Enabled = false;
        b->Visible = false;
        Button1->Caption = "Wygrana! Zagraj ponownie.";
        Button1->Visible = true;
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::lewoTimer(TObject* Sender)
{
    if (p->Left > 10)
        p->Left += -20;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::prawoTimer(TObject* Sender)
{
    if (p->Left + p->Width < tlo->Width - 10)
        p->Left += +20;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject* Sender, WORD& Key, TShiftState Shift)
{
    if (Key == VK_LEFT)
        lewo->Enabled = true;
    if (Key == VK_RIGHT)
        prawo->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject* Sender, WORD& Key, TShiftState Shift)
{
    if (Key == VK_LEFT)
        lewo->Enabled = false;
    if (Key == VK_RIGHT)
        prawo->Enabled = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject* Sender)
{
    b->Left = 50;
    b->Top = 50;
    b->Visible = true;
    x = -8;
    y = -8;
    Timerpilka->Enabled = true;
    Button1->Visible = false;
    do_wygrania = 12;

    AnsiString nazwa;
    for (int i = 1; i <= 12; i++)
    {
        nazwa = "Image" + IntToStr(i);
        TImage* wskIm = static_cast<TImage*>(Form1->FindComponent(nazwa));
        wskIm->Visible = true;
    }
}

//---------------------------------------------------------------------------


