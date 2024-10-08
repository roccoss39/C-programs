//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *m1;
        TImage *m3;
        TImage *m2;
        TImage *m4;
        TImage *b1;
        TImage *b2;
        TImage *b3;
        TImage *b4;
        TLabel *Rozpocznij;
        TImage *tlo;
        TImage *m5;
        TImage *m6;
        TImage *b5;
        TImage *b6;
        TImage *b7;
        TImage *b8;
        TImage *b9;
        TImage *b10;
        TImage *b11;
        TImage *b12;
        TImage *m11;
        TImage *m12;
        TImage *m10;
        TImage *m9;
        TImage *m8;
        TImage *m7;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall RozpocznijClick(TObject *Sender);

        void __fastcall bClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
