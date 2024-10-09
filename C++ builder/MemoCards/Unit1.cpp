#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

const int totalCards = 12;
const int totalCardSides = totalCards * 2;
int clicks = 0;
bool gameStarted = false;
AnsiString lastCardName;

struct Card
{
    TImage *image;
    AnsiString name;
    Card() : image(NULL), name() {}
};

Card cards[totalCardSides];

//---------------------------------------------------------------------------

void ShuffleCards()
{
    AnsiString cardName, filePath;
    int randomIndex, count = 0;

    randomize();

    for (int i = 0; i < totalCards / 2; i++)
    {
        filePath = "img/m" + IntToStr(i + 1) + ".bmp";

        while (count < 2)
        {
            randomIndex = random(totalCards);

            if (cards[randomIndex].image->Picture->Graphic == NULL)
            {
                cardName = "cardFront" + IntToStr(randomIndex + 1);
                cards[randomIndex].image = static_cast<TImage *>(Form1->FindComponent(cardName));
                cards[randomIndex].image->Picture->LoadFromFile(filePath);
                cards[randomIndex].name = filePath;
                count++;
            }
        }
        count = 0;
    }
}

//---------------------------------------------------------------------------

void ResetGame()
{
    sndPlaySound("snd/rain1.wav", SND_ASYNC | SND_LOOP | SND_NOSTOP);

    for (int i = 0; i < totalCards; i++)
    {
        cards[i].image->Picture->Graphic = NULL;
    }

    clicks = 0;
    ShuffleCards();
    gameStarted = true;
}

//---------------------------------------------------------------------------

void CheckCard(TObject *clickedObject)
{
    Card *selectedCard;
    AnsiString cardIndex;
    TImage *clickedImage = dynamic_cast<TImage *>(clickedObject);
    cardIndex = clickedImage->Name;
    cardIndex = cardIndex.Delete(1, 9);  // Remove "cardFront" from the name
    selectedCard = &cards[StrToInt(cardIndex) - 1];

    if (gameStarted)
    {
        clickedImage->Visible = false;
        clicks++;

        if (clicks % 2 == 1)
        {
            sndPlaySound("snd/ok4.wav", SND_ASYNC);
            lastCardName = selectedCard->name;
        }
        else
        {
            if (selectedCard->name == lastCardName)
            {
                if (clicks == totalCards)
                {
                    sndPlaySound("snd/win2.wav", SND_ASYNC);
                    Form1->startLabel->Caption = "You win! Play again?";
                    gameStarted = false;
                }
                else
                {
                    sndPlaySound("snd/ok.wav", SND_ASYNC);
                    Form1->startLabel->Caption = "Great!";
                    Application->ProcessMessages();
                    Sleep(300);
                    Form1->startLabel->Caption = "Start again";
                }
            }
            else
            {
                Form1->startLabel->Caption = "Miss! Try again";
                sndPlaySound("snd/lose.wav", SND_ASYNC);
                gameStarted = false;
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
    AnsiString cardName;

    sndPlaySound("snd/rain1.wav", SND_ASYNC | SND_LOOP | SND_NOSTOP);

    for (int i = 0; i < totalCards; i++) // Initialize pointers
    {
        cardName = "cardFront" + IntToStr(i + 1);
        cards[i].image = static_cast<TImage *>(Form1->FindComponent(cardName));
        cards[i].name = "";
        cards[i].image->Enabled = false;
        cards[i].image->Picture->Graphic = NULL;
    }

    for (int i = totalCards; i < totalCardSides; i++) // Assign card backs
    {
        cardName = "cardBack" + IntToStr((i % totalCards) + 1);
        cards[i].image = static_cast<TImage *>(Form1->FindComponent(cardName));
        cards[i].image->Enabled = false;

        if (cards[i].image != NULL)
        {
            cards[i].image->Picture->LoadFromFile("img/b.bmp");
        }
    }

    WindowState = wsMaximized;
    background->Stretch = true;
    background->Width = ClientWidth;
    background->Height = ClientHeight;

    ShuffleCards();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::cardClick(TObject *Sender)
{
    CheckCard(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::startLabelClick(TObject *Sender)
{
    if (!gameStarted && clicks != 0)
    {
        ResetGame();
    }

    gameStarted = false;
    sndPlaySound("snd/start.wav", SND_ASYNC);

    for (int i = totalCards; i < totalCardSides; i++)
    {
        cards[i].image->Visible = false;
        cards[i].image->Enabled = false;
    }

    startLabel->Caption = "Memorize";
    Application->ProcessMessages();
    Sleep(3000);
    Application->ProcessMessages();
    Sleep(1);

    for (int i = totalCards; i < totalCardSides; i++)
    {
        cards[i].image->Visible = true;
        cards[i].image->Enabled = true;
    }

    gameStarted = true;
    startLabel->Caption = "Start again";
}

