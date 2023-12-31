//---------------------------------------------------------------------------
// Program napisany na podstawie bloga https://miroslawzelent.pl/

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "MojNotatnikUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
AnsiString nazwapliku = "";

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Otwrz1Click(TObject *Sender)
{
    if (OpenDialog1->Execute());
    try
    {
        tresc->Lines->LoadFromFile(OpenDialog1->FileName);
        nazwapliku = OpenDialog1->FileName;
    }
    catch (...)
    {
        ShowMessage("Odczyt zako�czy� si� niepowodzeniem.");
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Zapizjako1Click(TObject *Sender)
{
    if (SaveDialog1->Execute());
    try
    {
        tresc->Lines->SaveToFile(SaveDialog1->FileName);
        nazwapliku = SaveDialog1->FileName;
    }
    catch (...)
    {
        ShowMessage("Zapis zako�czy� si� niepowodzeniem.");
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Zapisz1Click(TObject *Sender)
{
    if (nazwapliku != "")
    {
        tresc->Lines->SaveToFile(nazwapliku);
    }
    else
    {
        Form2->Zapizjako1Click(MainMenu1);
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Nowy1Click(TObject *Sender)
{
    if (Application->MessageBox(
        "Czy na pewno chcesz utworzy� nowy plik?", "Potwierd�",
        MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
    {
        tresc->Lines->Clear();
        nazwapliku = "";
        // Application->MessageBox("Utworzono");
        // ShowMessage("Nowy plik zosta� utworzony.");
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::trescKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Shift.Contains(ssCtrl))
    {
        if ((Key == 's' || Key == 'S'))
            Form2->Zapisz1Click(MainMenu1);
    }
    if (Shift.Contains(ssCtrl))
    {
        if ((Key == 'n' || Key == 'N'))
            Form2->Nowy1Click(MainMenu1);
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Zakocz1Click(TObject *Sender)
{
    if (Application->MessageBox(
        "Czy na pewno chcesz zamkn�� program?", "Potwierd�",
        MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        Application->Terminate();
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (Application->MessageBox(
        "Czy na pewno chcesz zamkn�� program?", "Potwierd�",
        MB_YESNO | MB_ICONQUESTION) == IDNO)
    {
        Action = caNone;
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::WyttnijCtrlx1Click(TObject *Sender)
{
    tresc->CutToClipboard();
}

//---------------------------------------------------------------------------

void __fastcall TForm2::KopiujCtrlC1Click(TObject *Sender)
{
    tresc->CopyToClipboard();
}

//---------------------------------------------------------------------------

void __fastcall TForm2::WklejCtrlV1Click(TObject *Sender)
{
    tresc->PasteFromClipboard();
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Zawijaniewierszy1Click(TObject *Sender)
{
    if (Zawijaniewierszy1->Checked == true)
    {
        Zawijaniewierszy1->Checked = false;
        tresc->WordWrap = false;
        tresc->ScrollBars = ssBoth;
    }
    else
    {
        Zawijaniewierszy1->Checked = true;
        tresc->WordWrap = true;
        tresc->ScrollBars = ssVertical;
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Czcionka1Click(TObject *Sender)
{
    if (FontDialog1->Execute())
    {
        tresc->Font->Name = FontDialog1->Font->Name;
        tresc->Font->Color = FontDialog1->Font->Color;
        tresc->Font->Size = FontDialog1->Font->Size;
        tresc->Font->Style = FontDialog1->Font->Style;
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Oprogramie1Click(TObject *Sender)
{
    Form1->Visible = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Zapraszamnabloga1Click(TObject *Sender)
{
    ShellExecute(NULL, "open", "https://miroslawzelent.pl/", NULL, NULL, SW_SHOWNORMAL);
}

//---------------------------------------------------------------------------


