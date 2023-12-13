//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const int ilepic = 12;
const int ilestronkart = ilepic * 2;
int ile_klik;
bool startgry = false;
AnsiString temp_nazwa;

struct pic
{
    TImage *pict;
    AnsiString nazwa_pict;
    pic() : pict(NULL), nazwa_pict(){};
};

pic tabpic[ilestronkart];

//---------------------------------------------------------------------------

void LosujKarty()
{
    AnsiString nazwa, sciezka_do_pliku;
    int x, licznik = 0;

    randomize();

    for (int i = 0; i < ilepic / 2; i++)
    {
        sciezka_do_pliku = "img/m" + IntToStr(i + 1) + ".bmp";

        while (licznik < 2)
        {
            x = random(ilepic);

            if (tabpic[x].pict->Picture->Graphic == NULL)
            {
                nazwa = "m" + IntToStr(x + 1);
                tabpic[x].pict = static_cast<TImage *>(Form1->FindComponent(nazwa));

                tabpic[x].pict->Picture->LoadFromFile(sciezka_do_pliku);
                tabpic[x].nazwa_pict = sciezka_do_pliku;

                licznik++;
            }
        }
        licznik = 0;
    }
}
//---------------------------------------------------------------------------
void ResetGry()
{
    sndPlaySound("snd/rain1.wav", SND_ASYNC | SND_LOOP | SND_NOSTOP);

    for (int i = 0; i < ilepic; i++)
    {
        tabpic[i].pict->Picture->Graphic = NULL;
    }

    ile_klik = 0;
    LosujKarty();
    startgry = true;
}
//---------------------------------------------------------------------------
void sprawdz(TObject *wskp)
{
    // Znalezienie odpowiedniej karty dla klikniêtej karty zakrytej
    pic *wskt;
    AnsiString index;
    TImage *obraz = dynamic_cast<TImage *>(wskp);
    index = obraz->Name;
    index = index.Delete(1, 1);
    wskt = &tabpic[(StrToInt(index)) - 1];

    if (startgry)
    {
        obraz->Visible = false;
        ile_klik++;
        if (ile_klik % 2)
        {
            sndPlaySound("snd/ok4.wav", SND_ASYNC);
            temp_nazwa = wskt->nazwa_pict;
        }
        else
        {
            if (wskt->nazwa_pict == temp_nazwa)
            {
                if (ile_klik == ilepic)
                {
                    sndPlaySound("snd/win2.wav", SND_ASYNC);
                    Form1->Rozpocznij->Caption = "Wygra³eœ! Zagraj ponownie";
                    startgry = false;
                }
                else
                {
                    sndPlaySound("snd/ok.wav", SND_ASYNC);
                    Form1->Rozpocznij->Caption = "Doskonale!";
                    Application->ProcessMessages();
                    Sleep(300);
                    Form1->Rozpocznij->Caption = "Zacznij od nowa";
                }
            }
            else
            {
                Form1->Rozpocznij->Caption = "Pud³o! Zagraj ponownie";
                sndPlaySound("snd/lose.wav", SND_ASYNC);
                startgry = false;
            }
        }
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    AnsiString nazwaobi;

    sndPlaySound("snd/rain1.wav", SND_ASYNC | SND_LOOP | SND_NOSTOP);

    for (int i = 0; i < ilepic; i++) // Inicjalizacja wskaŸników
    {
        nazwaobi = "m" + IntToStr(i + 1);
        tabpic[i].pict = static_cast<TImage *>(Form1->FindComponent(nazwaobi));
        tabpic[i].nazwa_pict = "";
        tabpic[i].pict->Enabled = false;
        tabpic[i].pict->Picture->Graphic = NULL;
    };

    for (int i = ilepic; i < ilestronkart; i++) // Przypisanie rewersu karty
    {
        nazwaobi = "b" + IntToStr((i % (ilepic)) + 1);
        tabpic[i].pict = static_cast<TImage *>(Form1->FindComponent(nazwaobi));
        tabpic[i].pict->Enabled = false;

        if (tabpic[i].pict != NULL)
        {
            tabpic[i].pict->Picture->LoadFromFile("img/b.bmp");
        }
    }

    WindowState = wsMaximized;
    tlo->Stretch = true;
    tlo->Width = ClientWidth;
    tlo->Height = ClientHeight;

    LosujKarty();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::bClick(TObject *Sender)
{
    sprawdz(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::RozpocznijClick(TObject *Sender)
{
    if ((startgry == false) && (ile_klik != 0))
    {
        ResetGry();
    }

    startgry = false;
    sndPlaySound("snd/start.wav", SND_ASYNC);
    for (int i = (ilepic); i < ilestronkart; i++)
    {
        tabpic[i].pict->Visible = false;
        tabpic[i].pict->Enabled = false;
    }

    Rozpocznij->Caption = "Zapamiêtaj";
    Application->ProcessMessages();
    Sleep(3000);
    Application->ProcessMessages();
    Sleep(1);
    if (startgry == true)
        ;
    for (int i = (ilepic); i < ilestronkart; i++)
    {
        tabpic[i].pict->Visible = true;
        tabpic[i].pict->Enabled = true;
    }
    startgry = true;
    Rozpocznij->Caption = "Zacznij od nowa";
};

//---------------------------------------------------------------------------

