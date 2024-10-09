#ifndef Unit1H
#define Unit1H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>

class TForm1 : public TForm
{
__published:    // IDE-managed Components
    TImage *cardFront1;
    TImage *cardFront2;
    TImage *cardFront3;
    TImage *cardFront4;
    TImage *cardBack1;
    TImage *cardBack2;
    TImage *cardBack3;
    TImage *cardBack4;
    TLabel *startLabel;
    TImage *background;
    TImage *cardFront5;
    TImage *cardFront6;
    TImage *cardBack5;
    TImage *cardBack6;
    TImage *cardBack7;
    TImage *cardBack8;
    TImage *cardBack9;
    TImage *cardBack10;
    TImage *cardBack11;
    TImage *cardBack12;
    TImage *cardFront11;
    TImage *cardFront12;
    TImage *cardFront10;
    TImage *cardFront9;
    TImage *cardFront8;
    TImage *cardFront7;

    void __fastcall FormCreate(TObject *Sender);
    void __fastcall startLabelClick(TObject *Sender);
    void __fastcall cardClick(TObject *Sender);

private:    // User declarations
public:     // User declarations
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
#endif
