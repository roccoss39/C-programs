object Form1: TForm1
  Left = 192
  Top = 125
  Width = 870
  Height = 450
  Caption = 'Tic Tac Toe v 1.0'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Pole1: TImage
    Left = 32
    Top = 24
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole2: TImage
    Left = 128
    Top = 24
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole3: TImage
    Left = 224
    Top = 24
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole4: TImage
    Left = 32
    Top = 120
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole5: TImage
    Left = 128
    Top = 120
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole6: TImage
    Left = 224
    Top = 120
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole7: TImage
    Left = 32
    Top = 216
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole8: TImage
    Left = 128
    Top = 216
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Pole9: TImage
    Left = 224
    Top = 216
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = PoleClick
  end
  object Tura: TLabel
    Left = 400
    Top = 120
    Width = 173
    Height = 37
    Caption = 'Tura gracza'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object turaobraz: TImage
    Left = 584
    Top = 128
    Width = 30
    Height = 30
  end
  object Button1: TButton
    Left = 416
    Top = 184
    Width = 153
    Height = 49
    Cursor = crHandPoint
    Caption = 'Od nowa'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = FormCreate
  end
end
