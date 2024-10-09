#ifndef Unit1H
#define Unit1H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>

class TForm1 : public TForm
{
__published:    // IDE-managed components
    TButton *Button1;
    TImage *Image1;

    // Handles button click event
    void __fastcall Button1Click(TObject *Sender);

private:    

public:     
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
