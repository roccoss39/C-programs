// Program napisany na podstawie bloga https://miroslawzelent.pl/
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

char kto;

struct pola
{
    char p;
    TImage* Pole;
};

pola tp[9];
bool wygrana = false;

void sprawdz()
{
    // Dla poziomów
    for (int i = 0, j = 0; j < 3; i += 3, j++)
    {
        if (tp[i].p == tp[i + 1].p && tp[i + 1].p == tp[i + 2].p && tp[i].p != 'n')
            wygrana = true;
    }

    // Dla pionów
    for (int i = 0; i < 3; i++)
    {
        if (tp[i].p == tp[i + 3].p && tp[i + 3].p == tp[i + 6].p && tp[i].p != 'n')
            wygrana = true;
    }

    // Dla skosów
    if ((tp[0].p == tp[4].p && tp[4].p == tp[8].p && tp[0].p != 'n') ||
        (tp[2].p == tp[4].p && tp[4].p == tp[6].p && tp[2].p != 'n'))
        wygrana = true;

    if (wygrana)
    {
        const char* t;
        if (kto == 'x')
            t = "Wygrywa kó³ko!";
        else
            t = "Wygrywa krzy¿yk!";

        Application->MessageBox(t, "Koniec gry", MB_OK);
    }
}

TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void wstaw_znak(pola &tablicapol)
{
    if (tablicapol.p == 'n' && wygrana == false)
    {
        if (kto == 'o')
        {
            tablicapol.Pole->Picture->LoadFromFile("img/o.bmp");
            tablicapol.p = 'o';
            kto = 'x';
            Form1->turaobraz->Picture->LoadFromFile("img/xsmall.bmp");
        }
        else
        {
            tablicapol.Pole->Picture->LoadFromFile("img/x.bmp");
            tablicapol.p = 'x';
            kto = 'o';
            Form1->turaobraz->Picture->LoadFromFile("img/osmall.bmp");
        }
        tablicapol.Pole->Enabled = false;
        sprawdz();
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    wygrana = false;

    tp[0].Pole = Pole1;
    tp[1].Pole = Pole2;
    tp[2].Pole = Pole3;
    tp[3].Pole = Pole4;
    tp[4].Pole = Pole5;
    tp[5].Pole = Pole6;
    tp[6].Pole = Pole7;
    tp[7].Pole = Pole8;
    tp[8].Pole = Pole9;

    for (int i = 0; i < 9; ++i)
    {
        tp[i].Pole->Picture->LoadFromFile("img/nic.bmp");
        tp[i].Pole->Enabled = true;
        tp[i].p = 'n';
    }

    turaobraz->Picture->LoadFromFile("img/osmall.bmp");
    kto = 'o';
}

//---------------------------------------------------------------------------
void __fastcall TForm1::PoleClick(TObject *Sender)
{
    TImage *clickedPole = dynamic_cast<TImage*>(Sender);

    for (int i = 0; i < 9; ++i)
    {
        if (clickedPole == tp[i].Pole)
        {
            wstaw_znak(tp[i]);
            break;
        }
    }
}

