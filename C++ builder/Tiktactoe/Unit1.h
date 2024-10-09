#ifndef Unit1H
#define Unit1H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

class TForm1 : public TForm
{
__published:    // IDE-managed components
    TImage *Field1;
    TImage *Field2;
    TImage *Field3;
    TImage *Field4;
    TImage *Field5;
    TImage *Field6;
    TImage *Field7;
    TImage *Field8;
    TImage *Field9;
    TLabel *TurnLabel;
    TImage *TurnImage;
    TButton *ResetButton;

    // Event handlers for form creation and clicks on images
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Field1Click(TObject *Sender);
    void __fastcall Field2Click(TObject *Sender);
    void __fastcall Field3Click(TObject *Sender);
    void __fastcall Field4Click(TObject *Sender);
    void __fastcall Field5Click(TObject *Sender);
    void __fastcall Field6Click(TObject *Sender);
    void __fastcall Field7Click(TObject *Sender);
    void __fastcall Field8Click(TObject *Sender);
    void __fastcall Field9Click(TObject *Sender);

private:   
public:     
    __fastcall TForm1(TComponent *Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
