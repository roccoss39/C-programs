//---------------------------------------------------------------------------
// Game based on a tutorial from https://miroslawzelent.pl/

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

// Constants
const int INITIAL_BALL_SPEED_X = -8;
const int INITIAL_BALL_SPEED_Y = -8;
const int WIN_CONDITION_BRICKS = 12;
const int PADDLE_MOVE_SPEED = 20;
const int BALL_PADDING = 5;
const int BALL_LOSS_MARGIN = 15;

// Function to detect collision between the ball and a brick
bool isCollision(TImage *ball, TImage *brick)
{
    return (ball->Left >= brick->Left && ball->Left <= brick->Left + brick->Width &&
            ball->Top >= brick->Top - ball->Height && ball->Top <= brick->Top + brick->Height);
}

int bricksRemaining = WIN_CONDITION_BRICKS;
int ballSpeedX = INITIAL_BALL_SPEED_X;
int ballSpeedY = INITIAL_BALL_SPEED_Y;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
    b->Left += ballSpeedX;
    b->Top += ballSpeedY;

    // Left wall reflection
    if (b->Left - BALL_PADDING <= tlo->Left)
    {
        ballSpeedX = -ballSpeedX;
    }

    // Upper wall reflection
    if (b->Top - BALL_PADDING <= tlo->Top)
    {
        ballSpeedY = -ballSpeedY;
    }

    // Right wall reflection
    if (b->Left + b->Width + BALL_PADDING >= tlo->Width)
    {
        ballSpeedX = -ballSpeedX;
    }

    // Check if ball falls below paddle (Game over)
    if (b->Top >= p->Top + p->Height + BALL_LOSS_MARGIN)
    {
        TimerBall->Enabled = false;
        b->Visible = false;
        Button1->Caption = "Game over. Play again?";
        Button1->Visible = true;
    }
    // Paddle collision
    else if (b->Left > p->Left - b->Width / 2 && b->Left < p->Left + p->Width &&
             b->Top + b->Height > p->Top)
    {
        if (ballSpeedY > 0)
            ballSpeedY = -ballSpeedY;
    }

    // Check for brick collisions
    if (bricksRemaining > 0)
    {
        for (int i = 1; i <= WIN_CONDITION_BRICKS; i++)
        {
            AnsiString brickName = "Image" + IntToStr(i);
            TImage *brick = static_cast<TImage *>(Form1->FindComponent(brickName));
            if (isCollision(b, brick) && brick->Visible == true)
            {
                ballSpeedX = -ballSpeedX;
                ballSpeedY = -ballSpeedY;
                brick->Visible = false;
                bricksRemaining--;
            }
        }
    }

    // Check for win condition
    if (bricksRemaining <= 0)
    {
        TimerBall->Enabled = false;
        b->Visible = false;
        Button1->Caption = "Win! Play again.";
        Button1->Visible = true;
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::MovePaddleLeftTimer(TObject *Sender)
{
    if (p->Left > PADDLE_MOVE_SPEED)
        p->Left -= PADDLE_MOVE_SPEED;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::MovePaddleRightTimer(TObject *Sender)
{
    if (p->Left + p->Width < tlo->Width - PADDLE_MOVE_SPEED)
        p->Left += PADDLE_MOVE_SPEED;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Key == VK_LEFT)
        MovePaddleLeft->Enabled = true;
    if (Key == VK_RIGHT)
        MovePaddleRight->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Key == VK_LEFT)
        MovePaddleLeft->Enabled = false;
    if (Key == VK_RIGHT)
        MovePaddleRight->Enabled = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    b->Left = 50;
    b->Top = 50;
    b->Visible = true;
    ballSpeedX = INITIAL_BALL_SPEED_X;
    ballSpeedY = INITIAL_BALL_SPEED_Y;
    TimerBall->Enabled = true;
    Button1->Visible = false;
    bricksRemaining = WIN_CONDITION_BRICKS;

    // Reset all bricks to visible
    for (int i = 1; i <= WIN_CONDITION_BRICKS; i++)
    {
        AnsiString brickName = "Image" + IntToStr(i);
        TImage *brick = static_cast<TImage *>(Form1->FindComponent(brickName));
        brick->Visible = true;
    }
}

//---------------------------------------------------------------------------
